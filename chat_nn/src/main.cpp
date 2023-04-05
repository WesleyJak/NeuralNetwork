void NeuralNetwork::train(const std::vector<std::vector<double>>& input, const std::vector<std::vector<double>>& target, int epochs, double learningRate, std::string filename) {
    for (int i = 0; i < epochs; i++) {
        for (int j = 0; j < input.size(); j++) {
            forward(input[j]);
            backpropagate(target[j], learningRate);
        }
    }

    saveToFile(filename);
}

void NeuralNetwork::saveToFile(std::string filename) const {
    std::ofstream outFile(filename, std::ios::binary);
    if (!outFile.is_open()) {
        throw std::runtime_error("Could not open file for writing: " + filename);
    }

    // Write the number of layers to the file
    int numLayers = layers_.size();
    outFile.write(reinterpret_cast<char*>(&numLayers), sizeof(numLayers));

    // Write each layer to the file
    for (const auto& layer : layers_) {
        layer.saveToFile(outFile);
    }

    outFile.close();
}

NeuralNetwork loadFromFile(std::string filename) {
    std::ifstream inFile(filename, std::ios::binary);
    if (!inFile.is_open()) {
        throw std::runtime_error("Could not open file for reading: " + filename);
    }

    // Read the number of layers from the file
    int numLayers;
    inFile.read(reinterpret_cast<char*>(&numLayers), sizeof(numLayers));

    // Create a new NeuralNetwork object with the correct number of layers
    NeuralNetwork nn;
    for (int i = 0; i < numLayers; i++) {
        nn.addLayer(Layer::loadFromFile(inFile));
    }

    inFile.close();
    return nn;
}

int main() {
    // Load the trained neural network from a file
    NeuralNetwork nn = loadFromFile("trained_network.bin");

    // Load the test data from a file
    std::vector<std::vector<double>> testData = parseEMNISTData("test_images.csv");

    // Run the test data through the network and print out the results
    for (const auto& input : testData) {
        auto output = nn.forward(input);
        int prediction = std::distance(output.begin(), std::max_element(output.begin(), output.end()));
        std::cout << "Prediction: " << prediction << std::endl;
    }

    return 0;
}
void parseEMNISTData(std::string filename, NeuralNetwork& network, int numExamples) {
    // open the file
    std::ifstream file(filename, std::ios::binary);
    if (!file.is_open()) {
        std::cerr << "Error: Unable to open file " << filename << std::endl;
        return;
    }

    // read the header information
    int magicNumber, numImages, numRows, numCols;
    file.read((char*)&magicNumber, sizeof(magicNumber));
    file.read((char*)&numImages, sizeof(numImages));
    file.read((char*)&numRows, sizeof(numRows));
    file.read((char*)&numCols, sizeof(numCols));

    // check that the data is valid
    if (magicNumber != 2051) {
        std::cerr << "Error: Invalid magic number in file " << filename << std::endl;
        file.close();
        return;
    }

    // allocate memory for the image and label data
    unsigned char* imageData = new unsigned char[numRows * numCols];
    unsigned char labelData;

    // loop through the images and labels
    for (int i = 0; i < numExamples && file.good(); i++) {
        // read the image and label data
        file.read((char*)imageData, numRows * numCols);
        file.read((char*)&labelData, sizeof(labelData));

        // convert the image data to a double array and normalize it
        double* input = new double[numRows * numCols];
        for (int j = 0; j < numRows * numCols; j++) {
            input[j] = imageData[j] / 255.0;
        }

        // create the target output array and set the correct index to 1
        double* target = new double[26];
        for (int j = 0; j < 26; j++) {
            target[j] = 0.0;
        }
        target[labelData - 97] = 1.0; // ASCII code for 'a' is 97

        // train the network with the input and target data
        network.train(input, target);

        // free memory
        delete[] input;
        delete[] target;
    }

    // free memory and close the file
    delete[] imageData;
    file.close();
}
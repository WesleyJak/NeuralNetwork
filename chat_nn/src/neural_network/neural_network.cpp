class NeuralNetwork {
public:
    NeuralNetwork(std::vector<int> layerSizes, double learningRate) {
        layerSizes_ = layerSizes;
        learningRate_ = learningRate;
        for (int i = 1; i < layerSizes.size(); i++) {
            Layer layer(layerSizes[i-1], layerSizes[i]);
            layers_.push_back(layer);
        }
    }

    ~NeuralNetwork() {
        layers_.clear();
    }

    double* forward(double* input) {
        double* output = input;
        for (int i = 0; i < layers_.size(); i++) {
            layers_[i].setLastInput(output);
            output = layers_[i].forward(output);
        }
        return output;
    }

        void backpropagate(double* input, double* target) {
        // forward pass
        double* output = forward(input);

        // calculate delta for output layer
        double* delta = new double[layerSizes_[layerSizes_.size()-1]];
        for (int j = 0; j < layerSizes_[layerSizes_.size()-1]; j++) {
            delta[j] = output[j] - target[j];
        }

        // update weights for output layer
        layers_[layers_.size()-1].updateWeights(delta, learningRate_);

        // calculate delta and update weights for hidden layers
        for (int i = layers_.size()-2; i >= 0; i--) {
            delta = new double[layerSizes_[i+1]];
            double* nextDelta = new double[layerSizes_[i+2]];
            for (int j = 0; j < layerSizes_[i+1]; j++) {
                double sum = 0.0;
                for (int k = 0; k < layerSizes_[i+2]; k++) {
                    sum += layers_[i+1].getWeight(j, k) * nextDelta[k];
                }
                delta[j] = sum * sigmoidDerivative(layers_[i].getOutput(j));
            }
            layers_[i].updateWeights(delta, learningRate_);
            delete[] nextDelta;
            nextDelta = delta;
        }
        delete[] delta;
        delete[] output;
    }

private:
    std::vector<int> layerSizes_;
    double learningRate_;
    std::vector<Layer> layers_;

    double sigmoid(double x) {
        return 1.0 / (1.0 + exp(-x));
    }

    double sigmoidDerivative(double x) {
        return x * (1.0 - x);
    }
};
#include "fill_array.h"

class Layer {
public:
    Layer(int inputSize, int outputSize) {
        inputSize_ = inputSize;
        outputSize_ = outputSize;
        weights_ = new double*[inputSize];
        for (int i = 0; i < inputSize; i++) {
            weights_[i] = new double[outputSize];
            fillArrayWithRandomNumbers(weights_[i], outputSize);
        }
        bias_ = new double[outputSize];
        fillArrayWithRandomNumbers(bias_, outputSize);
    }

    ~Layer() {
        for (int i = 0; i < inputSize_; i++) {
            delete[] weights_[i];
        }
        delete[] weights_;
        delete[] bias_;
    }

    double* forward(double* input) {
        double* output = new double[outputSize_];
        for (int j = 0; j < outputSize_; j++) {
            double sum = bias_[j];
            for (int i = 0; i < inputSize_; i++) {
                sum += input[i] * weights_[i][j];
            }
            output[j] = sum;
        }
        return output;
    }

    void updateWeights(double* delta, double learningRate) {
        for (int j = 0; j < outputSize_; j++) {
            bias_[j] -= learningRate * delta[j];
            for (int i = 0; i < inputSize_; i++) {
                weights_[i][j] -= learningRate * delta[j] * lastInput_[i];
            }
        }
    }

    void setLastInput(double* input) {
        lastInput_ = input;
    }

private:
    int inputSize_;
    int outputSize_;
    double** weights_;
    double* bias_;
    double* lastInput_;
};
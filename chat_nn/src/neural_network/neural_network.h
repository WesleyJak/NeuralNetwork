#ifndef NEURALNETWORK_H
#define NEURALNETWORK_H

#include "layer.h"

class NeuralNetwork {
public:
    NeuralNetwork(int inputSize, int outputSize, int numHiddenLayers, int neuronsPerLayer);
    ~NeuralNetwork();
    
    void forwardPass(float* input);
    void backPropagate(float* targetOutput, float learningRate);
    void updateWeights();
    float calculateError(float* targetOutput);
    
    void saveNetwork(std::string filename);
    void loadNetwork(std::string filename);
    
private:
    int m_inputSize;
    int m_outputSize;
    int m_numHiddenLayers;
    int m_neuronsPerLayer;
    Layer** m_layers;
    float* m_output;
};

#endif

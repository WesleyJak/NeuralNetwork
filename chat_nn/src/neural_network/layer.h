#ifndef LAYER_H
#define LAYER_H

#include <vector>

class Layer {
public:
    Layer(int input_size, int output_size);
    std::vector<double> forward(std::vector<double> input);
    std::vector<double> backward(std::vector<double> grad_output);
    void update_weights(double learning_rate);

private:
    std::vector<double> weights;
    std::vector<double> biases;
    std::vector<double> input;
    std::vector<double> output;
    int input_size;
    int output_size;

    void fill_array_with_random_numbers(double* arr, int size);
};

#endif /* LAYER_H */

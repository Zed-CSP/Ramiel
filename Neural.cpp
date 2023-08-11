#include <vector>
#include <cmath>
#include <cstdlib> // for rand()

class Neuron {
public:
    double value;
    std::vector<double> weights;
    double bias;
    
    Neuron(int prevLayerSize) {
        for (int i = 0; i < prevLayerSize; i++) {
            weights.push_back(((double) rand() / (RAND_MAX)) * 2.0 - 1.0); // Random value between -1 and 1
        }
        bias = ((double) rand() / (RAND_MAX)) * 2.0 - 1.0;
    }
};

class Layer {
public:
    std::vector<Neuron> neurons;
    
    Layer(int size, int prevLayerSize) {
        for (int i = 0; i < size; i++) {
            neurons.push_back(Neuron(prevLayerSize));
        }
    }
};

class NeuralNetwork {
private:
    std::vector<Layer> layers;

    double sigmoid(double x) {
        return 1.0 / (1.0 + std::exp(-x));
    }

public:
    NeuralNetwork(std::vector<int> topology) {
        for (size_t i = 0; i < topology.size(); i++) {
            int prevSize = i == 0 ? 0 : topology[i - 1];
            layers.push_back(Layer(topology[i], prevSize));
        }
    }

    std::vector<double> feedForward(const std::vector<double>& input) {
        for (size_t i = 0; i < input.size(); i++) {
            layers[0].neurons[i].value = input[i];
        }

        for (size_t i = 1; i < layers.size(); i++) {
            for (Neuron& neuron : layers[i].neurons) {
                double sum = 0.0;
                for (const Neuron& prevNeuron : layers[i - 1].neurons) {
                    sum += prevNeuron.value * neuron.weights[i];
                }
                sum += neuron.bias;
                neuron.value = sigmoid(sum);
            }
        }

        std::vector<double> output;
        for (const Neuron& neuron : layers.back().neurons) {
            output.push_back(neuron.value);
        }
        return output;
    }
};

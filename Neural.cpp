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

#ifndef LAYER_H
#define LAYER_H

#include <vector>
#include <memory>
#include <ctime>

#include "constants.h"
//#include "Activ.h"
#include "../Nodes/activatorsfactory.h"
#include "../Nodes/node.h"

class Layer
{
public:
    Layer(int neuronCount, ActivationFunctions fn, int dropout_ = 0);
    virtual ~Layer(){}

    Layer (const Layer&) = delete;
    Layer& operator= (const Layer&) = delete;

protected:
    int neurons;
    int droupoutRate;
    ActivationFunctions activator;
    ConnectionType connections_t;
    std::vector<std::unique_ptr<Node> > nodeLayer;

};

#endif // LAYER_H

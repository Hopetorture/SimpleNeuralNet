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

    int size(){return nodeLayer.size();}
    std::shared_ptr<Node>/*&*/ at(int i){ return nodeLayer.at(i);}
    std::shared_ptr<Node>/*&*/ operator[](int i){return nodeLayer.at(i);}
    NodeVec getNodeVec(){return nodeLayer;}
    std::shared_ptr<Node> back(){return nodeLayer.back();}
    virtual void debug() = 0;

protected:
    int neurons;
    int droupoutRate;
    ActivationFunctions activator;
    ConnectionType connections_t;
    std::vector<std::shared_ptr<Node> > nodeLayer;
    std::string description = "default";

};

#endif // LAYER_H

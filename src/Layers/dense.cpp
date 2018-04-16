#include "dense.h"
#include "../Nodes/simplenode.h"

Dense::Dense(int neuronCount, ActivationFunctions fn, int dropout_)
    : Layer(neuronCount, fn, dropout_)
{
    for (int i = 0; i < neurons; i++){
        Node* node = new SimpleNode();    //UB place, hope for no exceptions
        auto node_ptr = std::unique_ptr<Node>(node);
        std::srand(unsigned(std::time(nullptr))); // todo - fix later
        fp rnd = ((fp)std::rand()/ (RAND_MAX) );
        if (rnd > 1 || rnd < 0){std::cout << "Error in random generation in DenseLayer!" << std::endl;}
        std::cout << rnd << std::endl;;
        auto activ = ActivatorsFactory::getActivator(ActivationFunctions::Sigmoid);
        node_ptr->setParams(rnd, activ);
        //std::cout << typeid (node_ptr).name() << std::endl;
        nodeLayer.push_back(std::move(node_ptr));
    }
}

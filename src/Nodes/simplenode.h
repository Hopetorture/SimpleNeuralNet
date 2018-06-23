#ifndef SIMPLENODE_H
#define SIMPLENODE_H

#include "node.h"

class SimpleNode : public Node
{
public:
    SimpleNode();
    SimpleNode(uint numOutputs, uint myIndex) : Node(numOutputs, myIndex){}
    virtual ~SimpleNode(){}
    virtual void calcOutputGradients(fp targetVal) override;
    virtual void calcHiddenGradients(const NodeVec &nextLayer) override;
    virtual fp sumDOW(const NodeVec &nextLayer) const override ;
    virtual void updateInputWeights(const NodeVec &prevLayer) override;
    virtual void feedForward(Layer* prevLayer)override;
protected:
    virtual void In(const std::vector<fp> &in, const std::vector<fp> &weight);
    virtual void Activate();
    virtual fp Out();
};

#endif // SIMPLENODE_H

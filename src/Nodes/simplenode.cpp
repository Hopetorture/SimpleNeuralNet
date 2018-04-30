#include "simplenode.h"

SimpleNode::SimpleNode()
{

}

void SimpleNode::calcOutputGradients(fp targetVal)
{
    fp delta = targetVal - m_outputVal;
    m_gradient = delta * act->derivative(m_outputVal);

}

void SimpleNode::calcHiddenGradients(const Layer &nextLayer)
{
    fp dow = sumDOW(nextLayer);
    m_gradient = dow * act->derivative(m_outputVal);
}

void SimpleNode::updateInputWeights(const Layer &prevLayer)
{
    for (uint n = 0; n < prevLayer.size(); ++n){
        Node &neuron = prevLayer[n];
        fp oldDeltaWeight = neuron.m_outputWeights[m_myIndex].deltaWeight;
        fp newDeltaWeight = Node::eta *neuron.getOutputVal() * m_gradient + Node::alpha * oldDeltaWeight;
    }
}

fp SimpleNode::sumDOW(const Layer &nextLayer)
{
    double sum = 0.0;
    for  (uint n = 0; n < nextLayer.size() - 1; ++n ){
        sum += m_outputWeights[n].weight * nextLayer[n].m_gradient;
    }
    return sum;
}

void SimpleNode::In(const std::vector<fp> &in, const std::vector<fp> &weight)
{
    this->sum = 0.0;
    for (uint i = 0; i < in.size(); i++){
        sum += in.at(i) * weight;
    }
}

void SimpleNode::Activate()
{
    this->act->activate(sum);
}

fp SimpleNode::Out()
{
    return 0;
}

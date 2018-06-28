#include "simplenode.h"
#include "Layers/layer.h"
#include "Layers/dense.h"
#include <QDebug>
//SimpleNode::SimpleNode()
//{

//}

void SimpleNode::calcOutputGradients(fp targetVal)
{
    fp delta = targetVal - m_outputVal;
    m_gradient = delta * act->derivative(m_outputVal);

}

void SimpleNode::calcHiddenGradients(const NodeVec &nextLayer)
{
    fp dow = sumDOW(nextLayer);
    m_gradient = dow * act->derivative(m_outputVal);
}

void SimpleNode::updateInputWeights(const NodeVec &prevLayer)
{
    for (uint n = 0; n < prevLayer.size(); ++n){
         std::shared_ptr<Node> neuron = prevLayer.at(n);
        //qDebug() << neuron->m_outputWeights.size() << " < ow size";
        fp oldDeltaWeight = neuron->m_outputWeights[m_myIndex].deltaWeight;
        fp newDeltaWeight = Node::eta * neuron->getOutputVal() * m_gradient + Node::alpha * oldDeltaWeight;
        neuron->m_outputWeights[m_myIndex].deltaWeight = newDeltaWeight;
        neuron->m_outputWeights[m_myIndex].weight += newDeltaWeight;
    }
}

void SimpleNode::feedForward(Layer *prevLayer)
{
    double sum = 0.0;
    for(unsigned n = 0 ; n < prevLayer->size(); ++n)
        {
            double d1 = prevLayer->at(n)->m_outputWeights[m_myIndex].weight;
            double d2 = prevLayer->at(n)->getOutputVal();
            sum += d1 * d2;
            //sum += prevLayer->at(n)->getOutputVal() * prevLayer->at(n)->m_outputWeights[m_myIndex].weight;
        }

        m_outputVal = act->activate(sum);
//        int dbg;
//        qDebug() << "Node output: "  << m_outputVal;
//        int dbg1;
//        int dbg2;
//        int dbg3;

}

void SimpleNode::debug()
{
    qDebug() <<"my index: "<<this->m_myIndex << " my gradient: "<<this->m_gradient
            <<  " my output weights: " << /*this->m_outputWeights*/ "tmp unavailavble"  << " my outputVal:" << this->m_outputVal;
}

fp SimpleNode::sumDOW(const NodeVec &nextLayer) const
{
    fp sum = 0.0;
    for  (uint n = 0; n < nextLayer.size() - 1; ++n ){
        sum += m_outputWeights[n].weight * nextLayer[n]->m_gradient;
    }
    return sum;
}

//void SimpleNode::In(const std::vector<fp> &in, const std::vector<fp> &weight)
//{
//    this->sum = 0.0;
//    for (uint i = 0; i < in.size(); i++){
//        sum += in.at(i) * weight.at(i);
//    }
//}

//void SimpleNode::Activate()
//{
//    this->act->activate(sum);
//}

//fp SimpleNode::Out()
//{
//    return 0;
//}

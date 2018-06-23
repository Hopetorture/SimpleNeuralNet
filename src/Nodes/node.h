#ifndef NODE_H
#define NODE_H
/*Abstract neuron class
*/

#include "constants.h"
#include <vector>
#include "activation.h"
#include <memory>
#include <cstdlib>

class Layer;

class Connection{
public:
    Connection(){
        weight = randomWeight();
    }
    fp weight;
    fp deltaWeight;
private:
    fp randomWeight(){
        return rand() / fp(RAND_MAX);
    }
};

class Node
{
public:
    //enum class ActivationMethod {};
    //Node(){}
    Node(uint numOutputs, uint myIndex);
    virtual ~Node(){}

    void setOutputValue(fp val){ this->m_outputVal = val; }
    fp getOutputVal(){return this->m_outputVal;}
    fp outputValue() const { return m_outputVal; }
    fp calculate(const std::vector<fp> &in, const std::vector<fp> &weight){
        In(in, weight);
        Activate();
        return Out();
    }

    void setParams(fp bias, std::shared_ptr<Activation> &a){
        //this->bias = bias; // todo - change sign
        this->act = std::shared_ptr<Activation>(std::move(a));
        //this->act = std::unique_ptr<Activation>(std::forward<Activation>(a));
    }

    virtual void calcOutputGradients(fp targetVal) = 0;
    virtual void calcHiddenGradients(const NodeVec &nextLayer) = 0;
    virtual fp sumDOW(const NodeVec &nextLayer) const = 0;
    virtual void updateInputWeights(const NodeVec &prevLayer) = 0;
    virtual void feedForward(Layer* prevLayer) = 0;

    std::vector<Connection> m_outputWeights;
    fp m_gradient = 0.0;

protected:
    fp m_outputVal;
    fp sum = 0.0; //summ of incoming signals * weights
    uint m_myIndex;
    static fp eta; // [0.0 ... 1.0] overall net training rate
    static fp alpha; // [0.0 .. n] momentun
    //fp bias;
    std::shared_ptr<Activation> act;

    virtual void In(const std::vector<fp> &in, const std::vector<fp> &weight) = 0;
    virtual void Activate() = 0;
    virtual fp Out() = 0;

};

#endif // NODE_H

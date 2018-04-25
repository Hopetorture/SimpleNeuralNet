#ifndef NODE_H
#define NODE_H
/*Abstract neuron class
*/

#include "constants.h"
#include <vector>
#include "activation.h"
#include <memory>
#include <cstdlib>

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
    Node(){}
    Node(uint numOutputs){
        //bias = b;
        for (int i = 0; i < numOutputs; i++){
            m_outputWeights.push_back(Connection());

        }

    }
    virtual ~Node(){}

    fp calculate(const std::vector<fp> &in){
        In(in);
        Activate();
        return Out();
    }

    void setParams(fp bias, std::unique_ptr<Activation> &a){
        //this->bias = bias; // todo - change sign
        this->act = std::unique_ptr<Activation>(std::move(a));
        //this->act = std::unique_ptr<Activation>(std::forward<Activation>(a));

    }

protected:
    fp m_outputVal;
    std::vector<Connection> m_outputWeights;
    //fp bias;
    std::unique_ptr<Activation> act;

    virtual void In(const std::vector<fp> &in) = 0;
    virtual void Activate() = 0;
    virtual fp Out() = 0;

};

#endif // NODE_H

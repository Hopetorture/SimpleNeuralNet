#ifndef NODE_H
#define NODE_H
/*Abstract neuron class
*/

#include "constants.h"
#include <vector>
#include "activation.h"
#include <memory>

class Node
{
public:
    //enum class ActivationMethod {};
    Node(){}
    Node(fp b){
        bias = b;

    }
    virtual ~Node(){}

    fp calculate(const std::vector<fp> &in){
        In(in);
        Activate();
        return Out();
    }

    void setParams(fp bias, std::unique_ptr<Activation> &a){
        this->bias = bias;
        this->act = std::unique_ptr<Activation>(std::move(a));
        //this->act = std::unique_ptr<Activation>(std::forward<Activation>(a));

    }

protected:
    fp midResult;
    fp bias;
    std::unique_ptr<Activation> act;

    virtual void In(const std::vector<fp> &in) = 0;
    virtual void Activate() = 0;
    virtual fp Out() = 0;

};

#endif // NODE_H

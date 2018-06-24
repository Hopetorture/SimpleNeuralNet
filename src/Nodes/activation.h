#ifndef ACTIVATION_H
#define ACTIVATION_H
#include "constants.h"

class Activation
{
public:
    Activation(){}
    virtual ~Activation(){}
    virtual fp operator()(const fp &in) = 0;
    fp activate(const fp &in){
        return this->operator ()(in);
    }
    virtual fp derivative(const fp &in)=0;
};

#endif // ACTIVATION_H

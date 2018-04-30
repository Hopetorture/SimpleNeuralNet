#ifndef STUBACTIVATION_H
#define STUBACTIVATION_H

#include "activation.h"
#include <cmath>

class StubActivation : public Activation
{
public:
    StubActivation();
    ~StubActivation();
    virtual fp operator()(const fp &in) override{
        // should try to use tanh(x)?
        //fp result = in / (1+ std::abs(in));  //sigmoid approximation
        fp result = tanh(in);
        std::cout << "activation Result" << result << std::endl;
        return result;
    }
    virtual fp derivative(const fp &in){
        return 1.0 - in * in;
    }

};

#endif // STUBACTIVATION_H

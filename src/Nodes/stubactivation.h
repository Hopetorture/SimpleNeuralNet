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
        return in / (1+ std::abs(in));  //sigmoid approximation
    }
};

#endif // STUBACTIVATION_H

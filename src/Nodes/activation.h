#ifndef ACTIVATION_H
#define ACTIVATION_H
#include "constants.h"

class Activation
{
public:
    Activation(){}
    virtual ~Activation() = 0;
    virtual fp operator()(const fp &in) = 0;
};

#endif // ACTIVATION_H

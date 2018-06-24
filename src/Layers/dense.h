#ifndef DENSE_H
#define DENSE_H

#include "layer.h"
#include <iostream>

class Dense : public Layer
{
public:
    Dense(int neuronCount, ActivationFunctions fn, uint nextLayerSize, std::string d, int dropout_ = 0);
    virtual ~Dense(){}

    Dense (const Dense&) = delete;
    Dense& operator= (const Dense&) = delete;    
    void debug() override;
};

#endif // DENSE_H

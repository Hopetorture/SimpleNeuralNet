#ifndef STUBACTIVATION_H
#define STUBACTIVATION_H

#include "activation.h"
#include <cmath>
#include <iostream>
#include <QDebug>

class StubActivation : public Activation
{
public:
    StubActivation();
    ~StubActivation();
    virtual fp operator()(const fp &in) override{
        //qDebug() << "in: " << in;
        // should try to use tanh(x)?
        //fp result = in / (1+ std::abs(in));  //sigmoid approximation
        fp result = tanh(in);
        //std::cout << "activation Result" << result << std::endl;
        //qDebug() << "activation res: " << result;
        return result;
    }
    virtual fp derivative(const fp &in){
        double d = 1.0 - in * in;
        return d;
    }

};

#endif // STUBACTIVATION_H

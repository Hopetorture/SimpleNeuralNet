#ifndef ACTIVATORSFACTORY_H
#define ACTIVATORSFACTORY_H
#include <string>
#include "activation.h"
#include "stubactivation.h"
//#include <map>
#include <memory>

class ActivatorsFactory
{
public:
    ActivatorsFactory();
    static auto getActivator(ActivationFunctions f)
    {

        switch(f){
        case ActivationFunctions::ReLU:
            break;
        case ActivationFunctions::Sigmoid:
            return std::shared_ptr<Activation>(new StubActivation());
            //return std::make_unique<StubActivation>();
        }

        return std::shared_ptr<Activation>(new StubActivation());
    }

};

#endif // ACTIVATORSFACTORY_H

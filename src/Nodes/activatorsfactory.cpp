#include "activatorsfactory.h"

ActivatorsFactory::ActivatorsFactory()
{

}

ActivatorsFactory::getActivator(ActivationFunctions f)
{

    switch(f){
    case ActivationFunctions::ReLU:
        break;
    case ActivationFunctions::Sigmoid:
        break;
    default:
        return nullptr;
        break;
    }

    return nullptr;
}

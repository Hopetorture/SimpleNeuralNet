#ifndef ACTIVATORSFACTORY_H
#define ACTIVATORSFACTORY_H
#include <string>
#include "activation.h"
#include <map>

class ActivatorsFactory
{
public:
    ActivatorsFactory();
    auto getActivator(ActivationFunctions f);

};

#endif // ACTIVATORSFACTORY_H

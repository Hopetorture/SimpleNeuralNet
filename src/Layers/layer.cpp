#include "layer.h"

//Layer::Layer(int neurons)
//{

//}

Layer::Layer(int neuronCount, ActivationFunctions fn, int dropout_)
    : neurons(neuronCount), activator(fn), droupoutRate(dropout_)
{

}



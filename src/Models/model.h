#ifndef MODEL_H
#define MODEL_H
#include "Models/abstractmodel.h"
#include "Layers/dense.h"
//#include "Nodes/activation.h"
//#include "Nodes/activatorsfactory.h"


class Model : public AbstractModel
{
public:
    Model(Topology t);
    virtual ~Model(){}
    virtual void feedFoward(const std::vector<fp> &inputVals)override{}
    virtual void backProp(const std::vector<fp> &targetVals)override{}
    virtual std::vector<fp>getResult()override{}

private:
    std::vector<Layer*> m_layers;
    auto getActivation(){return ActivationFunctions::Sigmoid;}

};

#endif // MODEL_H

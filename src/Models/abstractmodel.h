#ifndef ABSTRACTMODEL_H
#define ABSTRACTMODEL_H
#include "constants.h"
#include <vector>

class AbstractModel
{
public:
    AbstractModel(/*Topology t*/);
    virtual ~AbstractModel(){}

    virtual void feedFoward(const std::vector<fp> &inputVals)=0;
    virtual void backProp(const std::vector<fp> &targetVals)=0;
    virtual std::vector<fp> getResult()=0;

};

#endif // ABSTRACTMODEL_H

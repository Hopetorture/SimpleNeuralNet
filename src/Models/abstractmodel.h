#ifndef ABSTRACTMODEL_H
#define ABSTRACTMODEL_H
#include "constants.h"
#include "Layers/layer.h"

#include <vector>

class AbstractModel
{
public:
    AbstractModel(/*Topology t*/);
    virtual ~AbstractModel(){}

    virtual void feedFoward(const std::vector<fp> &inputVals)=0;
    virtual void backProp(const std::vector<fp> &targetVals)=0;
    virtual std::vector<fp> getResult()=0;
    fp getRecentAverageError(){return m_recentAverageError;}
protected:
    fp m_recentAverageError;
};

#endif // ABSTRACTMODEL_H

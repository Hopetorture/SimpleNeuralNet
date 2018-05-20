#include <iostream>

#include "Layers/dense.h"
#include "constants.h"
#include "Models/model.h"
using namespace std;


int main(int argc, char *argv[])
{
    cout << "Hello World!" << endl;
    Topology t = {10,20,10};
    Model *model = new Model(t);

    vector <fp> inputVals;
    model->feedFoward(inputVals);

    vector <fp> targetVals;
    model->backProp(targetVals);

    vector<fp> resultVals = model->getResult();

    std::cout << "resultVals" << std::endl;
    for (auto elem : resultVals){
        std::cout << elem << std::endl;
    }

    //auto a = new Dense(10, ActivationFunctions::Sigmoid);

    return 0;
}

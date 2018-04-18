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


    //auto a = new Dense(10, ActivationFunctions::Sigmoid);

    return 0;
}

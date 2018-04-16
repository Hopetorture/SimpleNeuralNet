#include <iostream>

#include "Layers/dense.h"
#include "constants.h"

using namespace std;


int main(int argc, char *argv[])
{
    cout << "Hello World!" << endl;

    auto a = new Dense(10, ActivationFunctions::Sigmoid);
    return 0;
}

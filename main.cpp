#include <iostream>

#include "Layers/dense.h"
#include "constants.h"
#include "Models/model.h"
#include "datafeed.h"
using namespace std;


int main(int argc, char *argv[])
{
    cout << "Hello World!" << endl;
    Topology t = {2,4,1};
    Model *model = new Model(t);
    DataFeed feed;
    feed.load("D:/Projects/build-SNNLib-Desktop_Qt_5_8_0_MinGW_32bit-Debug/debug/data.txt");

    size_t pass = 0;
    while(feed.hasNext()){
        pass++;
        auto next = feed.next();
        qDebug() << "Inputs: " << next.x << " " << next.y;
        model->feedFoward({next.x, next.y});

        auto resultVals = model->getResult();
        qDebug() << "Output values: " << resultVals;
        qDebug() << "Target values: " << next.out;
        //assert(t.back() == 1);
        model->backProp({next.out});

        qDebug() << "Net recent average error: " << model->getRecentAverageError();
    }
    //feed.load("./data.txt");

//    vector <fp> inputVals;
//    model->feedFoward(inputVals);

//    vector <fp> targetVals;
//    model->backProp(targetVals);

//    vector<fp> resultVals = model->getResult();

//    std::cout << "resultVals" << std::endl;
//    for (auto elem : resultVals){
//        std::cout << elem << std::endl;
//    }

    //auto a = new Dense(10, ActivationFunctions::Sigmoid);

    return 0;
}

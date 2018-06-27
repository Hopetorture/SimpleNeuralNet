#include <iostream>

#include "Layers/dense.h"
#include "constants.h"
#include "Models/model.h"
#include "datafeed.h"
using namespace std;

void main1(){
    cout << "Hello World!" << endl;
    Topology t = {2,4,1};
    Model *model = new Model(t);
    DataFeed feed;
    feed.load("D:/Projects/build-SNNLib-Desktop_Qt_5_8_0_MinGW_32bit-Debug/debug/data.txt");
    model->debug();
    size_t pass = 0;
    while(feed.hasNext()){
        pass++;
        auto next = feed.next();
        ///qDebug() << "Inputs: " << next.x << " " << next.y;
        model->feedFoward({next.x, next.y});

        auto resultVals = model->getResult();
        qDebug() << "Output values: " << resultVals.at(0);
        qDebug() << "Target values: " << next.out;
        //assert(t.back() == 1);
        model->backProp({next.out});

        qDebug() << "Net recent average error: " << model->getRecentAverageError();
    }
    qDebug() << "passes: " << pass;
    int stop;
    std::cin >> stop;
}

void main2(){
    Topology t = {15,40,7};
    Model *model = new Model(t);
    ZooDataFeed feed;
    feed.load("D:/Projects/build-SNNLib-Desktop_Qt_5_8_0_MinGW_32bit-Debug/debug/data_zoo.txt");
    //model->debug();
    size_t pass = 0;
    size_t pass2 = 0;


    while(feed.hasNext()){
        pass++;
        pass2++;
        auto next = feed.next();
        auto rawNext = next.naiveVec;
        model->feedFoward(rawNext);
        auto resultVals = model->getResult();
        qDebug() << "Output values: " << resultVals;
        //assert(t.back() == 1);
        std::vector<fp>correctVec = {0,0,0,0,0,0,0};
        correctVec[next.type - 1] = 1;
        qDebug() << next.name;
        qDebug() << "type: " << next.type;
        qDebug() << "Target values: " << correctVec;
        model->backProp(correctVec);

        qDebug() << "Net recent average error: " << model->getRecentAverageError();
        if (pass2 == 500)  break;
        if (pass == 100){
            feed.datasetIndex = 0;
        }
    }
    qDebug() << "passes: " << pass;
    int stop;
    std::cin >> stop;
}

int main(int argc, char *argv[])
{
    //main1();
    main2();
    return 0;
}

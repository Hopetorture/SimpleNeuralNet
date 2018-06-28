#ifndef DATAFEED_H
#define DATAFEED_H
#include <QFile>
#include <QTextStream>
#include <constants.h>
#include <QDebug>
#include <QStringList>
#include <iostream>

struct DE{
    double x;
    double y;
    double out;
};
struct Animal{
    QString name;
    fp fpName;
    std::vector<bool> boolAttribs;
    int legs;
    int type;
    std::vector<fp> naiveVec;
};
class ZooDataFeed{
public:
    void load(const QString &path){
        QFile data(path);
        if (!data.open(QIODevice::ReadOnly | QIODevice::Text))
            qWarning() << "Could not open a dataset";
        QTextStream ts(&data);
        while (!ts.atEnd()){
            parse(ts.readLine().split(","));
        }
    }
    std::vector<Animal> dataset;
    Animal next(){
        size_t current = datasetIndex;
        datasetIndex++;
        return dataset[current];
    }
    bool hasNext(){
        if (dataset.size() > datasetIndex)
            return true;
        else
            return false;
    }
    size_t datasetIndex = 0;
private:
    void parse(QStringList qsl){
        //qDebug() << qsl;
        Animal newAnimal;
        newAnimal.name = qsl[0];
        newAnimal.fpName = newAnimal.name.toDouble();
        //newAnimal.naiveVec.push_back(newAnimal.fpName);
        for (int i = 1; i < 13; i++){
            QString b = qsl[i];
            newAnimal.boolAttribs.push_back(b.toInt());
            newAnimal.naiveVec.push_back(b.toDouble());
        }
        newAnimal.legs = qsl[13].toInt();
        for (int i = 14; i < 16; i++){
            newAnimal.boolAttribs.push_back(qsl[i].toInt());
            newAnimal.naiveVec.push_back(qsl[i].toDouble());
        }
        //newAnimal.type = qsl[17].toInt();
        newAnimal.type = qsl.back().toInt();
        qDebug() << qsl;
        //int zz;
        //std::cin >> zz;
        dataset.push_back(newAnimal);
        //newAnimal.naiveVec.push_back(qsl.back().toDouble());
    }

};
class DataFeed
{
public:
    DataFeed();
    void load(const QString &path){
        QFile data(path);
        if (!data.open(QIODevice::ReadOnly | QIODevice::Text))
            qWarning() << "Could not open a dataset";

        QTextStream ts(&data);
        QString topology = ts.readLine();
        QStringList tmp = topology.split(" ");
        tmp.removeOne("topology:");
        for (QString s: tmp){
            t.push_back(s.toInt());
        }
        qDebug() << "parsed topology:" << t;

        while (!ts.atEnd()) {
            QString inLine = ts.readLine().trimmed();
            QString outLine = ts.readLine().trimmed();

            QStringList inParse = inLine.split(" ");
            //qDebug() << "in: " << inParse;

            inParse.removeAt(0);
            DE de;
            de.x = inParse.at(0).toDouble();
            de.y = inParse.at(1).toDouble();
            de.out = outLine.split(" ")[1].toDouble();
//            qDebug() << "out: " << outLine.split(" ")[1].toDouble();
//            qDebug() << "DE: " << "i1:" << de.i1 << "  i2:  " << de.i2 << "  out: " << de.out;
//            int zzz;
//            std::cin >> zzz;
            dataset.push_back(de);
        }
    }

    DE next(){
        size_t current = datasetIndex;
        datasetIndex++;
        return dataset[current];
    }
    bool hasNext(){
        if (dataset.size() > datasetIndex)
            return true;
        else
            return false;
    }

    Topology t;
    std::vector<DE> dataset;
private:
    size_t datasetIndex = 0;
};

#endif // DATAFEED_H

#include "node.h"
#include <QDebug>

Node::Node(uint numOutputs, uint myIndex){
    qDebug() << "Called with numOut: " << numOutputs << " mIndex:" << myIndex;
    for (int i = 0; i < numOutputs; i++){
        m_outputWeights.push_back(Connection());
    }
    m_myIndex = myIndex;
    qDebug() << "m_output weights size = " << m_outputWeights.size();
}

fp Node::eta = 0.15; // todo - make config
fp Node::alpha = 0.5;


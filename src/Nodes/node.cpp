#include "node.h"

Node::Node(uint numOutputs, uint myIndex){
    for (int i = 0; i < numOutputs; i++){
        m_outputWeights.push_back(Connection());
    }
    m_myIndex = myIndex;
}

fp Node::eta = 0.15; // todo - make config
fp Node::alpha = 0.5;


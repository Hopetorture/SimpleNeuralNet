#include "model.h"
#include <QMap>

Model::Model(Topology t)
{
    uint numLayers = t.size();
    QMap<int, std::string> debugMap;
    debugMap.insert(0, std::string("first Layer"));
    debugMap.insert(1, std::string("hidden Layer"));
    debugMap.insert(2, std::string("output Layer"));
    for (uint i = 0; i < numLayers; i++){
        uint nextLayerOutputs = i == t.size() - 1 ? 0 : t.at(i+1);
        m_layers.push_back(new Dense(t.at(i), getActivation(), nextLayerOutputs, debugMap.value(i)));

    }
    m_layers.back()->back()->setOutputValue(1.0);
    //m_layers.back()->
    //std::cout << "FIX THIS!!! 1234" << std::endl;
}

Model::~Model(){
    //delete m_layers;
    for (auto &e : m_layers)
        delete e;
}

void Model::feedFoward(const std::vector<fp> &inputVals)
{
    //m_layers.at(0);
    //qDebug()<< "feed forward: "<<"in: " << inputVals.size() << " expected: " << m_layers[0]->size() - 1;
    assert(inputVals.size() == m_layers[0]->size() - 1 ); //debug check, -1 for bias neuron
    //assign the input vals into neurons
    for (uint i = 0; i < inputVals.size(); ++i){
        m_layers[0]->at(i)->setOutputValue(inputVals[i]);
    }
    //forward propagate
    for (uint layerNum = 1; layerNum < m_layers.size(); ++layerNum){
        auto prevLayer = m_layers[layerNum - 1];
        for (uint n = 0; n < m_layers[layerNum]->size() - 1; ++n){ // -1 for bias neuron
            m_layers[layerNum]->at(n)->feedForward(prevLayer);
            ///m_layers[layerNum]->at(n)->feedForward(prevLayer);
            /// CHECK EXAMPLE CODE,  what should actually get called here?
            //std::cout << "Fix me here" << std::endl;
        }
    }
}

void Model::backProp(const std::vector<fp> &targetVals)
{
    //qDebug() << "back prop started";
    //calculate overall net error (Root mean square error of output neuron errors)
    Layer* outputLayer = m_layers.back();
    m_error = 0.0;

    for (int n = 0; n < outputLayer->size() - 1; ++n){
        fp delta = targetVals[n] - outputLayer->at(n)->getOutputVal();
        m_error += delta * delta;
    }
    m_error /= outputLayer->size() - 1;
    m_error = sqrt(m_error); //Root mean square

    //TODO: make metrics more flexible , perhaps a composite class?
    m_recentAverageError = (m_recentAverageError * m_recentAverageSmoothingFactor + m_error) /
                                       (m_recentAverageSmoothingFactor + 1.0);

    //calculate output layer gradients
    for (uint n = 0; n < outputLayer->size() - 1; ++n){
        //std::cout << typeid(outputLayer).name() << std::endl;
        std::shared_ptr<Node> node = outputLayer->at(n);
//                outputLayer->operator [](n);
                //outputLayer[n]->calcOutputGradients(targetVals[n]);
        node->calcOutputGradients(targetVals[n]);
    }
    //calculate gradients on hidden layers
    for (uint layerNum = m_layers.size() - 2;  layerNum > 0; --layerNum){
        Layer *hiddenLayer = m_layers[layerNum];
        Layer *nextLayer = m_layers[layerNum + 1];

        for (uint n = 0; n < hiddenLayer->size(); ++n){
            hiddenLayer->at(n)->calcHiddenGradients(nextLayer->getNodeVec());
        }
    }

    // For all layers from outputs to first hidden layer, update connection weights
    for (uint layerNum = m_layers.size() - 1;  layerNum > 0; --layerNum){
        Layer *layer = m_layers[layerNum];
        Layer *prevLayer = m_layers[layerNum - 1];

        for (uint n = 0; n < layer->size() - 1; ++n){
            layer->at(n)->updateInputWeights(prevLayer->getNodeVec());
        }

    }
}

std::vector<fp> Model::getResult()
{
    std::vector<fp> res;
    for (uint n = 0; n < m_layers.size() - 1; ++n){

        res.push_back(m_layers.back()->at(n)->getOutputVal());
    }
    return res;
}

void Model::debug()
{
    for (Layer* l : m_layers){
        l->debug();
    }
}

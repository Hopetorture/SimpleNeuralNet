#include "model.h"

Model::Model(Topology t)
{
    uint numLayers = t.size();

    for (uint i = 0; i < numLayers; i++){
        uint nextLayerOutputs = i == t.size() - 1 ? 0 : t.at(i+1);
        m_layers.push_back(new Dense(t.at(i), getActivation(), nextLayerOutputs));

    }
    m_layers.back().setOutputVal(-1.0);
}

Model::~Model(){
    delete m_layers;
}

void Model::feedFoward(const std::vector<fp> &inputVals)
{
    assert(inputVals.size() == m_layers[0].size() - 1 ); //debug check, -1 for bias neuron
    //assign the input vals into neurons
    for (uint i = 0; i < inputVals.size(); ++i){
        m_layers[0][i].setOutputValue(inputVals[i]);
    }
    //forward propagate
    for (uint layerNum = 1; layerNum < m_layers.size(); ++i){
        Layer &prevLayer = m_layers[layerNum - 1];
        for (uint n = 0; n < m_layers[layerNum].size() - 1; ++n){ // -1 for bias neuron
            m_layers[layerNum][n].feedForward(prevLayer);
        }
    }
}

void Model::backProp(const std::vector<fp> &targetVals)
{
    //calculate overall net error (Root mean square error of output neuron errors)
    Layer &outputLayer = m_layers.back();
    m_error = 0.0;

    for (uint n = 0; n < outputLayer.size() - 1; ++n){
        fp delta = targetVals[n] - outputLayer[n].getOutputVal();
        m_error += delta * delta;
    }
    m_error /= outputLayer.size() - 1;
    m_error = sqrt(m_error); //Root mean square

    //TODO: make metrics more flexible , perhaps a composite class?
    m_recentAverageError = (m_recentAverageError * m_recentAverageSmoothingFactor + m_error) /
                                       (m_recentAverageSmoothingFactor + 1.0);

    //calculate output layer gradients
    for (uint n = 0; n < outputLayer.size() - 1; ++n){
        outputLayer[n].calcOutputGradients(targetVals[n]);
    }
    //calculate gradients on hidden layers
    for (uint layerNum = m_layers.size() - 2;  layerNum > 0; --layerNum){
        Layer &hiddenLayer = m_layers[layerNum];
        Layer &nextLayer = m_layers[layerNum + 1];

        for (uint n = 0; n < hiddenLayer.size(); ++n){
            hiddenLayer[n].calcHiddenGradients(nextLayer);
        }
    }

    // For all layers from outputs to first hidden layer, update connection weights
    for (uint layerNum = m_layers.size() - 1;  layerNum > 0; --layerNum){
        Layer &layer = m_layers[layerNum];
        Layer &prevLayer = m_layers[layerNum];

        for (uint n = 0; n < layer.size() - 1; ++n){
            layer[n].updateInputWeights(prevLayer);
        }

    }
}

std::vector<fp> Model::getResult()
{
    std::vector<fp> res;
    for (uint n = 0; n < m_layers.size() - 1; ++n){
        res.push_back(m_layers.back()[n].getOutputVal());
    }
    return res;
}

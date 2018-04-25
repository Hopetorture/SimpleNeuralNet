#include "model.h"

Model::Model(Topology t)
{
    uint numLayers = t.size();

    for (uint i = 0; i < numLayers; i++){
        uint nextLayerOutputs = i == t.size() - 1 ? 0 : t.at(i+1);
        m_layers.push_back(new Dense(t.at(i), getActivation(), nextLayerOutputs));

    }
}

#ifndef CONSTANTS_H
#define CONSTANTS_H
#include <vector>
using fp = double;
enum class ActivationFunctions{ReLU, Sigmoid};
enum class LayerType {Simple, Convolutional};
enum class ConnectionType {FullyConnected};

using Topology = std::vector<int>;
#endif // CONSTANTS_H

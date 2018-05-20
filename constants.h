#ifndef CONSTANTS_H
#define CONSTANTS_H
#include <vector>
#include <memory>
using fp = double;
class Node;
using NodeVec = std::vector<std::shared_ptr<Node> >;
enum class ActivationFunctions{ReLU, Sigmoid};
enum class LayerType {Simple, Convolutional};
enum class ConnectionType {FullyConnected};

using Topology = std::vector<unsigned int>;
using uint = unsigned int;
#endif // CONSTANTS_H

#ifndef SIMPLENODE_H
#define SIMPLENODE_H

#include "node.h"

class SimpleNode : public Node
{
public:
    SimpleNode();
    SimpleNode(fp b) : Node(b){}
    virtual ~SimpleNode(){}

protected:
    virtual void In(const std::vector<fp> &in);
    virtual void Activate();
    virtual fp Out();
};

#endif // SIMPLENODE_H

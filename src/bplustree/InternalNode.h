#ifndef INTERNAL_NODE_H
#define INTERNAL_NODE_H
#include "Node.h"

class InternalNode : public Node
{
public:
    std::vector<uint64_t> children;

    InternalNode(uint64_t offset) : Node(offset, false) {};
};

#endif
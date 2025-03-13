#ifndef LEAF_NODE_H
#define LEAF_NODE_H

#include "Node.h"

class LeafNode : public Node
{
public:
    uint64_t next;
    std::vector<std::pair<uint64_t, uint64_t>> dataReference;

    LeafNode(uint64_t offset) : Node(offset, true), next(0) {};
};

#endif
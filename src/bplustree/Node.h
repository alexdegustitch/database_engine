#ifndef NODE_H
#define NODE_H

#include <vector>

class Node
{
public:
    bool isLeaf;
    uint64_t offset;
    std::vector<int> keys;
    uint64_t parent;

    Node(uint64_t offset, bool isLeaf) : isLeaf(isLeaf), offset(offset), parent(0) {}

    virtual ~Node() = default; // Virtual destructor for polymorphism
};

#endif
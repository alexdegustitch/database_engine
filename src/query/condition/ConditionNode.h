#ifndef CONDITION_NODE_H
#define CONDITION_NODE_H

#include "../../catalog/Record.h"

enum LOGICAL_OP
{
    AND,
    OR
};
enum COMPARISON_OP
{
    LT,
    LE,
    GT,
    GE,
    EQ,
    NE
};

class ConditionNode
{
public:
    bool isLeaf;
    ConditionNode(bool isLeaf = false) : isLeaf(isLeaf) {}
};

#endif
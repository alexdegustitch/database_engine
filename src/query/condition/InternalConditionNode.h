#ifndef INTERNAL_CONDITION_NODE_H
#define INTERNAL_CONDITION_NODE_H

#include "ConditionNode.h"
#include "LeafConditionNode.h"

class InternalConditionNode : public ConditionNode
{
public:
    InternalConditionNode(LOGICAL_OP op, ConditionNode *left, ConditionNode *right);
    bool visitChildren(Record *record);

private:
    ConditionNode *left, *right;
    LOGICAL_OP op;
};

#endif
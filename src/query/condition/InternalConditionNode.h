#ifndef INTERNAL_CONDITION_NODE_H
#define INTERNAL_CONDITION_NODE_H

#include "ConditionNode.h"
#include "LeafConditionNode.h"

class InternalConditionNode : public ConditionNode
{
public:
    InternalConditionNode(LOGICAL_OP op, ConditionNode *left, ConditionNode *right);
    bool visitChildren(Record &record);

    ConditionNode *getLeftChild()
    {
        return left;
    }
    ConditionNode *getRightChild()
    {
        return right;
    }

    LOGICAL_OP getOp() { return op; }

private:
    ConditionNode *left, *right;
    LOGICAL_OP op;
};

#endif
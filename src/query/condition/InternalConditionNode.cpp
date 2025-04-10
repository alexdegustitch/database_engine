#include "InternalConditionNode.h"

InternalConditionNode::InternalConditionNode(LOGICAL_OP op, ConditionNode *left, ConditionNode *right) : ConditionNode(false), op(op), left(left), right(right) {}

bool InternalConditionNode::visitChildren(Record &record)
{

    if (left->isLeaf)
    {
        if (op == LOGICAL_OP::OR)
            return static_cast<LeafConditionNode *>(left)->evaluate(record) || static_cast<LeafConditionNode *>(right)->evaluate(record);
        else
            return static_cast<LeafConditionNode *>(left)->evaluate(record) && static_cast<LeafConditionNode *>(right)->evaluate(record);
    }

    if (op == LOGICAL_OP::OR)
        return static_cast<InternalConditionNode *>(left)->visitChildren(record) || static_cast<InternalConditionNode *>(right)->visitChildren(record);
    else
        return static_cast<InternalConditionNode *>(left)->visitChildren(record) && static_cast<InternalConditionNode *>(right)->visitChildren(record);
}
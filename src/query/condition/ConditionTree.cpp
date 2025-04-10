#include "ConditionTree.h"
ConditionTree::ConditionTree(ConditionNode *root) : root(root) {};

bool ConditionTree::evaluateRecord(Record &record)
{
    if (root->isLeaf)
    {
        return static_cast<LeafConditionNode *>(root)->evaluate(record);
    }
    return static_cast<InternalConditionNode *>(root)->visitChildren(record);
}

#ifndef CONDITION_TREE_H
#define CONDITION_TREE_H

#include "ConditionNode.h"
#include "LeafConditionNode.h"
#include "InternalConditionNode.h"

class ConditionTree
{
public:
    ConditionTree(ConditionNode *root) {}
    bool evaluateRecord(Record *);

private:
    ConditionNode *root;
};

#endif
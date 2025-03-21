#ifndef LEAF_CONDITION_NODE_H
#define LEAF_CONDITION_NODE_H

#include "ConditionNode.h"
#include <string>

class LeafConditionNode : public ConditionNode
{
public:
    LeafConditionNode(COMPARISON_OP op, std::string colName, const char *recordValue);
    bool evaluate(Record *record);

private:
    COMPARISON_OP op;
    std::string colName;
    const char *recordValue;
};

#endif
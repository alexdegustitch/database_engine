#ifndef LEAF_CONDITION_NODE_H
#define LEAF_CONDITION_NODE_H

#include "ConditionNode.h"
#include "../../utils/TypeConverter.h"

#include <string>

class LeafConditionNode : public ConditionNode
{
public:
    LeafConditionNode(COMPARISON_OP op, std::string tableName, std::string colName, const char *recordValue);
    bool evaluate(Record &record);
    COMPARISON_OP getOp() { return op; };
    std::string getColName() { return colName; };
    std::string getTableName() { return tableName; };
    DataType getConvertedValue() { return convertedValue; };

private:
    COMPARISON_OP op;
    std::string colName;
    std::string tableName;
    const char *recordValue;
    DataType convertedValue;
};

#endif
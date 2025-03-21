#include "LeafConditionNode.h"

LeafConditionNode::LeafConditionNode(COMPARISON_OP op, std::string colName, const char *recordValue) : ConditionNode(true), op(op), colName(colName), recordValue(recordValue)
{
}

bool LeafConditionNode::evaluate(Record *record)
{

    switch (op)
    {
    case COMPARISON_OP::EQ:
        return record->getRawValues()[colName] == recordValue;
        break;
    case COMPARISON_OP::NE:
        return record->getRawValues()[colName] != recordValue;
        break;
    case COMPARISON_OP::GE:
        return record->getRawValues()[colName] >= recordValue;
        break;
    case COMPARISON_OP::GT:
        return record->getRawValues()[colName] > recordValue;
        break;
    case COMPARISON_OP::LE:
        return record->getRawValues()[colName] <= recordValue;
        break;
    case COMPARISON_OP::LT:
        return record->getRawValues()[colName] < recordValue;
        break;
    default:
        break;
    }
    return false;
}
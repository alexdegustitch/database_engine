#include "LeafConditionNode.h"

LeafConditionNode::LeafConditionNode(COMPARISON_OP op, std::string tableName, std::string colName, const char *recordValue) : ConditionNode(true), op(op), colName(colName), recordValue(recordValue)
{
    int tableId = SystemTableManager::getInstance().getAllTableSchemas()[tableName].tableId;
    std::string col = colName + ":" + std::to_string(tableId);
    std::cout << col << std::endl;
    char *type = SystemTableManager::getInstance().getAllColumnSchema()[col].type;
    convertedValue = TypeConverter::getInstance().deserializeValue(type, recordValue);
    std::cout << "Table id: " << tableId << " col: " << col << " convertedValue: ";
    TypeConverter::getInstance().printDataTypeFormatted(convertedValue, 12);
    std::cout << std::endl;
}

bool LeafConditionNode::evaluate(Record &record)
{

    std::cout << "Evaluating a leaf!" << std::endl;
    int tableId = SystemTableManager::getInstance().getAllTableSchemas()[tableName].tableId;
    std::string col = colName + ":" + std::to_string(tableId);
    char *type = SystemTableManager::getInstance().getAllColumnSchema()[col].type;
    std::cout << "I AM HERE!" << std::endl;
    if (record.getRawValues().find(colName) == record.getRawValues().end())
    {
        std::cout << "NO THAT COLL" << std::endl;
    }
    else
    {
        std::cout << "YES THAT COLL" << std::endl;
    }
    // DataType convertedRecordValue = TypeConverter::getInstance().deserializeValue(type, record.getRawValues()[colName]);
    std::cout << "Table id: " << tableId << " col: " << col << " convertedValue: ";
    DataType convertedRecordValue = record.getValues()[colName];
    TypeConverter::getInstance().printDataTypeFormatted(convertedRecordValue, 12);
    std::cout << std::endl;
    switch (op)
    {
    case COMPARISON_OP::EQ:
        return convertedRecordValue == convertedValue;
        break;
    case COMPARISON_OP::NE:
        return convertedRecordValue != convertedValue;
        break;
    case COMPARISON_OP::GE:
        return convertedRecordValue >= convertedValue;
        break;
    case COMPARISON_OP::GT:
        return convertedRecordValue > convertedValue;
        break;
    case COMPARISON_OP::LE:
        return convertedRecordValue <= convertedValue;
        break;
    case COMPARISON_OP::LT:
        return convertedRecordValue < convertedValue;
        break;
    default:
        break;
    }
    return false;
}
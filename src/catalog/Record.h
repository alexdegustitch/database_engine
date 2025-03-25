#ifndef RECORD_H
#define RECORD_H

#include <unordered_map>
#include "SystemTableManager.h"
#include "../utils/TypeConverter.h"
#include <string>

class Record
{
public:
    Record(TableSchema &tbSchema, std::vector<ColumnSchema> &cols, char *data);
    char *readData() { return data; }
    void deserializeData();
    std::unordered_map<std::string, DataType> &getValues() { return values; }
    std::unordered_map<std::string, char *> &getRawValues() { return rawValues; }

private:
    char *data;
    TableSchema tb;
    std::vector<ColumnSchema> &cols;
    std::unordered_map<std::string, DataType> values;
    std::unordered_map<std::string, char *> rawValues;
};
#endif
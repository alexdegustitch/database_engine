#ifndef RECORD_MANAGER_H
#define RECORD_MANAGER_H

#include "SystemTableManager.h"
#include "../buffer/BufferManager.h"
#include "../index/IndexHandler.h"
#include "../utils/TypeConverter.h"
class RecordManager
{
public:
    RecordManager();
    static RecordManager &getInstance();
    void readRecord(int pageId, uint64_t offseet, std::string &tableName, std::vector<std::string> &cols);

    void deserializeData(char *data, std::vector<ColumnSchema> &cols, std::unordered_map<std::string, std::string> &values);
    std::unordered_map<int, DataType> serializeData(std::vector<std::string> &colNames, std::vector<std::string> &colVals, std::vector<ColumnSchema> &schemas, std::vector<char> &row);

private:
    SystemTableManager &tableManager = SystemTableManager::getInstance();
    BufferManager *bufferManager;
    IndexHandler *indexHandler;
};

#endif
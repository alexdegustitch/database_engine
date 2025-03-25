#include "DatabaseManager.h"

DatabaseManager::DatabaseManager() {}

DatabaseManager &DatabaseManager::getInstance()
{
    static DatabaseManager instance;
    return instance;
}

bool DatabaseManager::insertRecord(const std::string &tableName, std::vector<std::string> &cols, std::vector<std::string> &values)
{

    std::vector<ColumnSchema> schemas = SystemTableManager::getInstance().getSchemasForColumns(tableName, cols);
    std::vector<char> row;
    std::unordered_map<int, DataType> colValues = RecordManager::getInstance().serializeData(cols, values, schemas, row);
    int pageId = PageManager::getInstance().findPageWithFreeSpace(tableName);
    Page *p = BufferManager::getInstance().fetchPage(tableName, pageId);
    BufferManager::getInstance().flushPage(tableName, pageId);
    int slotIdx = p->insertRecord(row);

    std::vector<std::pair<std::string, int>> indexes = SystemTableManager::getInstance().getAllIndexNamesForTable(tableName);

    for (auto idx : indexes)
    {
        DataType val = colValues[idx.second];
        IndexHandler::getInstance().insertIntoIndex(idx.first, std::get<int>(val), pageId, slotIdx);
    }
}
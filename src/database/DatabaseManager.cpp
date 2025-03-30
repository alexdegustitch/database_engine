#include "DatabaseManager.h"

DatabaseManager::DatabaseManager() {}

DatabaseManager &DatabaseManager::getInstance()
{
    static DatabaseManager instance;
    return instance;
}

bool DatabaseManager::insertRecord(const std::string &tableName, std::vector<std::string> &cols, std::vector<std::string> &values)
{
    std::cout << "cols size: " << cols.size() << std::endl;
    std::cout << "values size: " << values.size() << std::endl;
    for (int i = 0; i < cols.size(); i++)
    {
        std::cout << "col: " << cols[i] << ", val: " << values[i] << std::endl;
    }
    std::cout << "IN INSERT RECORD " << std::endl;
    std::vector<ColumnSchema> schemas = SystemTableManager::getInstance().getSchemasForColumns(tableName, cols);
    std::vector<char> row;
    std::unordered_map<int, DataType> colValues = RecordManager::getInstance().serializeData(cols, values, schemas, row);
    int pageId = PageManager::getInstance().findPageWithFreeSpace(tableName);
    Page *p = BufferManager::getInstance().fetchPage(tableName, pageId);
    int slotIdx = p->insertRecord(row);
    BufferManager::getInstance().flushPage(tableName, pageId);
    PageManager::getInstance().updateFSM(tableName, pageId, p->getFreeSpace());
    PageManager::getInstance().saveFSM(tableName);

    std::vector<std::pair<std::string, int>> indexes = SystemTableManager::getInstance().getAllIndexNamesForTable(tableName);

    for (auto idx : indexes)
    {
        std::cout << "Idx name: " << idx.first << " col id: " << idx.second << std::endl;
        DataType val = colValues[idx.second];
        std::cout << "val: " << std::get<int>(val) << " " << pageId << " " << slotIdx << std::endl;
        IndexHandler::getInstance().insertIntoIndex(idx.first, std::get<int>(val), pageId, slotIdx);
    }
    std::cout << "Insert record done " << std::endl;
}
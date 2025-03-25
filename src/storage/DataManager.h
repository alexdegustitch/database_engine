#ifndef DATA_MANAGER_H
#define DATA_MANAGER_H

#include "../index/IndexHandler.h"
#include "../buffer/BufferManager.h"
#include "../catalog/SystemTableManager.h"

class DataManager
{
public:
    DataManager();
    void getData(std::string &tableName);
    void updateData();
    void deleteData();
    void insertData();

private:
    IndexHandler *indexHandler;
    SystemTableManager &systemTableManager = SystemTableManager::getInstance();
    BufferManager *bufferManager;
};
#endif
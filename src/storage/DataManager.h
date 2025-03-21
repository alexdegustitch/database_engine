#ifndef DATA_MANAGER_H
#define DATA_MANAGER_H

#include "IndexHandler.h"
#include "BufferManager.h"
#include "SystemTableManager.h"

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
    SystemTableManager *systemTableManager;
    BufferManager *bufferManager;
};
#endif
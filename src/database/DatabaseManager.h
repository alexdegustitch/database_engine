#ifndef DATABASE_MANAGER_H
#define DATABASE_MANAGER_H

#include "../catalog/SystemTableManager.h"
#include "../catalog/RecordManager.h"
#include "../index/IndexHandler.h"
#include "../buffer/BufferManager.h"
#include "../storage/PageManager.h"
#include <vector>

class DatabaseManager
{
public:
    DatabaseManager();
    static DatabaseManager &getInstance();

    bool insertRecord(const std::string &tableName, std::vector<std::string> &cols, std::vector<std::string> &values);
    bool deleteRecord();
    bool updateRecord();
    bool selectRecord();
};

#endif
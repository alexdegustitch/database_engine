#ifndef RECORD_MANAGER_H
#define RECORD_MANAGER_H

#include "SystemTableManager.h"
#include "BufferManager.h"
#include "IndexHandler.h"

class RecordManager
{
public:
    RecordManager();
    void readRecords(int pageId, uint64_t offseet, std::string &tableName, std::vector<std::string> &cols);

private:
    SystemTableManager *tableManager;
    BufferManager *bufferManager;
    IndexHandler *indexHandler;
};

#endif
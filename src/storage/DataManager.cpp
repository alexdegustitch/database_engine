#include "DataManager.h"

DataManager::DataManager()
{
    systemTableManager = new SystemTableManager("data/tableSchema.dat", "data/columnSchema.dat");
    bufferManager = new BufferManager();
    indexHandler = new IndexHandler();
}

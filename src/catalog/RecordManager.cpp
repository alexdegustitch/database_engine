#include "RecordManager.h"

RecordManager::RecordManager()
{
    tableManager = new SystemTableManager("data/tableSchema.dat", "data/columnSchema.dat");
    bufferManager = new BufferManager();
    indexHandler = new IndexHandler();
}

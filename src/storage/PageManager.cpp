
#include "PageManager.h"

PageManager::PageManager() {}

PageManager &PageManager::getInstance()
{
    static PageManager instance;
    return instance;
}

int PageManager::findPageWithFreeSpace(const std::string &tableName)
{
    int id = getFSMManager(tableName).findPageWithFreeSpace();
    if (id == -1)
    {
        id = allocatePage(tableName);
    }
    return id;
}

int PageManager::allocatePage(const std::string &tableName)
{
    std::string path = tableName + ".tbl";
    std::ofstream file(path, std::ios::binary | std::ios::app);
    if (!file)
    {
        std::cout << "Could not allocate a new page!" << std::endl;
        return -1;
    }
    FreeSpaceManager &manager = getFSMManager(tableName);
    Page p;
    int id = manager.size();
    p.setPageID(id);
    manager.growToPage(id);
    return id;
}
void PageManager::updateFSM(const std::string &tableName, int pageId, uint16_t freeSpace)
{
    getFSMManager(tableName).update(pageId, freeSpace);
}

void PageManager::saveFSM(const std::string &tableName)
{
    getFSMManager(tableName).save();
}

FreeSpaceManager &PageManager::getFSMManager(const std::string &tableName)
{
    if (fsmTables.find(tableName) == fsmTables.end())
    {
        fsmTables[tableName] = FreeSpaceManager::getInstance("data/fsm/" + tableName + ".dat");
    }
    return fsmTables[tableName];
}
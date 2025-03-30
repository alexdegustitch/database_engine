#ifndef PAGE_MANAGER_H
#define PAGE_MANAGER_H

#include "FreeSpaceManager.h"
#include "Page.h"
#include <unordered_map>

class PageManager
{
public:
    PageManager();
    static PageManager &getInstance();

    int findPageWithFreeSpace(const std::string &tableName);
    void updateFSM(const std::string &tableName, int pageId, uint16_t freeSpace);
    void saveFSM(const std::string &tableName);

private:
    std::unordered_map<std::string, FreeSpaceManager> fsmTables;

    int allocatePage(const std::string &tableName);
    FreeSpaceManager &getFSMManager(const std::string &tableName);
};

#endif
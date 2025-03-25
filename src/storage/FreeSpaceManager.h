#ifndef FREE_SPACE_MANAGER_H
#define FREE_SPACE_MANAGER_H

#include "Page.h"
#include <vector>
#include <string>
#include <fstream>
#include <iostream>

enum class FreeSpaceTag
{
    EMPTY = 0,
    LOW = 1,
    MEDIUM = 2,
    HIGH = 3,
    FULL = 4
};

class FreeSpaceManager
{
public:
    FreeSpaceManager() {}
    FreeSpaceManager(const std::string &path);
    static FreeSpaceManager &getInstance(const std::string &filePath);
    FreeSpaceTag clasifyFreeSpace(uint16_t freeSpace, uint16_t pageSize);
    void init(size_t numPages);
    void load();
    void update(int pageId, uint16_t freeSpace);
    void save();
    int size() { return fsm.size(); }
    int findPageWithFreeSpace();
    void growToPage(int pageId);

private:
    std::vector<FreeSpaceTag> fsm;
    std::string filePath;
};

#endif
#include "FreeSpaceManager.h"

FreeSpaceManager::FreeSpaceManager(const std::string &path) : filePath(path)
{
    std::ofstream file(path, std::ios::binary);
    if (!file)
    {
        std::cerr << "Could not open file for FSM file " << path << std::endl;
    }
    file.close();
}

FreeSpaceManager &FreeSpaceManager::getInstance(const std::string &path)
{
    static FreeSpaceManager instance(path);
    return instance;
}

FreeSpaceTag FreeSpaceManager::clasifyFreeSpace(uint16_t freeSpace, uint16_t pageSize)
{
    float ratio = static_cast<float>(freeSpace) / pageSize;
    if (ratio == 0.0f)
    {
        return FreeSpaceTag::FULL;
    }
    else if (ratio < 0.2f)
    {
        return FreeSpaceTag::HIGH;
    }
    else if (ratio < 0.5f)
    {
        return FreeSpaceTag::MEDIUM;
    }
    else if (ratio < 0.8f)
    {
        return FreeSpaceTag::LOW;
    }
    return FreeSpaceTag::EMPTY;
}

void FreeSpaceManager::init(size_t numPages)
{
    fsm.resize(numPages, FreeSpaceTag::EMPTY);
}

void FreeSpaceManager::load()
{
    std::ifstream file(filePath, std::ios::binary);
    if (!file)
    {
        std::cerr << "Could not open fsm file!" << std::endl;
        return;
    }
    int size;
    file.read(reinterpret_cast<char *>(&size), sizeof(int));
    fsm.resize(size);
    file.read(reinterpret_cast<char *>(fsm.data()), sizeof(FreeSpaceTag) * size);
}

void FreeSpaceManager::update(int pageId, uint16_t freeSpace)
{
    growToPage(pageId);
    fsm[pageId] = clasifyFreeSpace(freeSpace, PAGE_SIZE);
}

void FreeSpaceManager::save()
{
    std::ofstream file(filePath, std::ios::binary);
    if (!file)
    {
        std::cerr << "Could not open fsm file!" << std::endl;
        return;
    }

    file.seekp(0, std::ios::beg);
    int size = fsm.size();
    file.write(reinterpret_cast<char *>(&size), sizeof(int));
    file.write(reinterpret_cast<char *>(fsm.data()), sizeof(FreeSpaceTag) * size);
}

int FreeSpaceManager::findPageWithFreeSpace()
{
    for (int i = 0; i < fsm.size(); ++i)
    {
        if (fsm[i] <= FreeSpaceTag::MEDIUM)
        {
            return i;
        }
    }
    return -1;
}

void FreeSpaceManager::growToPage(int pageId)
{
    if (pageId >= fsm.size())
    {
        fsm.resize(pageId + 1, FreeSpaceTag::EMPTY);
    }
}
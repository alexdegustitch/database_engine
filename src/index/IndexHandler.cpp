#include "IndexHandler.h"

IndexHandler::IndexHandler()
{
}

IndexHandler &IndexHandler::getInstance()
{
    static IndexHandler instance;
    return instance;
}
void IndexHandler::loadIndex(std::string fullName, int maxKeys)
{
    std::string fileName = "meta/indexes/" + fullName + ".idx";
    if (fileToIndex.find(fullName) == fileToIndex.end())
    {
        fileToIndex[fullName] = new BPlusTree(fileName, maxKeys);
    }
}

void IndexHandler::insertIntoIndex(std::string file, int key, uint64_t pageId, uint64_t slotIdx)
{
    if (fileToIndex.find(file) == fileToIndex.end())
    {
        std::cout << file << std::endl;
        std::cerr << "Cannot find index file!" << std::endl;
        return;
    }
    fileToIndex[file]->insert(key, pageId, slotIdx);
}

int IndexHandler::deleteFromIndex(std::string file, int key)
{
    if (fileToIndex.find(file) == fileToIndex.end())
    {
        std::cerr << "Cannot find index file!" << std::endl;
        return -1;
    }
    return fileToIndex[file]->deleteKey(key);
}

int IndexHandler::deleteRangeFromIndex(std::string file, int keyStart, int keyEnd)
{
    if (fileToIndex.find(file) == fileToIndex.end())
    {
        std::cerr << "Cannot find index file!" << std::endl;
        return -1;
    }
    return fileToIndex[file]->deleteRangeOfKeys(keyStart, keyEnd);
}

std::vector<std::pair<uint64_t, uint64_t>> IndexHandler::searchFromIndex(std::string file, int key)
{
    if (fileToIndex.find(file) == fileToIndex.end())
    {
        std::cerr << "Cannot find index file!" << std::endl;
        return std::vector<std::pair<uint64_t, uint64_t>>{};
    }
    return fileToIndex[file]->search(key);
}

std::vector<std::pair<uint64_t, uint64_t>> IndexHandler::getAllFromIndex(std::string file)
{
    if (fileToIndex.find(file) == fileToIndex.end())
    {
        std::cerr << "Cannot find index file!" << std::endl;
        return std::vector<std::pair<uint64_t, uint64_t>>{};
    }
    fileToIndex[file]->getAllLeaves();
}

void IndexHandler::deleteAllFromIndex(std::string file)
{
    if (fileToIndex.find(file) == fileToIndex.end())
    {
        std::cerr << "Cannot find index file!" << std::endl;
        return;
    }
    fileToIndex[file]->eraseTree();
}
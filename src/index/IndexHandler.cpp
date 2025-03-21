#include "IndexHandler.h"

IndexHandler::IndexHandler()
{
}

void IndexHandler::loadIndex(std::string fileName, int maxKeys)
{
    if (fileToIndex.find(fileName) == fileToIndex.end())
    {
        fileToIndex[fileName] = new BPlusTree(fileName, maxKeys);
    }
}

void IndexHandler::insertIntoIndex(std::string file, int key, uint64_t pageId, uint64_t slotIdx)
{
    if (fileToIndex.find(file) == fileToIndex.end())
    {
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
        return;
    }
    return fileToIndex[file]->deleteKey(key);
}

int IndexHandler::deleteRangeFromIndex(std::string file, int keyStart, int keyEnd)
{
    if (fileToIndex.find(file) == fileToIndex.end())
    {
        std::cerr << "Cannot find index file!" << std::endl;
        return;
    }
    return fileToIndex[file]->deleteRangeOfKeys(keyStart, keyEnd);
}

std::vector<std::pair<uint64_t, uint64_t>> IndexHandler::searchFromIndex(std::string file, int key)
{
    if (fileToIndex.find(file) == fileToIndex.end())
    {
        std::cerr << "Cannot find index file!" << std::endl;
        return;
    }
    return fileToIndex[file]->search(key);
}

std::vector<std::pair<uint64_t, uint64_t>> IndexHandler::getAllFromIndex(std::string file)
{
    if (fileToIndex.find(file) == fileToIndex.end())
    {
        std::cerr << "Cannot find index file!" << std::endl;
        return;
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
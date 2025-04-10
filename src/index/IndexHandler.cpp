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

void IndexHandler::searchFromIndex(std::string file, int key, std::vector<std::pair<uint64_t, uint64_t>> &res)
{
    if (fileToIndex.find(file) == fileToIndex.end())
    {
        std::cerr << "Cannot find index file!" << std::endl;
        res.push_back(std::pair<uint64_t, uint64_t>{});
    }
    for (auto curr : fileToIndex[file]->search(key))
    {
        res.push_back(curr);
    }
}

void IndexHandler::searchRangeStartEndFromIndex(std::string file, int keyStart, COMPARISON_OP startOp, int keyEnd, COMPARISON_OP endOp, std::vector<std::pair<uint64_t, uint64_t>> &res)
{
    if (fileToIndex.find(file) == fileToIndex.end())
    {
        std::cerr << "Cannot find index file!" << std::endl;
        res.push_back(std::pair<uint64_t, uint64_t>{});
    }
    for (auto curr : fileToIndex[file]->searchRangeStartEnd(keyStart, startOp, keyEnd, endOp))
    {
        res.push_back(curr);
    }
}

void IndexHandler::searchRangeStartFromIndex(std::string file, int keyStart, COMPARISON_OP startOp, std::vector<std::pair<uint64_t, uint64_t>> &res)
{
    if (fileToIndex.find(file) == fileToIndex.end())
    {
        std::cerr << "Cannot find index file!" << std::endl;
        res.push_back(std::pair<uint64_t, uint64_t>{});
    }
    for (auto curr : fileToIndex[file]->searchRangeStart(keyStart, startOp))
    {
        res.push_back(curr);
    }
}

void IndexHandler::searchRangeEndFromIndex(std::string file, int keyEnd, COMPARISON_OP endOp, std::vector<std::pair<uint64_t, uint64_t>> &res)
{
    if (fileToIndex.find(file) == fileToIndex.end())
    {
        std::cerr << "Cannot find index file!" << std::endl;
        res.push_back(std::pair<uint64_t, uint64_t>{});
    }
    for (auto curr : fileToIndex[file]->searchRangeEnd(keyEnd, endOp))
    {
        res.push_back(curr);
    }
}

void IndexHandler::getAllFromIndex(std::string file, std::vector<std::pair<uint64_t, uint64_t>> &res)
{
    if (fileToIndex.find(file) == fileToIndex.end())
    {
        std::cerr << "Cannot find index file!" << std::endl;
        res.push_back(std::pair<uint64_t, uint64_t>{});
    }

    for (auto curr : fileToIndex[file]->getAllLeaves())
    {
        res.push_back(curr);
    }
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
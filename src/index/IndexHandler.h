#ifndef INDEX_HANDLER_H
#define INDEX_HANDLER_H

#include <unordered_map>
#include <string>
#include <vector>
#include "../bplustree/BPlusTree.h"

class IndexHandler
{
public:
    IndexHandler();
    static IndexHandler &getInstance();
    void loadIndex(std::string fileName, int maxKeys);
    void insertIntoIndex(std::string file, int key, uint64_t pageId, uint64_t slotIdx);
    int deleteFromIndex(std::string file, int key);
    int deleteRangeFromIndex(std::string file, int keyStart, int keyEnd);
    std::vector<std::pair<uint64_t, uint64_t>> searchFromIndex(std::string file, int key);
    std::vector<std::pair<uint64_t, uint64_t>> getAllFromIndex(std::string file);
    void deleteAllFromIndex(std::string file);

private:
    std::unordered_map<std::string, BPlusTree *> fileToIndex;
};

#endif
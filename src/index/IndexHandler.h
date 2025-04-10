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
    void searchFromIndex(std::string file, int key, std::vector<std::pair<uint64_t, uint64_t>> &res);
    void searchRangeStartEndFromIndex(std::string file, int keyStart, COMPARISON_OP startOp, int keyEnd, COMPARISON_OP endOp, std::vector<std::pair<uint64_t, uint64_t>> &res);
    void searchRangeStartFromIndex(std::string file, int keyStart, COMPARISON_OP startOp, std::vector<std::pair<uint64_t, uint64_t>> &res);
    void searchRangeEndFromIndex(std::string file, int keyEnd, COMPARISON_OP endOp, std::vector<std::pair<uint64_t, uint64_t>> &res);
    void getAllFromIndex(std::string file, std::vector<std::pair<uint64_t, uint64_t>> &res);
    void deleteAllFromIndex(std::string file);

private:
    std::unordered_map<std::string, BPlusTree *> fileToIndex;
};

#endif
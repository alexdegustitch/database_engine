#ifndef INDEX_MANAGER_H
#define INDEX_MANAGER_H

#include "Node.h"

struct IndexFileHeader
{
    uint64_t rootOffset;     // 8 bytes
    uint64_t freeListOffset; // 8 bytes
    uint32_t maxKeys;        // 4 bytes
};

class IndexManager
{
private:
public:
    static void writeNode(std::fstream &file, uint64_t offset, Node *node, int maxKeys);
    static Node *readNode(std::fstream &file, uint64_t offset, int maxKeys);
    static void writeRootOffset(std::fstream &file, uint64_t offset);
    static uint64_t readRootOffset(std::fstream &file);
    static uint64_t getFreeListOffset(std::fstream &file);
    static void initializeIndexFile(std::fstream &file, int maxKeys);
    static IndexFileHeader readIndexHeader(std::fstream &file);
};

#endif
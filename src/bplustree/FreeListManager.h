#ifndef FREE_LIST_MANAGER_H
#define FREE_LIST_MANAGER_H

#include "IndexManager.h"
#include <fstream>
#include <vector>
#include <cstdint>
#include <iostream>

#define MAX_FREE_NODES 1024 // Max free node offsets to store

struct FreeList
{
    uint64_t freeNodes[MAX_FREE_NODES];
    uint32_t freeNodeCount = 0;
};

class FreeListManager
{
public:
    static FreeList readFreeList(std::fstream &file, uint64_t offset)
    {
        file.seekg(offset, std::ios::beg);
        FreeList freeList;
        file.read(reinterpret_cast<char *>(&freeList), sizeof(FreeList));
        return freeList;
    }

    static void writeFreeList(std::fstream &file, FreeList &freeList, uint64_t offset)
    {
        file.seekp(offset, std::ios::beg);
        file.write(reinterpret_cast<char *>(&freeList), sizeof(FreeList));
        file.flush();
    }

    static uint64_t allocateNode(std::fstream &file)
    {
        if (!file)
        {
            std::cout << "Something is wrong 1" << std::endl;
        }
        uint64_t freeListOffset = IndexManager::getFreeListOffset(file);
        FreeList freeList = readFreeList(file, freeListOffset);
        if (!file)
        {
            std::cout << "Something is wrong 2" << std::endl;
        }
        std::cout << "FreeList is read!" << std::endl;
        file.seekp(0, std::ios::end);
        uint64_t newOffset = file.tellp();
        std::cout << "NewOffset is read! " << newOffset << std::endl;
        uint64_t rootOffset = IndexManager::readRootOffset(file);
        std::cout << "Root is read! " << rootOffset << std::endl;
        if (freeList.freeNodeCount > 0)
        {
            uint64_t offset = freeList.freeNodes[--freeList.freeNodeCount];
            writeFreeList(file, freeList, freeListOffset);
            if (rootOffset == 0)
            {
                IndexManager::writeRootOffset(file, offset);
            }
            std::cout << "FreeList is not empty!" << std::endl;
            return offset;
        }
        if (rootOffset == 0)
        {
            std::cout << "FreeList is empty!" << std::endl;
            IndexManager::writeRootOffset(file, newOffset);
        }
        return newOffset; // Append at the end
    }

    static void freeNode(std::fstream &file, uint64_t offset)
    {
        uint64_t freeListOffset = IndexManager::getFreeListOffset(file);
        FreeList freeList = readFreeList(file, freeListOffset);
        if (freeList.freeNodeCount < MAX_FREE_NODES)
        {
            freeList.freeNodes[freeList.freeNodeCount++] = offset;
            writeFreeList(file, freeList, freeListOffset);
        }
    }
};

#endif

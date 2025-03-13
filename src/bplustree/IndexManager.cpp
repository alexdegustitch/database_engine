#include "IndexManager.h"
#include "InternalNode.h"
#include "LeafNode.h"
#include "FreeListManager.h"
#include <fstream>
#include <iostream>

void IndexManager::writeNode(std::fstream &file, uint64_t offset, Node *node, int maxKeys)
{
    int effectiveMaxKeys = maxKeys + 1;
    const std::streamsize fixedSize = 21 + 4 * effectiveMaxKeys + 16 * effectiveMaxKeys + 8;

    file.seekp(0, std::ios::end);
    std::cout << "IN WRITE NODE: " << "TELLP: " << file.tellp() << " AND OFFSET IS: " << offset << std::endl;
    if (file.tellp() <= offset)
    {
        std::cout << "WRITE END OF FILE " << std::endl;
        file.seekp(0, std::ios::end);
    }
    else
    {
        std::cout << "WRITE ON OFFSET " << offset << std::endl;
        file.seekp(offset, std::ios::beg);
    }

    // Record the starting position.
    std::streampos startPos = file.tellp();

    file.write(reinterpret_cast<char *>(&node->isLeaf), sizeof(bool));
    file.write(reinterpret_cast<char *>(&offset), sizeof(uint64_t));       // ✅ Store node offset
    file.write(reinterpret_cast<char *>(&node->parent), sizeof(uint64_t)); // ✅ Store parent offset

    uint32_t numKeys = node->keys.size();
    file.write(reinterpret_cast<char *>(&numKeys), sizeof(uint32_t));
    file.write(reinterpret_cast<char *>(node->keys.data()), numKeys * sizeof(int));
    /*for (size_t i = numKeys; i < maxKeys; ++i)
     {
         int pad = 0;
         file.write(reinterpret_cast<char *>(&pad), sizeof(int));
     }*/
    if (node->isLeaf)
    {
        std::cout << "WRITE NODE IS LEAF " << std::endl;
        LeafNode *leaf = static_cast<LeafNode *>(node);
        if (leaf->dataReference.empty())
        {
            std::cout << "Error: leaf->dataReference is empty!" << std::endl;
        }
        file.write(reinterpret_cast<char *>(leaf->dataReference.data()), numKeys * sizeof(std::pair<uint64_t, uint64_t>));
        /*for (size_t i = numKeys; i < maxKeys; ++i)
        {
            std::pair<uint64_t, uint64_t> pad = {0, 0};
            file.write(reinterpret_cast<char *>(&pad), sizeof(std::pair<uint64_t, uint64_t>));
        }*/
        file.write(reinterpret_cast<char *>(&leaf->next), sizeof(uint64_t)); // ✅ Store next leaf offset
        std::cout << "WRITE NODE IS LEAF END" << std::endl;
    }
    else
    {
        std::cout << "WRITE NODE IS INTERNAL " << std::endl;
        InternalNode *internal = static_cast<InternalNode *>(node);
        uint32_t numChildren = internal->children.size();
        file.write(reinterpret_cast<char *>(&numChildren), sizeof(uint32_t));
        file.write(reinterpret_cast<char *>(internal->children.data()), numChildren * sizeof(uint64_t)); // ✅ Store child offsets
        /*for (size_t i = numKeys; i < maxKeys + 1; ++i)
        {
            u_int64_t pad = 0;
            file.write(reinterpret_cast<char *>(&pad), sizeof(uint64_t));
        }*/
        std::cout << "WRITE NODE IS INTERNAL END " << std::endl;
    }
    // Calculate how many bytes have been written so far.
    std::streampos currentPos = file.tellp();
    std::streamsize bytesWritten = currentPos - startPos;

    // Calculate the padding needed to reach the fixed node size.
    std::streamsize padBytes = fixedSize - bytesWritten;
    if (padBytes > 0)
    {
        std::vector<char> zeroPad(padBytes, 0);
        file.write(zeroPad.data(), padBytes);
    }
    file.flush();
}

Node *IndexManager::readNode(std::fstream &file, uint64_t offset, int maxKeys)
{
    maxKeys++;
    if (offset == 0)
    {
        return nullptr;
    }
    file.seekg(offset, std::ios::beg);

    bool isLeaf;
    file.read(reinterpret_cast<char *>(&isLeaf), sizeof(bool));
    uint64_t storedOffset;
    file.read(reinterpret_cast<char *>(&storedOffset), sizeof(uint64_t)); // ✅ Read stored offset
    if (storedOffset != offset)
    {
        std::cout << "ROOT IS: " << IndexManager::readRootOffset(file) << " !!" << std::endl;
        std::cerr << "Error offset mismatch! Expected " << offset << " but found " << storedOffset << " !" << std::endl;
        return nullptr;
    }
    Node *node = isLeaf ? static_cast<Node *>(new LeafNode(offset)) : static_cast<Node *>(new InternalNode(offset));
    node->isLeaf = isLeaf;
    node->offset = storedOffset;                                          // ✅ Restore node offset
    file.read(reinterpret_cast<char *>(&node->parent), sizeof(uint64_t)); // ✅ Restore parent offset
    uint32_t numKeys;
    file.read(reinterpret_cast<char *>(&numKeys), sizeof(uint32_t));
    node->keys.resize(numKeys);
    file.read(reinterpret_cast<char *>(node->keys.data()), numKeys * sizeof(int));
    // std::streamoff bytesToSkip = (maxKeys - numKeys) * sizeof(int);
    // file.seekg(bytesToSkip, std::ios::cur);
    if (isLeaf)
    {
        LeafNode *leaf = static_cast<LeafNode *>(node);
        leaf->dataReference.resize(numKeys);
        file.read(reinterpret_cast<char *>(leaf->dataReference.data()), numKeys * sizeof(std::pair<uint64_t, uint64_t>));
        // bytesToSkip = (maxKeys - numKeys) * sizeof(std::pair<uint64_t, uint64_t>);
        // file.seekg(bytesToSkip, std::ios::cur);
        file.read(reinterpret_cast<char *>(&leaf->next), sizeof(uint64_t)); // ✅ Read next leaf offset
    }
    else
    {
        InternalNode *internal = static_cast<InternalNode *>(node);
        uint32_t numChildren;
        file.read(reinterpret_cast<char *>(&numChildren), sizeof(uint32_t));
        internal->children.resize(numChildren);
        file.read(reinterpret_cast<char *>(internal->children.data()), numChildren * sizeof(uint64_t)); // ✅ Read child offsets
    }
    return node;
}
void IndexManager::writeRootOffset(std::fstream &file, uint64_t offset)
{
    file.seekp(0, std::ios::beg);
    file.write(reinterpret_cast<char *>(&offset), sizeof(uint64_t));
    file.flush();
}

uint64_t IndexManager::readRootOffset(std::fstream &file)
{
    if (!file.is_open())
    {
        std::cout << "File not opened" << std::endl;
    }
    uint64_t offset;

    file.seekg(0, std::ios::beg);
    file.read(reinterpret_cast<char *>(&offset), sizeof(uint64_t));

    if (!file)
    {
        std::cout << "Error reading file!" << std::endl;
    }
    std::cout << "Root is being read: " << offset << std::endl;
    return offset;
}

void IndexManager::initializeIndexFile(std::fstream &file, int maxKeys)
{
    file.seekp(0, std::ios::end);
    if (file.tellp() == 0)
    {
        std::cout << "File init!" << std::endl;
        IndexFileHeader header = {0, 0, static_cast<uint32_t>(maxKeys)};
        file.seekp(0, std::ios::beg);
        file.write(reinterpret_cast<char *>(&header), sizeof(IndexFileHeader));
        file.seekp(0, std::ios::end);
        uint64_t offset = file.tellp();
        FreeList freeList = {};
        freeList.freeNodeCount = 0; // Initially empty
        file.write(reinterpret_cast<char *>(&freeList), sizeof(FreeList));
        header.freeListOffset = offset;
        file.seekp(0, std::ios::beg);
        file.write(reinterpret_cast<char *>(&header), sizeof(IndexFileHeader));
        file.flush();
    }
}

IndexFileHeader IndexManager::readIndexHeader(std::fstream &file)
{
    file.seekg(0, std::ios::beg);
    IndexFileHeader header;
    file.read(reinterpret_cast<char *>(&header), sizeof(IndexFileHeader));
    return header;
}

uint64_t IndexManager::getFreeListOffset(std::fstream &file)
{
    IndexFileHeader header = readIndexHeader(file);
    return header.freeListOffset;
}
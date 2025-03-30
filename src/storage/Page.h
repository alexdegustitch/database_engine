#ifndef PAGE_H
#define PAGE_H

#include <iostream>
#include <vector>

const int PAGE_SIZE = 4096;

struct PageHeader
{
    int pageId;
    int numRecords;
    uint64_t freeSpaceOffset;
};

class Page
{
public:
    Page();
    int insertRecord(const std::vector<char> &record);
    bool readRecord(int slotIndex, std::vector<char> &record) const;
    bool deleteRecord(int slotIndex);
    char *getData() { return data; };
    void loadFromFile(const char *diskData);
    void writeToFile(char *fileData);
    uint64_t getFreeSpace();
    void setPageID(int id) { header.pageId = id; }
    void markDirty() { dirty = true; };
    void clearDirty() { dirty = false; };
    bool isDirty() { return dirty; };

private:
    PageHeader header;
    bool dirty = false;
    std::vector<uint64_t> slotDirectory;
    char data[PAGE_SIZE - sizeof(PageHeader)];
};

#endif
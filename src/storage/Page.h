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
    bool insertRecord(const std::vector<char> &record, uint64_t recordOffset);
    bool readRecord(int slotIndex, std::vector<char> &record) const;
    bool deleteRecord(int slotIndex);
    char *getData() { return data; };
    void loadFromFile(const char *diskData);

private:
    PageHeader header;
    std::vector<uint64_t> slotDirectory;
    char data[PAGE_SIZE - sizeof(PageHeader)];
};

#endif
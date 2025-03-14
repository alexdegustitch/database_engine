
#include "Page.h"

Page::Page()
{
    header.pageId = -1;
    header.numRecords = 0;
    header.freeSpaceOffset = PAGE_SIZE - sizeof(header);
};

bool Page::insertRecord(const std::vector<char> &record, uint64_t offset)
{
    int recordSize = record.size();

    // check if there is enough space
    if (header.freeSpaceOffset - recordSize < sizeof(PageHeader) + (header.numRecords + 1) * sizeof(int))
    {
        return false; // there is not enough space
    }

    header.freeSpaceOffset -= recordSize;
    header.numRecords++;

    uint64_t recordOffset = header.freeSpaceOffset;

    memcpy(data + recordOffset, record.data(), recordSize);

    slotDirectory.push_back(recordOffset);

    return true;
}

bool Page::readRecord(int slotIndex, std::vector<char> &record) const
{
    if (slotIndex >= header.numRecords && slotDirectory[slotIndex] != -1)
    {
        return false;
    }

    int recordSize = slotIndex == 0 ? PAGE_SIZE - slotDirectory[0] : slotDirectory[slotIndex - 1] - slotDirectory[slotIndex];

    uint64_t recordOffset = slotDirectory[slotIndex];

    record.resize(recordSize);
    memcpy(record.data(), data + recordOffset, recordSize);
    return true;
}

bool Page::deleteRecord(int slotIndex)
{
    if (slotIndex >= header.numRecords)
    {
        return false;
    }

    slotDirectory[slotIndex] = -1;
    return true;
}

void Page::loadFromFile(const char *fileData)
{
    memcpy(&header, fileData, sizeof(PageHeader));
    memcpy(data, fileData + sizeof(header), PAGE_SIZE - sizeof(PageHeader));
}
#include "Page.h"
#include <iomanip>
Page::Page()
{
    header.pageId = -1;
    header.numRecords = 0;
    header.freeSpaceOffset = PAGE_SIZE - sizeof(header);
    memset(data, 0, PAGE_SIZE);
};

void printHex(const char *buffer, size_t size)
{
    for (size_t i = 0; i < size; ++i)
    {
        std::cout << std::hex << std::setw(2) << std::setfill('0')
                  << (static_cast<unsigned int>(static_cast<unsigned char>(buffer[i]))) << " ";
    }
    std::cout << std::dec << std::endl; // reset to decimal
}

int Page::insertRecord(const std::vector<char> &record)
{
    int recordSize = record.size();

    // check if there is enough space
    if (header.freeSpaceOffset - recordSize < sizeof(PageHeader) + (header.numRecords + 1) * sizeof(Slot))
    {
        std::cout << "There is no enough space!" << std::endl;
        return false; // there is not enough space
    }

    header.freeSpaceOffset -= recordSize;
    header.numRecords++;

    int recordOffset = header.freeSpaceOffset;

    /* std::cout << "[record.data() as hex] ";
     printHex(record.data(), recordSize);

     std::cout << "[record.data() as text] ";
     std::cout.write(record.data(), recordSize);
     std::cout << std::endl;*/

    memcpy(data + recordOffset, record.data(), recordSize);
    int slotIdx = slotDirectory.size();
    Slot s = {recordOffset, recordSize};
    slotDirectory.push_back(s);
    dirty = true;
    return slotIdx;
}

bool Page::readRecord(int slotIndex, std::vector<char> &record) const
{
    std::cout << "I am in read record!" << std::endl;
    if (slotIndex >= header.numRecords || slotDirectory[slotIndex].offset == -1)
    {
        std::cout << "Slot idx: " << slotIndex << ", num record: " << header.numRecords << std::endl;
        return false;
    }

    std::cout << "Slot idx: " << slotIndex << ", num record: " << header.numRecords << std::endl;
    int recordSize = slotDirectory[slotIndex].length;
    uint64_t recordOffset = slotDirectory[slotIndex].offset;
    std::cout << "Record offset: " << recordOffset << " record size: " << recordSize << std::endl;
    record.resize(recordSize);
    memcpy(record.data(), data + recordOffset, recordSize);
    return true;
}

bool Page::deleteRecord(int slotIndex)
{
    if (slotIndex >= header.numRecords || slotDirectory[slotIndex].offset == -1)
    {
        return false;
    }

    dirty = true;
    slotDirectory[slotIndex].offset = -1;
    return true;
}

void Page::loadFromFile(const char *fileData)
{
    memcpy(&header, fileData, sizeof(PageHeader));
    slotDirectory.resize(header.numRecords);
    memcpy(slotDirectory.data(), fileData + sizeof(PageHeader), sizeof(Slot) * header.numRecords);
    memcpy(data + header.freeSpaceOffset, fileData + header.freeSpaceOffset, PAGE_SIZE - header.freeSpaceOffset);

    dirty = false;
}

void Page::writeToFile(char *fileData)
{
    memcpy(fileData, &header, sizeof(PageHeader));
    memcpy(fileData + sizeof(PageHeader), slotDirectory.data(), sizeof(Slot) * slotDirectory.size());
    memcpy(fileData + header.freeSpaceOffset, data + header.freeSpaceOffset, PAGE_SIZE - header.freeSpaceOffset);
}

uint64_t Page::getFreeSpace()
{
    return header.freeSpaceOffset - (sizeof(PageHeader) + (header.numRecords + 1) * sizeof(Slot));
}
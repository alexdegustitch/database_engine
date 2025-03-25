#include "BufferManager.h"

BufferManager::BufferManager()
{
    pool.setFlushCallback([this](std::string &tableName, int id)
                          {
        tableName = pageToTable[id];
        this->flushPage(tableName, id); });

    pool.setFetchPageCallback([this](std::string &tableName, int id)
                              {
        tableName = pageToTable[id];
        return this->fetchPage(tableName, id); });
}

BufferManager &BufferManager::getInstance()
{
    static BufferManager instance;
    return instance;
}

Page *BufferManager::fetchPage(const std::string &tableName, int id)
{
    Page *p = pool.getPage(id);
    if (p == nullptr)
    {
        p = new Page();
        readPageFromFile(tableName, id, p);
        pool.addPage(id, tableName, p);
    }
    return p;
}

void BufferManager::unpinPage(int id)
{
    pool.releasePage(id);
}

void BufferManager::flushPage(const std::string &tableName, int id)
{

    Page *page = pool.getPage(id);
    if (page != nullptr && page->isDirty())
    {
        std::fstream &file = getFile(tableName);
        writePageToFile(tableName, id, page);
        page->clearDirty();
    }
}

void BufferManager::flashAllPages()
{
    for (auto &[id, _] : pool.getPages())
    {
        if (pageToTable.find(id) != pageToTable.end())
        {
            flushPage(pageToTable[id], id);
        }
    }
}

std::fstream &BufferManager::getFile(std::string tableName)
{
    if (openFiles.find(tableName) == openFiles.end())
    {
        openFiles[tableName] = std::fstream("data/" + tableName + ".dat", std::ios::out | std::ios::binary);
        if (!openFiles[tableName])
        {
            openFiles[tableName].open("data/" + tableName + ".dat", std::ios::out | std::ios::binary);
            openFiles[tableName].close();
            openFiles[tableName].open("data/" + tableName + ".dat", std::ios::in | std::ios::out | std::ios::binary);
        }
    }
    return openFiles[tableName];
}

void BufferManager::readPageFromFile(const std::string &tableName, int id, Page *p)
{
    std::fstream &file = getFile(tableName);
    if (!file)
    {
        std::cerr << "Could not read data from the file!" << std::endl;
    }
    file.seekg(PAGE_SIZE * id);
    file.read(p->getData(), PAGE_SIZE);
}

void BufferManager::writePageToFile(const std::string &tableName, int id, Page *p)
{
    std::fstream &file = getFile(tableName);
    file.seekp(id * PAGE_SIZE);
    file.write(p->getData(), PAGE_SIZE);

    if (!file)
    {
        std::cerr << "Could not write data to the file!" << std::endl;
    }
}
#include "BufferManager.h"

BufferManager::BufferManager()
{
}

Page *BufferManager::fetchPage(std::string tableName, int id)
{
    Page *p = pool.getPage(id);
}

void BufferManager::unpinPage(int id)
{
    pool.releasePage(id);
}

void BufferManager::flushPage(std::string tableName, int id)
{
    std::fstream &file = openFile(tableName);
    pool.flushPage(id);
}

void BufferManager::flashAllPages()
{
    pool.flushAllPages();
}

std::fstream &BufferManager::openFile(std::string tableName)
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

void BufferManager::readPageFromFile(std::string tableName, int id, Page *p)
{
}

void BufferManager::writePageToFile(std::string tableName, int id, Page *p)
{
}
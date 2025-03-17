#ifndef BUFFER_MANAGER_H
#define BUFFER_MANAGER_H

#include "BufferPool.h"
#include <string>
#include <fstream>

class BufferManager
{
public:
    BufferManager();
    Page *fetchPage(std::string tableName, int id);
    void unpinPage(int id);
    void flushPage(std::string tableName, int id);
    void flashAllPages();

private:
    BufferPool pool;
    std::unordered_map<std::string, std::fstream> openFiles;

    std::fstream &openFile(std::string tableName);

    void readPageFromFile(std::string tableName, int id, Page *p);
    void writePageToFile(std::string tableName, int id, Page *p);
};
#endif
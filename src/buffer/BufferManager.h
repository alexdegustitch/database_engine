#ifndef BUFFER_MANAGER_H
#define BUFFER_MANAGER_H

#include "BufferPool.h"
#include <string>
#include <fstream>

class BufferManager
{
public:
    BufferManager();
    static BufferManager &getInstance();
    Page *fetchPage(const std::string &tableName, int id);
    void unpinPage(int id);
    void flushPage(const std::string &tableName, int id);
    void flashAllPages();

private:
    BufferPool pool;
    std::unordered_map<std::string, std::fstream> openFiles;
    std::unordered_map<int, std::string> pageToTable;

    std::fstream &getFile(const std::string &tableName);

    void readPageFromFile(const std::string &tableName, int id, Page *p);
    void writePageToFile(const std::string &tableName, int id, Page *p);
};
#endif
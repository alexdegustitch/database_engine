#ifndef BUFFER_POOL_H
#define BUFFER_POOL_H

#include "Page.h"
#include <list>
#include <fstream>
#include <unordered_map>

const int BUFFER_POOL_SIZE = 10;
const int PREFETCH_SIZE = 2;

struct PageFrame
{
    int pageId;
    Page *page;
    bool used;
};

class BufferPool
{
public:
    BufferPool();
    Page *getPage(int id);
    void addPage(int id, std::string &tableName, Page *p);
    void releasePage(int id);
    void evictPage(std::string &tableName);
    void flushPage(int id);
    void flushAllPages();
    void prefetchPages(int startPage, std::string &tableName, int cnt);

    std::unordered_map<int, PageFrame *> getPages();
    void setFlushCallback(std::function<void(std::string &, int)> callback);
    void setFetchPageCallback(std::function<Page *(std::string &, int)> callback);

private:
    std::unordered_map<int, PageFrame *> map;
    std::vector<PageFrame *> buffer;
    int clock;
    int lastFetchedPage;

    std::function<void(std::string &, int)> flushCallback;
    std::function<Page *(std::string &, int)> fetchPageCallback;
};
#endif
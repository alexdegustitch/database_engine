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
    void releasePage(int id);
    void evictPage();
    void flushPage(int id);
    void flushAllPages();
    void prefetchPages(int startPage, int cnt);

private:
    std::unordered_map<int, PageFrame *> map;
    std::vector<PageFrame *> buffer;
    int clock;
    int lastFetchedPage;
};
#endif
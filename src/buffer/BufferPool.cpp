#include "BufferPool.h"

BufferPool::BufferPool() : clock(0), lastFetchedPage(-1)
{
}

void BufferPool::setFlushCallback(std::function<void(std::string &, int)> callback)
{
    flushCallback = callback;
}

void BufferPool::setFetchPageCallback(std::function<Page *(std::string &, int)> callback)
{
    fetchPageCallback = callback;
}

Page *BufferPool::getPage(int id)
{
    if (map.find(id) != map.end())
    {
        map[id]->used = true;
        return map[id]->page;
    }
    return nullptr;
}

void BufferPool::addPage(int id, std::string &tableName, Page *page)
{
    PageFrame *pFrame = new PageFrame();
    pFrame->page = page;
    pFrame->used = true;
    pFrame->pageId = id;

    if (buffer.size() >= BUFFER_POOL_SIZE)
    {
        evictPage(tableName);
    }
    buffer.push_back(pFrame);

    if (lastFetchedPage != -1 && lastFetchedPage + 1 == id)
    {
        prefetchPages(id + 1, tableName, PREFETCH_SIZE);
    }
    lastFetchedPage = id;
}

void BufferPool::releasePage(int id)
{
    if (map.find(id) != map.end())
    {
        map[id]->used = false;
    }
}

void BufferPool::flushPage(int id)
{
    /*
        if (map.find(id) != map.end())
        {
            Page *page = map[id]->page;
            if (page->isDirty())
            {
                std::ofstream file("", std::ios::binary | std::ios::app);
                if (!file)
                {
                    std::cerr << "Could not open database!" << std::endl;
                    return;
                }
                file.seekp(PAGE_SIZE * id, std::ios::beg);
                file.write(page->getData(), PAGE_SIZE);
                file.close();

                page->clearDirty();
            }
        }*/
}
void BufferPool::flushAllPages()
{ /*
    for (auto &[page_id, _] : map)
    {
        flushPage(page_id);
    }
    */
}

void BufferPool::evictPage(std::string &tableName)
{
    while (buffer[clock]->used)
    {
        buffer[clock]->used = false;
        clock = (clock + 1) % BUFFER_POOL_SIZE;
    }

    if (flushCallback)
    {
        flushCallback(tableName, buffer[clock]->pageId);
    }

    map.erase(buffer[clock]->pageId);

    delete buffer[clock]->page;
    delete buffer[clock];
    buffer.erase(buffer.begin() + clock);
}

void BufferPool::prefetchPages(int startPage, std::string &tableName, int cnt)
{
    for (int i = 0; i < cnt; ++i)
    {
        int pageToGet = startPage + i;
        if (map.find(pageToGet) != map.end())
        {
            if (fetchPageCallback)
            {
                addPage(pageToGet, tableName, fetchPageCallback(tableName, pageToGet));
            }
        }
    }
}

std::unordered_map<int, PageFrame *> BufferPool::getPages()
{
    return map;
}
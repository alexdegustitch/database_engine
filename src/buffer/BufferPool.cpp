#include "BufferPool.h"

BufferPool::BufferPool() : clock(0), lastFetchedPage(-1)
{
}

Page *BufferPool::getPage(int id)
{
    if (map.find(id) != map.end())
    {
        map[id]->used = true;
        return map[id]->page;
    }

    Page *page = new Page();
    PageFrame *pFrame = new PageFrame();
    pFrame->page = page;
    pFrame->used = true;
    pFrame->pageId = id;

    if (buffer.size() >= BUFFER_POOL_SIZE)
    {
        evictPage();
    }
    buffer.push_back(pFrame);

    if (lastFetchedPage != -1 && lastFetchedPage + 1 == id)
    {
        prefetchPages(id + 1, PREFETCH_SIZE);
    }
    lastFetchedPage = id;
    return page;
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
    }
}
void BufferPool::flushAllPages()
{
    for (auto &[page_id, _] : map)
    {
        flushPage(page_id);
    }
}

void BufferPool::evictPage()
{
    while (buffer[clock]->used)
    {
        buffer[clock]->used = false;
        clock = (clock + 1) % BUFFER_POOL_SIZE;
    }

    flushPage(buffer[clock]->pageId);

    map.erase(buffer[clock]->pageId);

    delete buffer[clock]->page;
    delete buffer[clock];
    buffer.erase(buffer.begin() + clock);
}

void BufferPool::prefetchPages(int startPage, int cnt)
{
    for (int i = 0; i < cnt; ++i)
    {
        int pageToGet = startPage + i;
        if (map.find(pageToGet) != map.end())
        {
            getPage(pageToGet);
        }
    }
}

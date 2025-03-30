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
    if (page == nullptr)
    {
        std::cout << "page is nullptr" << std::endl;
    }
    if (page != nullptr && !page->isDirty())
    {
        std::cout << "page is not dirty" << std::endl;
    }
    if (page != nullptr && page->isDirty())
    {
        // std::fstream &file = getFile(tableName);
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

std::fstream &BufferManager::getFile(const std::string &tableName)
{
    // If not already open, open and store the stream
    if (openFiles.find(tableName) == openFiles.end())
    {
        std::string path = "data/data/" + tableName + ".dat";

        // Ensure the file exists (create it if not)
        if (!std::filesystem::exists(path))
        {
            std::ofstream createFile(path, std::ios::binary);
            if (!createFile)
            {
                throw std::runtime_error("Failed to create file: " + path);
            }
            createFile.close();
        }

        // Open the file in read/write binary mode
        std::fstream file(path, std::ios::in | std::ios::out | std::ios::binary);
        int i = 1;
        file.write(reinterpret_cast<char *>(&i), sizeof(int));
        file.flush();
        if (!file.is_open())
        {
            throw std::runtime_error("Failed to open file: " + path);
        }

        std::cout << "[getFile] Opened file: " << path << std::endl;

        // Store the open file stream using move semantics
        openFiles.emplace(tableName, std::move(file));
    }

    return openFiles.at(tableName);
}

void BufferManager::readPageFromFile(const std::string &tableName, int id, Page *p)
{
    std::string path = "data/data/" + tableName + ".dat";
    std::filesystem::create_directories("data/data");

    // Create file if it doesn't exist
    if (!std::filesystem::exists(path))
    {
        std::ofstream(path, std::ios::binary).close();
    }

    // Open file for reading & writing in binary mode
    std::ifstream file(path, std::ios::in | std::ios::out | std::ios::binary);
    if (!file.is_open())
    {
        throw std::runtime_error("Failed to open file for writing: " + path);
    }
    file.seekg(PAGE_SIZE * id);
    file.read(p->getData(), PAGE_SIZE);
}

void BufferManager::writePageToFile(const std::string &tableName, int id, Page *p)
{
    std::string path = "data/data/" + tableName + ".dat";
    std::filesystem::create_directories("data/data");

    // Create file if it doesn't exist
    if (!std::filesystem::exists(path))
    {
        std::ofstream(path, std::ios::binary).close();
    }

    // Open file for reading & writing in binary mode
    std::ofstream file(path, std::ios::in | std::ios::out | std::ios::binary);
    if (!file.is_open())
    {
        throw std::runtime_error("Failed to open file for writing: " + path);
    }
    // Seek to the correct page offset
    file.seekp(id * PAGE_SIZE);

    // Create buffer
    char buffer[PAGE_SIZE];
    p->writeToFile(buffer);

    // Write buffer
    file.write(buffer, PAGE_SIZE);
    file.flush();
    std::cout << "file written" << std::endl;
    if (!file)
    {
        std::cerr << "Could not write data to the file!" << std::endl;
    }
}
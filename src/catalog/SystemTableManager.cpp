#include "SystemTableManager.h"

int SystemTableManager::getNextTableId()
{
    std::ifstream file(tablesFile, std::ios::binary);

    file.seekg(0, std::ios::end);
    uint64_t offset = file.tellg();
    if (offset == 0)
    {
        return 1;
    }

    offset -= sizeof(TableSchema);

    int id;
    file.read(reinterpret_cast<char *>(&id), sizeof(int));
    file.close();
    return id + 1;
}

int SystemTableManager::getNextColumnId()
{
    std::ifstream file(colsFile, std::ios::binary);

    file.seekg(0, std::ios::end);
    uint64_t offset = file.tellg();
    if (offset == 0)
    {
        return 1;
    }

    offset -= sizeof(ColumnSchema);

    int id;
    file.read(reinterpret_cast<char *>(&id), sizeof(int));
    file.close();
    return id + 1;
}

SystemTableManager::SystemTableManager(const std::string &tablesFile, const std::string &colsFile) : tablesFile(tablesFile), colsFile(colsFile) {}

void SystemTableManager::createSystemTables()
{
    std::ofstream tbFile(tablesFile, std::ios::binary | std::ios::app);
    if (!tbFile)
    {
        throw std::runtime_error("Could not open database file!");
    }
    std::ofstream clFile(colsFile, std::ios::binary | std::ios::app);
    if (!clFile)
    {
        throw std::runtime_error("Could not open database file!");
    }
    tbFile.close();
    clFile.close();
}

int SystemTableManager::insertTableSchema(const std::string &tableName, std::vector<ColumnSchema> &cols)
{
    std::ofstream tbFile(tablesFile, std::ios::binary | std::ios::app);
    if (!tbFile)
    {
        throw std::runtime_error("Could not open database file!");
    }
    std::ofstream clFile(colsFile, std::ios::binary | std::ios::app);
    if (!clFile)
    {
        throw std::runtime_error("Could not open database file!");
    }

    int tableId = getNextTableId();

    TableSchema tbSchema = {tableId, "", cols.size()};
    strncpy(tbSchema.tableName, tableName.c_str(), 32);

    tbFile.write(reinterpret_cast<char *>(&tbSchema), sizeof(TableSchema));
    tbFile.close();

    int colId = getNextColumnId();
    for (const ColumnSchema &col : cols)
    {

        ColumnSchema clSchema = {colId, tableId, "", "", col.size, col.isVariable};
        strncpy(clSchema.columnName, col.columnName, 32);
        strncpy(clSchema.type, col.type, 16);
        clFile.write(reinterpret_cast<char *>(&clSchema), sizeof(ColumnSchema));
        ++colId;
    }
    clFile.close();
    return tableId;
}

TableSchema SystemTableManager::getTableSchema(const std::string &tableName, std::vector<ColumnSchema> &cols)
{
    std::ifstream tbFile(tablesFile, std::ios::binary);
    if (!tbFile)
    {
        throw std::runtime_error("Could not open database file!");
    }
    tbFile.seekg(0, std::ios::beg);

    TableSchema tbSchema;
    bool foundTable = false;
    while (tbFile.read(reinterpret_cast<char *>(&tbSchema), sizeof(TableSchema)))
    {
        if (tbSchema.tableName == tableName)
        {
            foundTable = true;
            break;
        }
    }
    tbFile.close();
    if (!foundTable)
    {
        return {};
    }

    std::ifstream clFile(colsFile, std::ios::binary);
    if (!clFile)
    {
        throw std::runtime_error("Could not open database file!");
    }
    clFile.seekg(0, std::ios::beg);

    cols.clear();
    int cnt = 0;

    ColumnSchema clSchema;
    while (cnt < tbSchema.numColumns && clFile.read(reinterpret_cast<char *>(&clSchema), sizeof(ColumnSchema)))
    {
        if (clSchema.tableId == tbSchema.tableId)
        {
            cnt++;
            cols.push_back(clSchema);
            break;
        }
    }
    clFile.close();
    return tbSchema;
}

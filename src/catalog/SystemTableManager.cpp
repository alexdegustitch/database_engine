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
    file.seekg(offset, std::ios::beg);
    int id;
    file.read(reinterpret_cast<char *>(&id), sizeof(int));
    std::cout << "TABLE ID: " << id << std::endl;
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
    file.seekg(offset, std::ios::beg);
    int id;
    file.read(reinterpret_cast<char *>(&id), sizeof(int));
    std::cout << "COLUMN ID: " << id << std::endl;
    file.close();
    return id + 1;
}

int SystemTableManager::getNextIndexId()
{
    std::ifstream file(indexesFile, std::ios::binary);
    file.seekg(0, std::ios::end);
    uint64_t offset = file.tellg();
    if (offset == 0)
    {
        return 1;
    }
    offset -= sizeof(IndexSchema);
    file.seekg(offset, std::ios::beg);
    int id;
    file.read(reinterpret_cast<char *>(&id), sizeof(int));
    std::cout << "INDEX ID: " << id << std::endl;
    file.close();
    return id + 1;
}

SystemTableManager &SystemTableManager::getInstance()
{
    static SystemTableManager instance;
    return instance;
}

SystemTableManager::SystemTableManager()
{
    tablesFile = "data/catalog_tables.dat";
    colsFile = "data/catalog_columns.dat";
    indexesFile = "data/catalog_indexes.dat";
    createSystemTables();
    loadAllSchemas();
}

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

    TableSchema tbSchema = {tableId, "", static_cast<int>(cols.size())};
    strncpy(tbSchema.tableName, tableName.c_str(), 32);

    tbFile.write(reinterpret_cast<char *>(&tbSchema), sizeof(TableSchema));
    tbFile.close();
    tableNameToSchema[tbSchema.tableName] = tbSchema;

    int colId = getNextColumnId();
    for (const ColumnSchema &col : cols)
    {
        ColumnSchema clSchema = {colId, tableId, "", "", col.size, col.isVariable, col.isPrimary, col.isNotNull};
        strncpy(clSchema.columnName, col.columnName, 32);
        strncpy(clSchema.type, col.type, 16);
        clFile.write(reinterpret_cast<char *>(&clSchema), sizeof(ColumnSchema));
        std::string id = std::string(clSchema.columnName) + ":" + std::to_string(clSchema.tableId);
        std::cout << "Insert clmn schema: " << id << std::endl;
        columnNameToSchema[id] = clSchema;
        columnIdToName[colId] = clSchema.columnName;
        columnSchemasForTable[tableId].push_back(clSchema);
        colsInTable[tableId].push_back(clSchema.columnName);
        ++colId;
    }
    clFile.close();
    return tableId;
}

TableSchema &SystemTableManager::getTableSchema(const std::string &tableName, std::vector<ColumnSchema> &cols)
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
        tbSchema = {};
        return tbSchema;
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

int SystemTableManager::insertIndexSchema(const std::string &tableName, const std::string &colName, const std::string &fullName, bool isUnique)
{
    std::ofstream file(indexesFile, std::ios::binary | std::ios::app);
    if (!file)
    {
        throw std::runtime_error("Could not open database file!");
    }

    int id = getNextIndexId();
    int tableId = tableNameToSchema[tableName].tableId;
    int columnId = columnNameToSchema[colName + ":" + std::to_string(tableId)].columnId;
    IndexSchema indexSchema;
    indexSchema.columnId = columnId;
    indexSchema.indexId = id;
    indexSchema.tableId = tableId;
    indexSchema.isUnique = isUnique;
    strncpy(indexSchema.indexName, fullName.c_str(), sizeof(fullName));

    file.write(reinterpret_cast<char *>(&indexSchema), sizeof(IndexSchema));
    file.close();

    indexNameToSchema[fullName] = indexSchema;
    indexesForTable[tableId].push_back({indexSchema.indexName, indexSchema.columnId});
    return id;
}

void SystemTableManager::loadTableSchema()
{
    std::ifstream file(tablesFile, std::ios::binary);

    TableSchema tb;
    while (file.read(reinterpret_cast<char *>(&tb), sizeof(TableSchema)))
    {
        tableNameToSchema[tb.tableName] = tb;
        tableIdToName[tb.tableId] = tb.tableName;
    }
    file.close();
}

void SystemTableManager::loadColumnSchema()
{
    std::ifstream file(colsFile, std::ios::binary);

    ColumnSchema cl;
    while (file.read(reinterpret_cast<char *>(&cl), sizeof(ColumnSchema)))
    {
        int tableId = cl.tableId;
        std::string fullName = std::string(cl.columnName) + ":" + std::to_string(cl.tableId);
        columnNameToSchema[fullName] = cl;
        columnIdToName[cl.columnId] = cl.columnName;
        colsInTable[tableId].push_back(cl.columnName);
        columnSchemasForTable[tableId].push_back(cl);
    }
    file.close();
}

void SystemTableManager::loadIndexSchema()
{
    std::ifstream file(indexesFile, std::ios::binary);
    IndexSchema idx;
    while (file.read(reinterpret_cast<char *>(&idx), sizeof(IndexSchema)))
    {
        indexNameToSchema[idx.indexName] = idx;
        indexIdToName[idx.indexId] = idx.indexName;
        indexesForTable[idx.tableId].push_back({idx.indexName, idx.columnId});
    }
    file.close();
}

void SystemTableManager::loadAllSchemas()
{
    loadTableSchema();
    loadColumnSchema();
    loadIndexSchema();
}

std::vector<std::string> &SystemTableManager::getColsInTable(const std::string &tableName)
{
    return colsInTable[tableNameToSchema[tableName].tableId];
}

std::vector<ColumnSchema> &SystemTableManager::getAllColumnSchemasForTable(const std::string &tableName)
{
    return columnSchemasForTable[tableNameToSchema[tableName].tableId];
}

std::vector<ColumnSchema> SystemTableManager::getSchemasForColumns(const std::string &tableName, std::vector<std::string> &cols)
{
    for (auto it : columnNameToSchema)
    {
        std::cout << "ColNameSchema: " << it.first << std::endl;
    }
    std::vector<ColumnSchema> res;
    for (std::string &name : cols)
    {
        std::string fullName = name + ":" + std::to_string(tableNameToSchema[tableName].tableId);
        std::cout << fullName << columnNameToSchema[fullName].type << std::endl;
        std::cout << fullName << columnNameToSchema[fullName].columnId << std::endl;
        std::cout << fullName << columnNameToSchema[fullName].columnName << std::endl;
        std::cout << fullName << columnNameToSchema[fullName].size << std::endl;
        std::cout << fullName << columnNameToSchema[fullName].isPrimary << std::endl;
        std::cout << fullName << columnNameToSchema[fullName].isNotNull << std::endl;
        std::cout << fullName << columnNameToSchema[fullName].isVariable << std::endl;
        std::cout << fullName << columnNameToSchema[fullName].tableId << std::endl;
        std::cout << "NEW" << std::endl;
        res.push_back(columnNameToSchema[fullName]);
    }
    return res;
}

std::vector<std::pair<std::string, int>> &SystemTableManager::getAllIndexNamesForTable(const std::string &tableName)
{
    return indexesForTable[tableNameToSchema[tableName].tableId];
}
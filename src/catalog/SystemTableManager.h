#ifndef SYSTEM_TABLE_H
#define SYSTEM_TABLE_H

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>

struct TableSchema
{
    int tableId;
    char tableName[32];
    int numColumns;
};

struct ColumnSchema
{
    int columnId;
    int tableId;
    char columnName[32];
    char type[16];
    int size;
    bool isVariable;
    bool isPrimary;
    bool isNotNull;
};

struct IndexSchema
{
    int indexId;
    int tableId;
    int columnId;
    char indexName[65];
    bool isUnique;
};

class SystemTableManager
{
private:
    std::string tablesFile, colsFile, indexesFile;
    std::unordered_map<std::string, TableSchema> tableNameToSchema;
    std::unordered_map<std::string, ColumnSchema> columnNameToSchema;
    std::unordered_map<std::string, IndexSchema> indexNameToSchema;

    std::unordered_map<int, std::string> tableIdToName, columnIdToName, indexIdToName;

    std::unordered_map<int, std::vector<std::string>> colsInTable;
    std::unordered_map<int, std::vector<ColumnSchema>> columnSchemasForTable;

    std::unordered_map<int, std::vector<std::pair<std::string, int>>> indexesForTable;

    int getNextTableId();
    int getNextColumnId();
    int getNextIndexId();
    SystemTableManager();
    void createSystemTables();

public:
    static SystemTableManager &getInstance();

    SystemTableManager(const SystemTableManager &) = delete;
    SystemTableManager &operator=(const SystemTableManager &) = delete;
    SystemTableManager(SystemTableManager &&) = delete;
    SystemTableManager &operator=(SystemTableManager &&) = delete;

    int insertTableSchema(const std::string &tableName, std::vector<ColumnSchema> &cols);
    TableSchema &getTableSchema(const std::string &tableName, std::vector<ColumnSchema> &cols);
    int insertIndexSchema(const std::string &tableName, const std::string &columnName, IndexSchema &indexSchema, const std::string &fullName);

    void loadAllSchemas();
    void loadTableSchema();
    void loadColumnSchema();
    void loadIndexSchema();

    std::unordered_map<std::string, TableSchema> &getAllTableSchemas() { return tableNameToSchema; }
    std::unordered_map<std::string, ColumnSchema> &getAllColumnSchema() { return columnNameToSchema; }
    std::unordered_map<std::string, IndexSchema> &getAllIndexSchema() { return indexNameToSchema; }

    std::unordered_map<int, std::string> &getTableIdToName() { return tableIdToName; }
    std::unordered_map<int, std::string> &getColumnIdToName() { return columnIdToName; }
    std::unordered_map<int, std::string> &getIndexIdToName() { return indexIdToName; }

    std::vector<std::string> &getColsInTable(const std::string &tableName);
    std::vector<ColumnSchema> &getAllColumnSchemasForTable(const std::string &tableName);
    std::vector<ColumnSchema> getSchemasForColumns(const std::string &tableName, std::vector<std::string> &cols);

    std::vector<std::pair<std::string, int>> &getAllIndexNamesForTable(const std::string &tableName);
};

#endif
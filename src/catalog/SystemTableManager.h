#ifndef SYSTEM_TABLE_H
#define SYSTEM_TABLE_H

#include <string>
#include <iostream>
#include <fstream>
#include <vector>

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
};

class SystemTableManager
{
private:
    std::string tablesFile, colsFile;
    int getNextTableId();
    int getNextColumnId();

public:
    SystemTableManager(const std::string &tablesFile, const std::string &columnsFile);
    void createSystemTables();
    int insertTableSchema(const std::string &tableName, std::vector<ColumnSchema *> &cols);
    TableSchema *getTableSchema(const std::string &tableName, std::vector<ColumnSchema *> &cols);
};

#endif
#ifndef TABLE_HANDLER
#define TABLE_HANDLER
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <fstream>

enum class Type
{
    INT,
    DOUBLE,
    STRING
};

struct Column
{
    std::string name;
    Type type;
};

struct Table
{
    std::string name;
    std::vector<Column> columns;
};

class TableHandler
{
public:
    std::string getStringType(Type t);
    void createTable(std::string tableName, std::vector<Column> columns);
};

#endif
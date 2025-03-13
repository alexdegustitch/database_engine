#ifndef TABLE_HANDLER
#define TABLE_HANDLER
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <variant>
#include <map>
#include <fstream>

using DataType = std::variant<int, std::string, double>;

enum class Type
{
    INT,
    DOUBLE,
    STRING
};

struct Column
{
    Column() {};
    Column(std::string name, Type type) : name(name), type(type) {};
    std::string name;
    Type type;
};

struct Row
{
    std::vector<std::pair<std::string, DataType>> data;
};

class Table
{
    std::string name;
    std::vector<Column> columns;
    std::map<std::string, Type> columnTypes;

public:
    Table() {};
    Table(std::string name, std::vector<Column> columns)
    {
        this->name = name;
        this->columns = columns;
    }
    void saveMetaData();
    void loadMetaData();
    void insertRow(Row row);
};

class TableHandler
{
private:
    std::map<std::string, Table> tables;

public:
    std::map<std::string, Table> &getTables() { return tables; };
    static std::string getStringType(Type t);
    static Type getTypeFromString(std::string t);

    void createTable(std::string tableName, std::vector<Column> &columns);
    void insertIntoTable(std::string tableName, Row &row);
};

#endif
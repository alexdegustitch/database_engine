#include "TableHandler.h"

std::string TableHandler::getStringType(Type t)
{
    static const std::unordered_map<Type, std::string> map = {
        {Type::INT, "INT"},
        {Type::DOUBLE, "DOUBLE"},
        {Type::STRING, "STRING"}};
    return map.at(t);
}

void TableHandler::createTable(std::string name, std::vector<Column> columns)
{
    std::ofstream file("data/" + name + ".db", std::ios::binary);
    for (auto c : columns)
    {
        file.write(c.name.c_str(), c.name.size());
        file.put('\0');
        file.write(getStringType(c.type).c_str(), getStringType(c.type).size());
        file.put('\0');
    }
    file.close();
    std::cout << "Created table " << name << std::endl;
}
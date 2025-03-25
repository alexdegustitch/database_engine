#include "TypeConverter.h"

TypeConverter::TypeConverter() {}

TypeConverter &TypeConverter::getInstance()
{
    static TypeConverter instance;
    return instance;
}

DataType TypeConverter::deserializeValue(char *type, const std::string &value)
{
    std::string str(type);
    std::cout << str << std::endl;
    if (strcmp(type, "INT") == 0)
    {
        int val = std::stoi(value);
        return val;
    }
    else if (strcmp(type, "TEXT") == 0 || strcmp(type, "VARCHAR") == 0 || strcmp(type, "CHAR") == 0)
    {
        return value;
    }
    else
    {
        std::cerr << "Unsupported column type!" << std::endl;
    }
    return nullptr;
}
#include "TypeConverter.h"

TypeConverter::TypeConverter() {}

TypeConverter &TypeConverter::getInstance()
{
    static TypeConverter instance;
    return instance;
}

DataType TypeConverter::deserializeValue(char *type, const std::string &value)
{
    std::cout << "I am here idk whats a problem!" << std::endl;
    std::string str(type);
    std::cout << str << std::endl;
    if (strcmp(type, "INT") == 0)
    {
        int val = std::stoi(value);
        std::cout << "My val " << val << std::endl;
        return val;
    }
    else if (strcmp(type, "TEXT") == 0 || strcmp(type, "VARCHAR") == 0 || strcmp(type, "CHAR") == 0)
    {
        std::cout << "My val " << value << std::endl;
        return value;
    }
    else
    {
        std::cerr << "Unsupported column type!" << std::endl;
    }
    return nullptr;
}

void TypeConverter::printDataTypeFormatted(DataType &data, int width)
{
    std::visit([&](const auto &v)
               { std::cout << std::left << std::setw(width) << v; }, data);
}

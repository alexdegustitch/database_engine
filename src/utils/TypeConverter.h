#ifndef TYPE_CONVERTER_H
#define TYPE_CONVERTER_H

#include <variant>
#include <string>
#include <iostream>
#include <iomanip>

using DataType = std::variant<int, char, std::string>;

class TypeConverter
{
public:
    TypeConverter();
    static TypeConverter &getInstance();
    DataType deserializeValue(char *type, const std::string &value);
    void printDataTypeFormatted(DataType &data, int width);
};
#endif
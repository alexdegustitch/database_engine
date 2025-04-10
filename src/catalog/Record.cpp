#include "Record.h"

Record::Record(TableSchema tbSchema, std::vector<ColumnSchema> cols, char *data) : cols(cols), tb(tbSchema), data(data) {}

void Record::deserializeData()
{
    values.clear();
    uint64_t offset = 0;
    for (ColumnSchema &cl : cols)
    {
        std::string colName(cl.columnName);
        std::cout << "COL NAME: " << colName << " OFFSET: " << offset << " CL SIZE: " << cl.size << " TYPE: " << cl.type << std::endl;
        if (strcmp(cl.type, "INT") == 0)
        {

            int value;
            char *rawVal;
            std::memcpy(&value, data + offset, cl.size);
            std::cout << "VALUE: " << value << std::endl;
            std::memcpy(&rawVal, data + offset, cl.size);
            offset += cl.size;
            values[colName] = value;
            rawValues[colName] = rawVal;
        }
        else if (strcmp(cl.type, "CHAR") == 0)
        {
            char buffer[cl.size + 1];
            std::memcpy(&buffer, data + offset, cl.size);
            buffer[cl.size] = '\0';
            char c;
            for (int i = 0; i < cl.size; ++i)
            {
                std::memcpy(&c, data + offset + i, 1);
                std::cout << "Char " << i << " = " << c << " ";
            }
            std::string value(buffer);
            std::cout << "/nVALUE: " << value << std::endl;
            offset += cl.size;
            values[colName] = value;
            rawValues[colName] = buffer;
        }
        else if (strcmp(cl.type, "TEXT") == 0 || strcmp(cl.type, "VARCHAR") == 0)
        {
            int len;
            memcpy(&len, data + offset, sizeof(int));
            char buffer[cl.size + 1];
            std::memcpy(&buffer, data + offset + sizeof(int), len);
            buffer[cl.size] = '\0';
            std::string value(buffer);
            std::cout << "VALUE: " << value << std::endl;
            offset += len;
            values[colName] = value;
            rawValues[colName] = buffer;
        }
    }
    std::cout << "Dont with deserialization!" << std::endl;
}

std::vector<char> &serializeData(std::vector<std::string> &colNames, std::vector<std::string> &colVals)
{
    int cntCols = colNames.size();
    for (int i = 0; i < cntCols; ++i)
    {
        ColumnSchema &cl = SystemTableManager::getInstance().getAllColumnSchema()[colNames[i]];
    }
}
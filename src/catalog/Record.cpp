#include "Record.h"

Record::Record(TableSchema *tbSchema, std::vector<ColumnSchema *> &cols, char *data) : cols(cols), tb(tbSchema), data(data) {}

void Record::serializeData()
{
    values.clear();
    uint64_t offset = 0;
    for (ColumnSchema *cl : cols)
    {
        std::string colName(cl->columnName);
        if (strcmp(cl->type, "INT") == 0)
        {
            int value;
            char *rawVal;
            std::memcpy(&value, data + offset, cl->size);
            std::memcpy(&rawVal, data + offset, cl->size);
            offset += cl->size;
            values[colName] = value;
            rawValues[colName] = rawVal;
        }
        else if (strcmp(cl->type, "TEXT") == 0 || strcmp(cl->type, "VARCHAR"))
        {
            char buffer[cl->size + 1];
            std::memcpy(&buffer, data + offset, cl->size);
            buffer[cl->size] = '\0';
            std::string value(buffer);
            offset += cl->size;
            values[colName] = value;
            rawValues[colName] = buffer;
        }
    }
}
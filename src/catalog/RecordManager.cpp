#include "RecordManager.h"

RecordManager::RecordManager()
{
    // tableManager = SystemTableManager::getInstance();
    bufferManager = new BufferManager();
    indexHandler = new IndexHandler();
}

RecordManager &RecordManager::getInstance()
{
    static RecordManager instance;
    return instance;
}

void RecordManager::deserializeData(char *data, std::vector<ColumnSchema> &cols, std::unordered_map<std::string, std::string> &values)
{
    uint64_t offset = 0;
    for (ColumnSchema &cl : cols)
    {
        std::string colName(cl.columnName);
        if (strcmp(cl.type, "INT") == 0)
        {
            int value;
            char *rawVal;
            std::memcpy(&value, data + offset, cl.size);
            std::memcpy(&rawVal, data + offset, cl.size);
            offset += cl.size;
            values[colName] = std::to_string(value);
        }
        else if (strcmp(cl.type, "TEXT") == 0 || strcmp(cl.type, "VARCHAR"))
        {
            char buffer[cl.size + 1];
            std::memcpy(&buffer, data + offset, cl.size);
            buffer[cl.size] = '\0';
            std::string value(buffer);
            offset += cl.size;
            values[colName] = value;
        }
    }
}

std::unordered_map<int, DataType> RecordManager::serializeData(std::vector<std::string> &colNames, std::vector<std::string> &colVals, std::vector<ColumnSchema> &schemas, std::vector<char> &row)
{

    std::unordered_map<int, DataType> columnValues;
    for (int i = 0; i < colNames.size(); ++i)
    {
        std::string &colName = colNames[i];
        std::string &colVal = colVals[i];

        ColumnSchema &colSchema = schemas[i];
        std::string str(colSchema.type);
        std::cout << str << std::endl;
        columnValues[colSchema.columnId] = TypeConverter::getInstance().deserializeValue(colSchema.type, colVal);
        if (strcmp(colSchema.type, "INT") == 0)
        {
            int val = std::stoi(colVal);
            row.insert(row.end(), reinterpret_cast<char *>(&val), reinterpret_cast<char *>(&val) + sizeof(colSchema.size));
        }
        else if (strcmp(colSchema.type, "TEXT") == 0 || strcmp(colSchema.type, "VARCHAR") == 0)
        {
            int len = colVal.size();
            std::string val = colVal;
            row.insert(row.end(), reinterpret_cast<char *>(&len), reinterpret_cast<char *>(&len) + sizeof(int));
            row.insert(row.end(), colVal.begin(), colVal.end());
        }
        else if (strcmp(colSchema.type, "CHAR") == 0)
        {
            std::vector<char> fixed(colSchema.size, '\0');
            memcpy(fixed.data(), colVal.c_str(), std::min((int)colVal.size(), colSchema.size));
            row.insert(row.end(), fixed.begin(), fixed.end());
        }
        else
        {
            std::cerr << "Unsupported column type!" << std::endl;
        }
    }
    return columnValues;
}
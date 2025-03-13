#include "TableHandler.h"

void Table::saveMetaData()
{
    std::ofstream metaFile("meta/" + name + ".meta", std::ios::binary | std::ios::app);
    if (!metaFile)
    {
        std::cerr << "Coult create metafile for table " << name << std::endl;
        return;
    }

    size_t cnt = columns.size();
    metaFile.write(reinterpret_cast<char *>(&cnt), sizeof(cnt));

    for (auto c : columns)
    {
        size_t nameLen = c.name.size();
        size_t typeLen = TableHandler::getStringType(c.type).size();

        metaFile.write(reinterpret_cast<char *>(&nameLen), sizeof(nameLen));
        metaFile.write(c.name.c_str(), nameLen);

        metaFile.write(reinterpret_cast<char *>(&typeLen), sizeof(typeLen));
        metaFile.write(TableHandler::getStringType(c.type).c_str(), typeLen);
    }

    metaFile.close();
};

void Table::loadMetaData()
{
    std::ifstream metaFile("meta/" + name + ".meta", std::ios::binary);
    if (!metaFile)
    {
        std::cerr << "Could not load meta data for table " << name << std::endl;
        return;
    }
    size_t cnt;
    metaFile.read(reinterpret_cast<char *>(&cnt), sizeof(cnt));

    columns.clear();
    columnTypes.clear();
    for (size_t i = 0; i < cnt; ++i)
    {
        size_t nameLen, typeLen;
        metaFile.read(reinterpret_cast<char *>(&nameLen), sizeof(nameLen));

        std::string name(nameLen, ' ');
        metaFile.read(&name[0], nameLen);

        metaFile.read(reinterpret_cast<char *>(&typeLen), sizeof(typeLen));

        std::string type(typeLen, ' ');
        metaFile.read(&type[0], typeLen);

        columns.push_back(Column(name, TableHandler::getTypeFromString(type)));
        columnTypes[name] = TableHandler::getTypeFromString(type);
    }
    metaFile.close();
};

void Table::insertRow(Row row)
{
    std::ofstream file("data/" + name + ".db", std::ios::binary | std::ios::app);
    if (!file)
    {
        std::cerr << "Error! Could not open file for writing!" << std::endl;
    }
    for (auto r : row.data)
    {
        std::string colName = r.first;
        DataType colVal = r.second;
        std::string colType = TableHandler::getStringType(columnTypes[colName]);
        if (colType == "STRING")
        {
            size_t len = sizeof(colVal);
            std::string val = std::get<std::string>(colVal);
            file.write(reinterpret_cast<char *>(&len), sizeof(len));
            file.write(val.c_str(), len);
        }
        else if (colType == "INT")
        {
            int val = std::get<int>(colVal);
            file.write(reinterpret_cast<char *>(&val), sizeof(val));
        }
        else if (colType == "DOUBLE")
        {
            double val = std::get<double>(colVal);
            file.write(reinterpret_cast<char *>(&val), sizeof(val));
        }
    }
    file.close();
}

std::string TableHandler::getStringType(Type t)
{
    static const std::unordered_map<Type, std::string> map = {
        {Type::INT, "INT"},
        {Type::STRING, "STRING"},
        {Type::DOUBLE, "DOUBLE"}};
    return map.at(t);
}

Type TableHandler::getTypeFromString(std::string t)
{
    static const std::unordered_map<std::string, Type> map = {
        {"INT", Type::INT},
        {"STRING", Type::STRING},
        {"DOUBLE", Type::DOUBLE}};
    return map.at(t);
}

void TableHandler::createTable(std::string name, std::vector<Column> &columns)
{
    /*std::ofstream file("data/" + name + ".db", std::ios::binary);
    for (auto c : columns)
    {
        file.write(c.name.c_str(), c.name.size());
        file.put('\0');
        file.write(getStringType(c.type).c_str(), getStringType(c.type).size());
        file.put('\0');
    }
    file.close();*/
    tables[name] = Table(name, columns);
    tables[name].saveMetaData();
    std::cout << "Created table " << name << std::endl;
}

void TableHandler::insertIntoTable(std::string name, Row &row)
{
    if (tables.find(name) == tables.end())
    {
        std::cerr << "Table " << name << " does not exist" << std::endl;
    }

    tables[name].insertRow(row);
}
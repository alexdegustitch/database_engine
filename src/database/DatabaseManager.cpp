#include "DatabaseManager.h"

DatabaseManager::DatabaseManager() {}

DatabaseManager &DatabaseManager::getInstance()
{
    static DatabaseManager instance;
    return instance;
}

bool DatabaseManager::insertRecord(const std::string &tableName, std::vector<std::string> &cols, std::vector<std::string> &values)
{
    std::cout << "cols size: " << cols.size() << std::endl;
    std::cout << "values size: " << values.size() << std::endl;
    for (int i = 0; i < cols.size(); i++)
    {
        std::cout << "col: " << cols[i] << ", val: " << values[i] << std::endl;
    }
    std::cout << "IN INSERT RECORD " << std::endl;
    std::vector<ColumnSchema> schemas = SystemTableManager::getInstance().getSchemasForColumns(tableName, cols);
    std::vector<char> row;
    std::unordered_map<int, DataType> colValues = RecordManager::getInstance().serializeData(cols, values, schemas, row);
    std::cout << "INSERTING VALUES: " << std::endl;
    for (auto curr : colValues)
    {
        std::cout << curr.first << " ";
        TypeConverter::getInstance().printDataTypeFormatted(curr.second, 10);
    }
    std::cout << "\n ";

    int pageId = PageManager::getInstance().findPageWithFreeSpace(tableName);
    Page *p = BufferManager::getInstance().fetchPage(tableName, pageId);
    int slotIdx = p->insertRecord(row);
    BufferManager::getInstance().flushPage(tableName, pageId);
    PageManager::getInstance().updateFSM(tableName, pageId, p->getFreeSpace());
    PageManager::getInstance().saveFSM(tableName);

    std::vector<std::pair<std::string, int>> indexes = SystemTableManager::getInstance().getAllIndexNamesForTable(tableName);

    for (auto idx : indexes)
    {
        std::cout << "Idx name: " << idx.first << " col id: " << idx.second << std::endl;
        DataType val = colValues[idx.second];
        std::cout << "val: " << std::get<int>(val) << " " << pageId << " " << slotIdx << std::endl;
        IndexHandler::getInstance().insertIntoIndex(idx.first, std::get<int>(val), pageId, slotIdx);
    }
    std::cout << "Insert record done " << std::endl;
}

bool DatabaseManager::selectRecord(const std::string &tableName, std::vector<std::string> &cols, ConditionTree *tree, std::vector<LeafConditionNode *> idxNodes, std::vector<std::pair<std::string, std::string>> &orderCol)
{
    std::cout << "Select record method " << std::endl;
    std::vector<std::pair<uint64_t, uint64_t>> offsets;
    if (idxNodes.size() > 0)
    {
        std::string colName = idxNodes[0]->getColName();
        std::string idxName = tableName + "_" + colName + "_idx";
        IndexSchema idxSchema = SystemTableManager::getInstance().getAllIndexSchema()[idxName];
        if (idxNodes[0]->getOp() == COMPARISON_OP::EQ)
        {
            IndexHandler::getInstance().searchFromIndex(idxName, std::get<int>(idxNodes[0]->getConvertedValue()), offsets);
        }
        else if (idxNodes[0]->getOp() != COMPARISON_OP::NE)
        {
            bool isStart = false, isEnd = false;
            COMPARISON_OP startOp, endOp;
            int startKey, endKey;

            int i = 0;
            int len = idxNodes.size();
            while (i < len && idxNodes[i]->getOp() == COMPARISON_OP::GE)
            {
                isStart = true;
                startOp = COMPARISON_OP::GE;
                startKey = std::get<int>(idxNodes[i]->getConvertedValue());
                ++i;
            }
            while (i < len && idxNodes[i]->getOp() == COMPARISON_OP::GE)
            {
                isStart = true;
                startOp = COMPARISON_OP::GT;
                startKey = std::get<int>(idxNodes[i]->getConvertedValue());
                ++i;
            }
            while (i < len && idxNodes[i]->getOp() == COMPARISON_OP::LE)
            {
                isEnd = true;
                endOp = COMPARISON_OP::LE;
                endKey = std::get<int>(idxNodes[i]->getConvertedValue());
                ++i;
            }
            while (i < len && idxNodes[i]->getOp() == COMPARISON_OP::LT)
            {
                isEnd = true;
                endOp = COMPARISON_OP::LT;
                endKey = std::get<int>(idxNodes[i]->getConvertedValue());
                ++i;
            }
            if (isStart && isEnd)
            {
                IndexHandler::getInstance().searchRangeStartEndFromIndex(idxName, startKey, startOp, endKey, endOp, offsets);
            }
            else if (isStart)
            {
                IndexHandler::getInstance().searchRangeStartFromIndex(idxName, startKey, startOp, offsets);
            }
            else
            {
                IndexHandler::getInstance().searchRangeEndFromIndex(idxName, endKey, endOp, offsets);
            }
        }
        else
        {
            int val = std::get<int>(idxNodes[0]->getConvertedValue());
            IndexHandler::getInstance().searchRangeEndFromIndex(idxName, val, COMPARISON_OP::LT, offsets);
            IndexHandler::getInstance().searchRangeEndFromIndex(idxName, val, COMPARISON_OP::GT, offsets);
        }
    }
    else
    {
        std::string idxName = tableName + "_" + "ID" + "_idx";
        IndexHandler::getInstance().getAllFromIndex(idxName, offsets);
    }
    std::cout << "Ovde sam i resords size is: " << offsets.size() << std::endl;
    TableSchema tb = SystemTableManager::getInstance().getAllTableSchemas()[tableName];
    std::vector<ColumnSchema> clSchemas = SystemTableManager::getInstance().getAllColumnSchemasForTable(tableName);
    std::vector<Record> records;
    for (auto offset : offsets)
    {
        std::cout << "Dodavanje rekorda!" << std::endl;
        uint64_t pageId = offset.first;
        uint64_t slotIdx = offset.second;
        // std::cout << "page id: " << pageId << " slot idx: " << slotIdx;
        Page *p = BufferManager::getInstance().fetchPage(tableName, pageId);
        std::vector<char> record;
        p->readRecord(slotIdx, record);
        // std::cout << " Record: " << record.data() << std::endl;
        // std::cout << "I am here!" << std::endl;
        Record r(tb, clSchemas, record.data());
        r.deserializeData();
        records.push_back(r);
        for (auto v : r.getValues())
        {
            std::cout << v.first << " ";
            TypeConverter::getInstance().printDataTypeFormatted(v.second, 10);
        }
    }

    std::vector<Record> resultRecords;
    if (tree == nullptr)
    {
        resultRecords = records;
    }
    else
    {
        for (auto &record : records)
        {
            std::cout << "I am evaluating a record!" << std::endl;
            if (tree->evaluateRecord(record))
            {
                resultRecords.push_back(record);
            }
        }
    }

    std::cout << "Done evaluating!" << std::endl;
    if (orderCol.size() > 0)
    {
        std::sort(resultRecords.begin(), resultRecords.end(), RecordComparator(orderCol));
    }

    for (const auto &col : cols)
    {
        std::cout << std::left << std::setw(15) << col;
    }
    std::cout << "\n"
              << std::string(15 * cols.size(), '-') << "\n";

    for (auto &record : resultRecords)
    {
        for (auto &col : cols)
        {
            TypeConverter::getInstance().printDataTypeFormatted(record.getValues()[col], 15);
        }
        std::cout << std::endl;
    }
}

bool DatabaseManager::deleteRecord(const std::string &tableName, ConditionTree *tree, std::vector<LeafConditionNode *> idxNodes)
{
    std::cout << "Delete record method " << std::endl;
    std::vector<std::pair<uint64_t, uint64_t>> offsets;
    if (idxNodes.size() > 0)
    {
        std::string colName = idxNodes[0]->getColName();
        std::string idxName = tableName + "_" + colName + "_idx";
        IndexSchema idxSchema = SystemTableManager::getInstance().getAllIndexSchema()[idxName];
        if (idxNodes[0]->getOp() == COMPARISON_OP::EQ)
        {
            IndexHandler::getInstance().searchFromIndex(idxName, std::get<int>(idxNodes[0]->getConvertedValue()), offsets);
        }
        else if (idxNodes[0]->getOp() != COMPARISON_OP::NE)
        {
            bool isStart = false, isEnd = false;
            COMPARISON_OP startOp, endOp;
            int startKey, endKey;

            int i = 0;
            int len = idxNodes.size();
            while (i < len && idxNodes[i]->getOp() == COMPARISON_OP::GE)
            {
                isStart = true;
                startOp = COMPARISON_OP::GE;
                startKey = std::get<int>(idxNodes[i]->getConvertedValue());
                ++i;
            }
            while (i < len && idxNodes[i]->getOp() == COMPARISON_OP::GE)
            {
                isStart = true;
                startOp = COMPARISON_OP::GT;
                startKey = std::get<int>(idxNodes[i]->getConvertedValue());
                ++i;
            }
            while (i < len && idxNodes[i]->getOp() == COMPARISON_OP::LE)
            {
                isEnd = true;
                endOp = COMPARISON_OP::LE;
                endKey = std::get<int>(idxNodes[i]->getConvertedValue());
                ++i;
            }
            while (i < len && idxNodes[i]->getOp() == COMPARISON_OP::LT)
            {
                isEnd = true;
                endOp = COMPARISON_OP::LT;
                endKey = std::get<int>(idxNodes[i]->getConvertedValue());
                ++i;
            }
            if (isStart && isEnd)
            {
                IndexHandler::getInstance().searchRangeStartEndFromIndex(idxName, startKey, startOp, endKey, endOp, offsets);
            }
            else if (isStart)
            {
                IndexHandler::getInstance().searchRangeStartFromIndex(idxName, startKey, startOp, offsets);
            }
            else
            {
                IndexHandler::getInstance().searchRangeEndFromIndex(idxName, endKey, endOp, offsets);
            }
        }
        else
        {
            int val = std::get<int>(idxNodes[0]->getConvertedValue());
            IndexHandler::getInstance().searchRangeEndFromIndex(idxName, val, COMPARISON_OP::LT, offsets);
            IndexHandler::getInstance().searchRangeEndFromIndex(idxName, val, COMPARISON_OP::GT, offsets);
        }
    }
    else
    {
        std::string idxName = tableName + "_" + "ID" + "_idx";
        IndexHandler::getInstance().getAllFromIndex(idxName, offsets);
    }
    std::cout << "Ovde sam i resords size is: " << offsets.size() << std::endl;
    TableSchema tb = SystemTableManager::getInstance().getAllTableSchemas()[tableName];
    std::vector<ColumnSchema> clSchemas = SystemTableManager::getInstance().getAllColumnSchemasForTable(tableName);
    std::vector<std::pair<Record, std::pair<uint64_t, uint64_t>>> records;

    for (auto offset : offsets)
    {
        std::cout << "Brisanje rekorda!" << std::endl;
        uint64_t pageId = offset.first;
        uint64_t slotIdx = offset.second;
        // std::cout << "page id: " << pageId << " slot idx: " << slotIdx;
        Page *p = BufferManager::getInstance().fetchPage(tableName, pageId);
        std::vector<char> record;
        p->readRecord(slotIdx, record);
        // std::cout << " Record: " << record.data() << std::endl;
        // std::cout << "I am here!" << std::endl;
        Record r(tb, clSchemas, record.data());
        r.deserializeData();
        records.push_back({r, offset});
        for (auto v : r.getValues())
        {
            std::cout << v.first << " ";
            TypeConverter::getInstance().printDataTypeFormatted(v.second, 10);
        }
    }
    std::vector<std::pair<Record, std::pair<uint64_t, uint64_t>>> recordsToDelete;
    if (tree == nullptr)
    {
        recordsToDelete = records;
    }
    else
    {
        for (auto &record : records)
        {
            std::cout << "I am evaluating a record!" << std::endl;
            if (tree->evaluateRecord(record.first))
            {
                recordsToDelete.push_back(record);
            }
        }
    }

    // Deleting data from indexes

    for (auto &idx : SystemTableManager::getInstance().getAllIndexNamesForTable(tableName))
    {
        std::string idxName = idx.first;
        int colId = idx.second;
        std::cout << "Col id: " << colId << std::endl;
        std::string colName = SystemTableManager::getInstance().getColumnIdToName()[colId];
        for (auto &record : recordsToDelete)
        {
            Record &r = record.first;
            std::pair<uint64_t, uint64_t> offset = record.second;
            std::cout << "page id: " << offset.first << ", slot idx: " << offset.second << std::endl;
            std::cout << "Col name: " << colName << " and values are: " << std::endl;
            for (auto k : r.getValues())
            {
                TypeConverter::getInstance().printDataTypeFormatted(k.second, 10);
            }
            IndexHandler::getInstance().deleteFromIndex(idxName, std::get<int>(r.getValues()[colName]), offset.first, offset.second);
        }
    }

    std::cout << "Deleting record!" << std::endl;
    // Deleting actuall data (records)
    for (auto &record : recordsToDelete)
    {

        Record &r = record.first;
        std::pair<uint64_t, uint64_t> offset = record.second;

        uint64_t pageId = offset.first;
        uint64_t slotIdx = offset.second;
        std::cout << "Page ID: " << pageId << ", Slot IDX: " << slotIdx << std::endl;
        Page *p = BufferManager::getInstance().fetchPage(tableName, pageId);
        p->deleteRecord(slotIdx);
    }
    if (recordsToDelete.size() == 1)
        std::cout << "Deleted 1 record." << std::endl;
    else
        std::cout << "Deleted " << recordsToDelete.size() << " records." << std::endl;
}
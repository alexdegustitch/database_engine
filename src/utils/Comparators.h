#ifndef COMPARATORS_H
#define COMPARATORS_H
#include "../query/condition/LeafConditionNode.h"

struct ConditionComparator
{
    bool operator()(LeafConditionNode *a, LeafConditionNode *b) const
    {

        if (a->getOp() == COMPARISON_OP::EQ && b->getOp() != COMPARISON_OP::EQ)
        {
            return false;
        }
        if (a->getOp() != COMPARISON_OP::EQ && b->getOp() == COMPARISON_OP::EQ)
        {
            return true;
        }
        if (a->getOp() == COMPARISON_OP::GE)
        {
            if (b->getOp() != COMPARISON_OP::GE)
            {
                return false;
            }
            if (a->getColName() == b->getColName() && a->getTableName() == b->getTableName())
            {
                return a->getConvertedValue() < b->getConvertedValue();
            }
            return false;
        }

        if (a->getOp() == COMPARISON_OP::GT)
        {
            if (b->getOp() != COMPARISON_OP::GT)
            {
                return false;
            }
            if (a->getColName() == b->getColName() && a->getTableName() == b->getTableName())
            {
                return a->getConvertedValue() < b->getConvertedValue();
            }
            return false;
        }

        if (a->getOp() == COMPARISON_OP::LT)
        {
            if (b->getOp() != COMPARISON_OP::LT)
            {
                return false;
            }
            if (a->getColName() == b->getColName() && a->getTableName() == b->getTableName())
            {
                return a->getConvertedValue() > b->getConvertedValue();
            }
            return false;
        }
        if (a->getOp() == COMPARISON_OP::LE)
        {
            if (b->getOp() != COMPARISON_OP::LE)
            {
                return false;
            }
            if (a->getColName() == b->getColName() && a->getTableName() == b->getTableName())
            {
                return a->getConvertedValue() > b->getConvertedValue();
            }
        }
        return false;
    }
};

struct RecordComparator
{
    std::vector<std::pair<std::string, std::string>> &orderCols;
    RecordComparator(std::vector<std::pair<std::string, std::string>> orderCols) : orderCols(orderCols) {}

    bool operator()(Record &a, Record &b) const
    {
        for (const auto &col : orderCols)
        {
            const auto &colName = col.first;
            const auto &direction = col.second;
            std::cout << "col name: " << colName << std::endl;
            for (auto x : a.getValues())
            {
                std::cout << x.first << " !! " << std::endl;
            }
            const auto &valA = a.getValues().at(colName);
            const auto &valB = b.getValues().at(colName);

            if (valA == valB)
                continue;

            // True if valA should come before valB
            bool less = valA < valB;

            // Handle sort direction
            return direction == "ASC" ? less : !less;
        }

        // All values are equal
        return false;
    }
};

#endif
#include "ConditionHandler.h"

ConditionHandler::ConditionHandler() {}

ConditionHandler &ConditionHandler::getInstance()
{
    static ConditionHandler instance;
    return instance;
}

std::vector<LeafConditionNode *> ConditionHandler::findIndexColumn(const std::string &tableName, ConditionTree *tree)
{
    std::vector<LeafConditionNode *> res;
    if (tree == nullptr)
    {
        return res;
    }
    std::priority_queue<LeafConditionNode *, std::vector<LeafConditionNode *>, ConditionComparator> pq;
    std::vector<std::pair<std::string, int>> &indexes = SystemTableManager::getInstance().getAllIndexNamesForTable(tableName);
    std::unordered_set<std::string> idxNames;
    std::cout << "Indexes in a set: " << std::endl;
    for (const auto &index : indexes)
    {
        std::cout << index.first << std::endl;
        idxNames.insert(index.first);
    }

    visitConditionNode(tableName, tree->getRoot(), pq, idxNames);

    if (pq.empty())
    {
        // IndexSchema idx = {};
        std::cout << "IT IS EMPTY" << std::endl;
        return res;
    }
    // std::string idxName = tableName + "_" + pq.top()->getColName() + "_idx";

    // return SystemTableManager::getInstance().getAllIndexSchema()[idxName];
    LeafConditionNode *topNode = pq.top();
    pq.pop();
    res.push_back(topNode);
    while (!pq.empty())
    {
        if (pq.top()->getColName() == topNode->getColName() && pq.top()->getTableName() == topNode->getTableName())
        {
            res.push_back(pq.top());
        }
        pq.pop();
    }
    return res;
}

void ConditionHandler::visitConditionNode(const std::string &tableName, ConditionNode *node, std::priority_queue<LeafConditionNode *, std::vector<LeafConditionNode *>, ConditionComparator> &pq, std::unordered_set<std::string> &indexes)
{

    if (node->isLeaf)
    {
        std::cout << "Visiting leaf -> " << static_cast<LeafConditionNode *>(node)->getColName() << " " << static_cast<LeafConditionNode *>(node)->getOp() << std::endl;
        std::string idxName = tableName + "_" + static_cast<LeafConditionNode *>(node)->getColName() + "_idx";
        std::cout << "Idx name " << idxName << std::endl;
        if (indexes.count(idxName) > 0)
        {
            std::cout << "EXISTS " << idxName << std::endl;
            pq.push(static_cast<LeafConditionNode *>(node));
        }
        return;
    }
    std::cout << "Visiting Internal -> " << static_cast<InternalConditionNode *>(node)->getOp() << std::endl;
    visitConditionNode(tableName, static_cast<InternalConditionNode *>(node)->getLeftChild(), pq, indexes);
    visitConditionNode(tableName, static_cast<InternalConditionNode *>(node)->getRightChild(), pq, indexes);
}
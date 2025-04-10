#ifndef CONDITION_HANDLER_H
#define CONDITION_HANDLER_H

#include "LeafConditionNode.h"
#include "ConditionTree.h"
#include "../../catalog/SystemTableManager.h"
#include "../../utils/Comparators.h"
#include <queue>
#include <unordered_set>

class ConditionHandler
{
public:
    ConditionHandler();
    static ConditionHandler &getInstance();
    std::vector<LeafConditionNode *> findIndexColumn(const std::string &tableName, ConditionTree *tree);

private:
    void visitConditionNode(const std::string &tableName, ConditionNode *node, std::priority_queue<LeafConditionNode *, std::vector<LeafConditionNode *>, ConditionComparator> &pq, std::unordered_set<std::string> &indexes);
};

#endif
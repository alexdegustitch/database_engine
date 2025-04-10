#include "SQLQueryVisitor.h"

antlrcpp::Any SQLQueryVisitor::visitSelectQuery(SQLParser::SelectQueryContext *ctx)
{
    std::cout << "Visiting Select Query..." << ctx->tableName()->getText() << std::endl;
    std::string tableName = ctx->tableName()->getText();
    currentTableName = tableName;
    std::vector<std::string> cols = std::any_cast<std::vector<std::string>>(visit(ctx->columns()));
    std::cout << "cols" << std::endl;
    ConditionTree *tree = nullptr;
    if (ctx->whereClause())
    {

        tree = std::any_cast<ConditionTree *>(visit(ctx->whereClause()));
        std::cout << "Where clause" << std::endl;
    }

    std::vector<LeafConditionNode *> idxNodes = ConditionHandler::getInstance().findIndexColumn(tableName, tree);
    // std::cout << "Index Column -> " << idx.indexName << std::endl;

    std::vector<std::pair<std::string, std::string>> orderCol;

    if (ctx->orderByClause())
    {
        orderCol.push_back(std::any_cast<std::pair<std::string, std::string>>(visit(ctx->orderByClause())));
    }
    else
    {
        orderCol.push_back(std::make_pair("ID", "ASC"));
    }
    DatabaseManager::getInstance().selectRecord(tableName, cols, tree, idxNodes, orderCol);
    return nullptr;
}

antlrcpp::Any SQLQueryVisitor::visitCreateQuery(SQLParser::CreateQueryContext *ctx)
{
    std::cout << "Visiting Create Query..." << ctx->tableName()->getText() << std::endl;
    std::string tableName = ctx->tableName()->getText();
    std::vector<ColumnSchema> cols = std::any_cast<std::vector<ColumnSchema>>(visit(ctx->tableValues()));

    std::string primaryKeyCol;
    for (auto cl : cols)
    {
        if (cl.isPrimary)
        {
            primaryKeyCol = cl.columnName;
            break;
        }
    }
    SystemTableManager::getInstance().insertTableSchema(tableName, cols);
    std::string fullName = tableName + "_" + primaryKeyCol + "_idx";
    SystemTableManager::getInstance().insertIndexSchema(tableName, primaryKeyCol, fullName, true);
    IndexHandler::getInstance().loadIndex(fullName, 4);

    return nullptr;
}

antlrcpp::Any SQLQueryVisitor::visitTableValues(SQLParser::TableValuesContext *ctx)
{
    std::cout << "Visiting Table Values..." << std::endl;
    std::vector<ColumnSchema> cols;

    for (auto c : ctx->tableValue())
    {
        std::string colName = c->value()->getText();
        std::string colType;
        int len = -1;
        bool isVariable = false;
        bool isNotNull = false;
        bool isPrimary = false;
        for (auto cc : c->columnConstraint())
        {
            std::cout << "Text: " << cc->getText() << std::endl;
            if (cc->getText() == "PRIMARYKEY")
            {
                if (isPrimary)
                {
                    std::cerr << "Only one column can be a primary key!" << std::endl;
                    return false;
                }
                isPrimary = true;
                isNotNull = true;
            }
            else if (cc->getText() == "NOT NULL")
            {
                isNotNull = true;
            }
        }

        if (c->dataType()->children.size() == 1)
        {

            colType = c->dataType()->getText();
            if (colType == "INT")
            {
                len = sizeof(int);
                isVariable = false;
            }
            else if (colType == "TEXT")
            {
                len = 1000;
                isVariable = true;
            }
        }
        else
        {
            colType = c->dataType()->children[0]->getText();
            len = std::stoi(c->dataType()->children[2]->getText());
            if (colType == "CHAR")
            {
                isVariable = false;
            }
            else if (colType == "VARCHAR")
            {
                isVariable = true;
            }
        }
        ColumnSchema cl;
        cl.columnId = 0;
        cl.tableId = 0;
        strncpy(cl.columnName, colName.c_str(), sizeof(cl.columnName));
        cl.columnName[sizeof(cl.columnName) - 1] = '\0';
        strncpy(cl.type, colType.c_str(), sizeof(cl.type));
        cl.type[sizeof(cl.type) - 1] = '\0';
        cl.size = len;
        cl.isVariable = isVariable;
        cl.isNotNull = isNotNull;
        cl.isPrimary = isPrimary;
        cols.push_back(cl);
    }

    return cols;
}

antlrcpp::Any SQLQueryVisitor::visitInsertQuery(SQLParser::InsertQueryContext *ctx)
{
    std::cout << "Visiting Insert into table ..." << std::endl;
    std::string tableName = ctx->tableName()->getText();
    std::vector<std::string> cols;
    if (ctx->insertColumns())
    {
        cols = std::any_cast<std::vector<std::string>>(visit(ctx->insertColumns()));
    }
    else
    {
        SystemTableManager &manager = SystemTableManager::getInstance();
        cols = manager.getColsInTable(tableName);
    }
    std::vector<std::string> values = std::any_cast<std::vector<std::string>>(visit(ctx->values()));
    DatabaseManager::getInstance().insertRecord(tableName, cols, values);
    std::cout << "I am here in the end of visit insert query" << std::endl;
    return nullptr;
}

antlrcpp::Any SQLQueryVisitor::visitInsertColumns(SQLParser::InsertColumnsContext *ctx)
{
    std::vector<std::string> cols;
    for (int i = 0; i < ctx->column().size(); ++i)
    {
        cols.push_back(ctx->column(i)->ID()->getText());
    }
    return cols;
}
antlrcpp::Any SQLQueryVisitor::visitValues(SQLParser::ValuesContext *ctx)
{
    std::vector<std::string> vals;
    for (int i = 0; i < ctx->value().size(); ++i)
    {
        if (ctx->value(i)->ID())
        {
            vals.push_back(ctx->value(i)->ID()->getText());
        }
        else if (ctx->value(i)->STRING())
        {
            vals.push_back(ctx->value(i)->STRING()->getText());
        }
        else if (ctx->value(i)->NUMBER())
        {
            vals.push_back(ctx->value(i)->NUMBER()->getText());
        }
    }
    return vals;
}

antlrcpp::Any SQLQueryVisitor::visitColumns(SQLParser::ColumnsContext *ctx)
{
    std::vector<std::string> cols;
    if (ctx->children.size() == 1 && ctx->children[0]->getText() == "*")
    {
        for (ColumnSchema &cs : SystemTableManager::getInstance().getAllColumnSchemasForTable(currentTableName))
        {
            cols.push_back(cs.columnName);
        }
        return cols;
    }

    for (int i = 0; i < ctx->column().size(); ++i)
    {
        cols.push_back(ctx->column(i)->ID()->getText());
    }
    return cols;
}

antlrcpp::Any SQLQueryVisitor::visitWhereClause(SQLParser::WhereClauseContext *ctx)
{

    ConditionNode *root = std::any_cast<ConditionNode *>(visit(ctx->condition()));
    ConditionTree *tree = new ConditionTree(root);
    return tree;
}

antlrcpp::Any SQLQueryVisitor::visitOrderByClause(SQLParser::OrderByClauseContext *ctx)
{
    std::string colName = ctx->column()->getText();
    std::string dir = "ASC";
    if (ctx->children.size() == 3)
    {
        dir = ctx->children[2]->getText();
    }
    return std::make_pair(colName, dir);
}

antlrcpp::Any SQLQueryVisitor::visitCondition(SQLParser::ConditionContext *ctx)
{
    return visit(ctx->orCondition());
}

antlrcpp::Any SQLQueryVisitor::visitOrCondition(SQLParser::OrConditionContext *ctx)
{
    ConditionNode *left = std::any_cast<ConditionNode *>(visitAndCondition(ctx->andCondition(0)));
    for (size_t i = 1; i < ctx->andCondition().size(); ++i)
    {
        ConditionNode *right = std::any_cast<ConditionNode *>(visitAndCondition(ctx->andCondition(i)));
        left = new InternalConditionNode(LOGICAL_OP::OR, left, right);
    }

    return static_cast<ConditionNode *>(left);
}

antlrcpp::Any SQLQueryVisitor::visitAndCondition(SQLParser::AndConditionContext *ctx)
{

    ConditionNode *left = std::any_cast<ConditionNode *>(visitBaseCondition(ctx->baseCondition(0)));

    for (size_t i = 1; i < ctx->baseCondition().size(); ++i)
    {
        ConditionNode *right = std::any_cast<ConditionNode *>(visitBaseCondition(ctx->baseCondition(i)));
        left = new InternalConditionNode(LOGICAL_OP::AND, left, right);
    }
    return static_cast<ConditionNode *>(left);
}

antlrcpp::Any SQLQueryVisitor::visitBaseCondition(SQLParser::BaseConditionContext *ctx)
{
    if (ctx->condition())
    {
        return visit(ctx->condition());
    }
    return visit(ctx->columnValueCondition());
}

antlrcpp::Any SQLQueryVisitor::visitColumnValueCondition(SQLParser::ColumnValueConditionContext *ctx)
{
    std::string colName = ctx->column()->getText();
    COMPARISON_OP op;
    if (ctx->operator_()->getText() == "=")
        op = COMPARISON_OP::EQ;
    else if (ctx->operator_()->getText() == "<>")
        op = COMPARISON_OP::NE;
    else if (ctx->operator_()->getText() == "<=")
        op = COMPARISON_OP::LE;
    else if (ctx->operator_()->getText() == "<")
        op = COMPARISON_OP::LT;
    else if (ctx->operator_()->getText() == ">=")
        op = COMPARISON_OP::GE;
    else
        op = COMPARISON_OP::GT;

    const char *value = ctx->value()->getText().c_str();

    LeafConditionNode *node = new LeafConditionNode(op, currentTableName, colName, value);

    return static_cast<ConditionNode *>(node);
}
#include "SQLQueryVisitor.h"

antlrcpp::Any SQLQueryVisitor::visitSelectQuery(SQLParser::SelectQueryContext *ctx)
{
    std::cout << "Visiting Select Query..." << ctx->tableName()->getText() << std::endl;
    ConditionTree *tree = std::any_cast<ConditionTree *>(visit(ctx->whereClause()));

    return nullptr;
}

antlrcpp::Any SQLQueryVisitor::visitCreateQuery(SQLParser::CreateQueryContext *ctx)
{
    std::cout << "Visiting Crate Query..." << ctx->tableName()->getText() << std::endl;
    std::string tableName = ctx->tableName()->getText();
    std::vector<Column> cols = std::any_cast<std::vector<Column>>(visitTableValues(ctx->tableValues()));

    tableHandler.createTable(tableName, cols);
    return nullptr;
}

antlrcpp::Any SQLQueryVisitor::visitTableValues(SQLParser::TableValuesContext *ctx)
{
    std::cout << "Visiting Table Values..." << std::endl;
    std::vector<Column> cols;

    for (auto c : ctx->tableValue())
    {
        std::string colName = c->value()->getText();
        std::string colType = c->TYPE()->getText();
        cols.push_back(Column(colName, TableHandler::getTypeFromString(colType)));
    }

    return cols;
}

antlrcpp::Any SQLQueryVisitor::visitInsertQuery(SQLParser::InsertQueryContext *ctx)
{
    std::cout << "Visiting Insert into table ..." << std::endl;
    std::string tableName = ctx->tableName()->getText();
    Row row;
    if (ctx->insertColumns())
    {
        row = std::any_cast<Row>(visitInsertColumns(ctx->insertColumns()));
    }
    else
    {
        // for(auto c:tableHandler.getTables()[tableName].)
    }
    return row;
}

antlrcpp::Any SQLQueryVisitor::visitInsertColumns(SQLParser::InsertColumnsContext *ctx)
{
    Row row;
    for (auto r : ctx->column())
    {
        row.data.push_back({r->ID()->getText(), ""});
    }
    return row;
}

/*antlrcpp::Any SQLQueryVisitor::visitColumns(SQLParser::ColumnsContext *ctx)
{
    std::cout << "Visiting Columns ..." << std::endl;
    std::vector<Column> cols;

    for(auto c: ctx->column()){
        std::string colName = c->getText();
        std::string typeName = ->
    }
    return cols;
}*/

antlrcpp::Any SQLQueryVisitor::visitWhereClause(SQLParser::WhereClauseContext *ctx)
{

    ConditionNode *root = std::any_cast<ConditionNode *>(visit(ctx->condition()));
    ConditionTree *tree = new ConditionTree(root);
    return tree;
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
        InternalConditionNode *res = new InternalConditionNode(LOGICAL_OP::OR, left, right);
        left = res;
    }

    return left;
}

antlrcpp::Any SQLQueryVisitor::visitAndCondition(SQLParser::AndConditionContext *ctx)
{
    ConditionNode *left = std::any_cast<ConditionNode *>(visitBaseCondition(ctx->baseCondition(0)));

    for (size_t i = 1; i < ctx->baseCondition().size(); ++i)
    {
        ConditionNode *right = std::any_cast<ConditionNode *>(visitBaseCondition(ctx->baseCondition(i)));
        InternalConditionNode *res = new InternalConditionNode(LOGICAL_OP::AND, left, right);
        left = res;
    }
    return left;
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

    LeafConditionNode *node = new LeafConditionNode(op, colName, value);
    return node;
}
#include "SQLQueryVisitor.h"

antlrcpp::Any SQLQueryVisitor::visitSelectQuery(SQLParser::SelectQueryContext *ctx)
{
    std::cout << "Visiting Select Query..." << ctx->tableName()->getText() << std::endl;

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
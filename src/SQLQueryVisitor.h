#ifndef SQL_QUERY_VISITOR
#define SQL_QUERY_VISITOR

#include "antlr/SQLBaseVisitor.h"
#include "TableHandler.h"
#include "query/condition/ConditionTree.h"
#include <iostream>

class SQLQueryVisitor : public SQLBaseVisitor
{
private:
    TableHandler tableHandler;

public:
    antlrcpp::Any visitSelectQuery(SQLParser::SelectQueryContext *ctx) override;
    antlrcpp::Any visitCreateQuery(SQLParser::CreateQueryContext *ctx) override;
    // antlrcpp::Any visitColumns(SQLParser::ColumnsContext *ctx) override;
    antlrcpp::Any visitTableValues(SQLParser::TableValuesContext *ctx) override;
    antlrcpp::Any visitInsertQuery(SQLParser::InsertQueryContext *ctx) override;
    antlrcpp::Any visitInsertColumns(SQLParser::InsertColumnsContext *ctx) override;
    antlrcpp::Any visitWhereClause(SQLParser::WhereClauseContext *ctx) override;
    antlrcpp::Any visitCondition(SQLParser::ConditionContext *ctx) override;
    antlrcpp::Any visitAndCondition(SQLParser::AndConditionContext *ctx) override;
    antlrcpp::Any visitOrCondition(SQLParser::OrConditionContext *ctx) override;
    antlrcpp::Any visitBaseCondition(SQLParser::BaseConditionContext *ctx) override;
    antlrcpp::Any visitColumnValueCondition(SQLParser::ColumnValueConditionContext *ctx) override;
};

#endif
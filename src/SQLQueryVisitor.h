#ifndef SQL_QUERY_VISITOR
#define SQL_QUERY_VISITOR

#include "antlr/SQLBaseVisitor.h"
#include "query/condition/ConditionTree.h"
#include "database/DatabaseManager.h"
#include <iostream>
#include "index/IndexHandler.h"
#include "query/condition/ConditionHandler.h"

class SQLQueryVisitor : public SQLBaseVisitor
{
public:
    antlrcpp::Any visitSelectQuery(SQLParser::SelectQueryContext *ctx) override;
    antlrcpp::Any visitCreateQuery(SQLParser::CreateQueryContext *ctx) override;
    antlrcpp::Any visitInsertQuery(SQLParser::InsertQueryContext *ctx) override;
    antlrcpp::Any visitDeleteQuery(SQLParser::DeleteQueryContext *ctx) override;
    antlrcpp::Any visitColumns(SQLParser::ColumnsContext *ctx) override;
    antlrcpp::Any visitTableValues(SQLParser::TableValuesContext *ctx) override;
    antlrcpp::Any visitValues(SQLParser::ValuesContext *ctx) override;
    antlrcpp::Any visitInsertColumns(SQLParser::InsertColumnsContext *ctx) override;
    antlrcpp::Any visitWhereClause(SQLParser::WhereClauseContext *ctx) override;
    antlrcpp::Any visitOrderByClause(SQLParser::OrderByClauseContext *ctx) override;
    antlrcpp::Any visitCondition(SQLParser::ConditionContext *ctx) override;
    antlrcpp::Any visitAndCondition(SQLParser::AndConditionContext *ctx) override;
    antlrcpp::Any visitOrCondition(SQLParser::OrConditionContext *ctx) override;
    antlrcpp::Any visitBaseCondition(SQLParser::BaseConditionContext *ctx) override;
    antlrcpp::Any visitColumnValueCondition(SQLParser::ColumnValueConditionContext *ctx) override;

private:
    std::string currentTableName;
};

#endif
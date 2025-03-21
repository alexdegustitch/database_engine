
// Generated from SQL.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "SQLParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by SQLParser.
 */
class  SQLVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by SQLParser.
   */
    virtual std::any visitQuery(SQLParser::QueryContext *context) = 0;

    virtual std::any visitCreateQuery(SQLParser::CreateQueryContext *context) = 0;

    virtual std::any visitSelectQuery(SQLParser::SelectQueryContext *context) = 0;

    virtual std::any visitInsertQuery(SQLParser::InsertQueryContext *context) = 0;

    virtual std::any visitDeleteQuery(SQLParser::DeleteQueryContext *context) = 0;

    virtual std::any visitUpdateQuery(SQLParser::UpdateQueryContext *context) = 0;

    virtual std::any visitCreateIndex(SQLParser::CreateIndexContext *context) = 0;

    virtual std::any visitInsertColumns(SQLParser::InsertColumnsContext *context) = 0;

    virtual std::any visitColumns(SQLParser::ColumnsContext *context) = 0;

    virtual std::any visitColumn(SQLParser::ColumnContext *context) = 0;

    virtual std::any visitTableName(SQLParser::TableNameContext *context) = 0;

    virtual std::any visitIndexName(SQLParser::IndexNameContext *context) = 0;

    virtual std::any visitWhereClause(SQLParser::WhereClauseContext *context) = 0;

    virtual std::any visitOrderByClause(SQLParser::OrderByClauseContext *context) = 0;

    virtual std::any visitCondition(SQLParser::ConditionContext *context) = 0;

    virtual std::any visitOrCondition(SQLParser::OrConditionContext *context) = 0;

    virtual std::any visitAndCondition(SQLParser::AndConditionContext *context) = 0;

    virtual std::any visitBaseCondition(SQLParser::BaseConditionContext *context) = 0;

    virtual std::any visitColumnValueCondition(SQLParser::ColumnValueConditionContext *context) = 0;

    virtual std::any visitOperator(SQLParser::OperatorContext *context) = 0;

    virtual std::any visitTableValues(SQLParser::TableValuesContext *context) = 0;

    virtual std::any visitTableValue(SQLParser::TableValueContext *context) = 0;

    virtual std::any visitValues(SQLParser::ValuesContext *context) = 0;

    virtual std::any visitValue(SQLParser::ValueContext *context) = 0;


};


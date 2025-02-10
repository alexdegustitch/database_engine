
// Generated from SQL.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "SQLParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by SQLParser.
 */
class  SQLListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterQuery(SQLParser::QueryContext *ctx) = 0;
  virtual void exitQuery(SQLParser::QueryContext *ctx) = 0;

  virtual void enterSelectQuery(SQLParser::SelectQueryContext *ctx) = 0;
  virtual void exitSelectQuery(SQLParser::SelectQueryContext *ctx) = 0;

  virtual void enterInsertQuery(SQLParser::InsertQueryContext *ctx) = 0;
  virtual void exitInsertQuery(SQLParser::InsertQueryContext *ctx) = 0;

  virtual void enterDeleteQuery(SQLParser::DeleteQueryContext *ctx) = 0;
  virtual void exitDeleteQuery(SQLParser::DeleteQueryContext *ctx) = 0;

  virtual void enterUpdateQuery(SQLParser::UpdateQueryContext *ctx) = 0;
  virtual void exitUpdateQuery(SQLParser::UpdateQueryContext *ctx) = 0;

  virtual void enterColumns(SQLParser::ColumnsContext *ctx) = 0;
  virtual void exitColumns(SQLParser::ColumnsContext *ctx) = 0;

  virtual void enterColumn(SQLParser::ColumnContext *ctx) = 0;
  virtual void exitColumn(SQLParser::ColumnContext *ctx) = 0;

  virtual void enterTableName(SQLParser::TableNameContext *ctx) = 0;
  virtual void exitTableName(SQLParser::TableNameContext *ctx) = 0;

  virtual void enterWhereClause(SQLParser::WhereClauseContext *ctx) = 0;
  virtual void exitWhereClause(SQLParser::WhereClauseContext *ctx) = 0;

  virtual void enterOrderByClause(SQLParser::OrderByClauseContext *ctx) = 0;
  virtual void exitOrderByClause(SQLParser::OrderByClauseContext *ctx) = 0;

  virtual void enterCondition(SQLParser::ConditionContext *ctx) = 0;
  virtual void exitCondition(SQLParser::ConditionContext *ctx) = 0;

  virtual void enterOperator(SQLParser::OperatorContext *ctx) = 0;
  virtual void exitOperator(SQLParser::OperatorContext *ctx) = 0;

  virtual void enterValues(SQLParser::ValuesContext *ctx) = 0;
  virtual void exitValues(SQLParser::ValuesContext *ctx) = 0;

  virtual void enterValue(SQLParser::ValueContext *ctx) = 0;
  virtual void exitValue(SQLParser::ValueContext *ctx) = 0;


};


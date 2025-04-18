
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

  virtual void enterCreateQuery(SQLParser::CreateQueryContext *ctx) = 0;
  virtual void exitCreateQuery(SQLParser::CreateQueryContext *ctx) = 0;

  virtual void enterSelectQuery(SQLParser::SelectQueryContext *ctx) = 0;
  virtual void exitSelectQuery(SQLParser::SelectQueryContext *ctx) = 0;

  virtual void enterInsertQuery(SQLParser::InsertQueryContext *ctx) = 0;
  virtual void exitInsertQuery(SQLParser::InsertQueryContext *ctx) = 0;

  virtual void enterDeleteQuery(SQLParser::DeleteQueryContext *ctx) = 0;
  virtual void exitDeleteQuery(SQLParser::DeleteQueryContext *ctx) = 0;

  virtual void enterUpdateQuery(SQLParser::UpdateQueryContext *ctx) = 0;
  virtual void exitUpdateQuery(SQLParser::UpdateQueryContext *ctx) = 0;

  virtual void enterCreateIndex(SQLParser::CreateIndexContext *ctx) = 0;
  virtual void exitCreateIndex(SQLParser::CreateIndexContext *ctx) = 0;

  virtual void enterInsertColumns(SQLParser::InsertColumnsContext *ctx) = 0;
  virtual void exitInsertColumns(SQLParser::InsertColumnsContext *ctx) = 0;

  virtual void enterColumns(SQLParser::ColumnsContext *ctx) = 0;
  virtual void exitColumns(SQLParser::ColumnsContext *ctx) = 0;

  virtual void enterColumn(SQLParser::ColumnContext *ctx) = 0;
  virtual void exitColumn(SQLParser::ColumnContext *ctx) = 0;

  virtual void enterTableName(SQLParser::TableNameContext *ctx) = 0;
  virtual void exitTableName(SQLParser::TableNameContext *ctx) = 0;

  virtual void enterIndexName(SQLParser::IndexNameContext *ctx) = 0;
  virtual void exitIndexName(SQLParser::IndexNameContext *ctx) = 0;

  virtual void enterWhereClause(SQLParser::WhereClauseContext *ctx) = 0;
  virtual void exitWhereClause(SQLParser::WhereClauseContext *ctx) = 0;

  virtual void enterOrderByClause(SQLParser::OrderByClauseContext *ctx) = 0;
  virtual void exitOrderByClause(SQLParser::OrderByClauseContext *ctx) = 0;

  virtual void enterCondition(SQLParser::ConditionContext *ctx) = 0;
  virtual void exitCondition(SQLParser::ConditionContext *ctx) = 0;

  virtual void enterOrCondition(SQLParser::OrConditionContext *ctx) = 0;
  virtual void exitOrCondition(SQLParser::OrConditionContext *ctx) = 0;

  virtual void enterAndCondition(SQLParser::AndConditionContext *ctx) = 0;
  virtual void exitAndCondition(SQLParser::AndConditionContext *ctx) = 0;

  virtual void enterBaseCondition(SQLParser::BaseConditionContext *ctx) = 0;
  virtual void exitBaseCondition(SQLParser::BaseConditionContext *ctx) = 0;

  virtual void enterColumnValueCondition(SQLParser::ColumnValueConditionContext *ctx) = 0;
  virtual void exitColumnValueCondition(SQLParser::ColumnValueConditionContext *ctx) = 0;

  virtual void enterOperator(SQLParser::OperatorContext *ctx) = 0;
  virtual void exitOperator(SQLParser::OperatorContext *ctx) = 0;

  virtual void enterTableValues(SQLParser::TableValuesContext *ctx) = 0;
  virtual void exitTableValues(SQLParser::TableValuesContext *ctx) = 0;

  virtual void enterTableValue(SQLParser::TableValueContext *ctx) = 0;
  virtual void exitTableValue(SQLParser::TableValueContext *ctx) = 0;

  virtual void enterColumnConstraint(SQLParser::ColumnConstraintContext *ctx) = 0;
  virtual void exitColumnConstraint(SQLParser::ColumnConstraintContext *ctx) = 0;

  virtual void enterValues(SQLParser::ValuesContext *ctx) = 0;
  virtual void exitValues(SQLParser::ValuesContext *ctx) = 0;

  virtual void enterValue(SQLParser::ValueContext *ctx) = 0;
  virtual void exitValue(SQLParser::ValueContext *ctx) = 0;

  virtual void enterDataType(SQLParser::DataTypeContext *ctx) = 0;
  virtual void exitDataType(SQLParser::DataTypeContext *ctx) = 0;


};


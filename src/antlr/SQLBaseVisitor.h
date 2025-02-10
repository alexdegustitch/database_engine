
// Generated from SQL.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "SQLVisitor.h"


/**
 * This class provides an empty implementation of SQLVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  SQLBaseVisitor : public SQLVisitor {
public:

  virtual std::any visitQuery(SQLParser::QueryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSelectQuery(SQLParser::SelectQueryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitInsertQuery(SQLParser::InsertQueryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDeleteQuery(SQLParser::DeleteQueryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUpdateQuery(SQLParser::UpdateQueryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitColumns(SQLParser::ColumnsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitColumn(SQLParser::ColumnContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTableName(SQLParser::TableNameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitWhereClause(SQLParser::WhereClauseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOrderByClause(SQLParser::OrderByClauseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCondition(SQLParser::ConditionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOperator(SQLParser::OperatorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitValues(SQLParser::ValuesContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitValue(SQLParser::ValueContext *ctx) override {
    return visitChildren(ctx);
  }


};


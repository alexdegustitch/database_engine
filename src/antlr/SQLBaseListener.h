
// Generated from SQL.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "SQLListener.h"


/**
 * This class provides an empty implementation of SQLListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  SQLBaseListener : public SQLListener {
public:

  virtual void enterQuery(SQLParser::QueryContext * /*ctx*/) override { }
  virtual void exitQuery(SQLParser::QueryContext * /*ctx*/) override { }

  virtual void enterCreateQuery(SQLParser::CreateQueryContext * /*ctx*/) override { }
  virtual void exitCreateQuery(SQLParser::CreateQueryContext * /*ctx*/) override { }

  virtual void enterSelectQuery(SQLParser::SelectQueryContext * /*ctx*/) override { }
  virtual void exitSelectQuery(SQLParser::SelectQueryContext * /*ctx*/) override { }

  virtual void enterInsertQuery(SQLParser::InsertQueryContext * /*ctx*/) override { }
  virtual void exitInsertQuery(SQLParser::InsertQueryContext * /*ctx*/) override { }

  virtual void enterDeleteQuery(SQLParser::DeleteQueryContext * /*ctx*/) override { }
  virtual void exitDeleteQuery(SQLParser::DeleteQueryContext * /*ctx*/) override { }

  virtual void enterUpdateQuery(SQLParser::UpdateQueryContext * /*ctx*/) override { }
  virtual void exitUpdateQuery(SQLParser::UpdateQueryContext * /*ctx*/) override { }

  virtual void enterCreateIndex(SQLParser::CreateIndexContext * /*ctx*/) override { }
  virtual void exitCreateIndex(SQLParser::CreateIndexContext * /*ctx*/) override { }

  virtual void enterInsertColumns(SQLParser::InsertColumnsContext * /*ctx*/) override { }
  virtual void exitInsertColumns(SQLParser::InsertColumnsContext * /*ctx*/) override { }

  virtual void enterColumns(SQLParser::ColumnsContext * /*ctx*/) override { }
  virtual void exitColumns(SQLParser::ColumnsContext * /*ctx*/) override { }

  virtual void enterColumn(SQLParser::ColumnContext * /*ctx*/) override { }
  virtual void exitColumn(SQLParser::ColumnContext * /*ctx*/) override { }

  virtual void enterTableName(SQLParser::TableNameContext * /*ctx*/) override { }
  virtual void exitTableName(SQLParser::TableNameContext * /*ctx*/) override { }

  virtual void enterIndexName(SQLParser::IndexNameContext * /*ctx*/) override { }
  virtual void exitIndexName(SQLParser::IndexNameContext * /*ctx*/) override { }

  virtual void enterWhereClause(SQLParser::WhereClauseContext * /*ctx*/) override { }
  virtual void exitWhereClause(SQLParser::WhereClauseContext * /*ctx*/) override { }

  virtual void enterOrderByClause(SQLParser::OrderByClauseContext * /*ctx*/) override { }
  virtual void exitOrderByClause(SQLParser::OrderByClauseContext * /*ctx*/) override { }

  virtual void enterCondition(SQLParser::ConditionContext * /*ctx*/) override { }
  virtual void exitCondition(SQLParser::ConditionContext * /*ctx*/) override { }

  virtual void enterOperator(SQLParser::OperatorContext * /*ctx*/) override { }
  virtual void exitOperator(SQLParser::OperatorContext * /*ctx*/) override { }

  virtual void enterTableValues(SQLParser::TableValuesContext * /*ctx*/) override { }
  virtual void exitTableValues(SQLParser::TableValuesContext * /*ctx*/) override { }

  virtual void enterTableValue(SQLParser::TableValueContext * /*ctx*/) override { }
  virtual void exitTableValue(SQLParser::TableValueContext * /*ctx*/) override { }

  virtual void enterValues(SQLParser::ValuesContext * /*ctx*/) override { }
  virtual void exitValues(SQLParser::ValuesContext * /*ctx*/) override { }

  virtual void enterValue(SQLParser::ValueContext * /*ctx*/) override { }
  virtual void exitValue(SQLParser::ValueContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};


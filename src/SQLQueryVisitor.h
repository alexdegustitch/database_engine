#ifndef SQL_QUERY_VISITOR
#define SQL_QUERY_VISITOR

#include "antlr/SQLBaseVisitor.h"
#include <iostream>

class SQLQueryVisitor : public SQLBaseVisitor
{
public:
    antlrcpp::Any visitSelectQuery(SQLParser::SelectQueryContext *ctx) override;
};

#endif
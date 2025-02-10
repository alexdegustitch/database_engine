#ifndef QUERY_ENGINE
#define QUERY_ENGINE
#include <string>
#include "antlr/SQLLexer.h"
#include "antlr/SQLParser.h"
#include "antlr/SQLBaseVisitor.h"
#include "SQLQueryVisitor.h"
#include <antlr4-runtime.h>

class QueryEngine
{
public:
    void executeQuery(const std::string &query);
};

#endif
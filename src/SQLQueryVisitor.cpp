#include "SQLQueryVisitor.h"

antlrcpp::Any SQLQueryVisitor::visitSelectQuery(SQLParser::SelectQueryContext *ctx)
{
    std::cout << "Visiting Select Query..." << ctx->tableName()->getText() << std::endl;

    return nullptr;
}
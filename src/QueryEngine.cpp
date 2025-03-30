#include "QueryEngine.h"

void QueryEngine::executeQuery(const std::string &query)
{
    antlr4::ANTLRInputStream input(query);
    SQLLexer lexer(&input);
    antlr4::CommonTokenStream tokens(&lexer);
    SQLParser parser(&tokens);

    SQLParser::QueryContext *tree = parser.query();
    SQLQueryVisitor visitor;
    try
    {
        std::cout << "I am here! " << std::endl;
        visitor.visitQuery(tree);
        std::cout << "I am here - end of execute query! " << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }
}
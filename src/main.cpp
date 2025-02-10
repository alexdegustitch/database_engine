#include "QueryEngine.h"
#include <iostream>
#include <string>

int main()
{
    QueryEngine engine;
    std::string query;
    while (true)
    {
        std::cout << "SQL> " << std::endl;

        std::getline(std::cin, query);
        if (query == "exit")
        {
            break;
        }
        engine.executeQuery(query);
    }

    return 0;
}
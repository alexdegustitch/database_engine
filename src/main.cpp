#include "QueryEngine.h"
#include "catalog/SystemTableManager.h"
#include <iostream>
#include <string>

int main()
{
    SystemTableManager::getInstance().loadAllSchemas();
    QueryEngine engine;
    std::string query;
    while (true)
    {
        std::cout << "SQL> ";

        std::getline(std::cin, query);
        if (query == "exit")
        {
            break;
        }
        engine.executeQuery(query);
    }

    return 0;
}

/*
#include "bplustree/BPlusTree.h"
#include <iostream>
#include <string>

int main()
{
    int m;
    std::cout << "Enter the max keys: ";
    std::cin >> m;

    std::string fileName;
    std::cout << "Enter file name: ";
    std::cin >> fileName;

    // Construct full file path
    std::string filePath = "meta/indexes/" + fileName + ".idx";

    // std::cout << filePath << std::endl;
    BPlusTree tree(filePath, m);
    // return 0;
    std::vector<int> keys = {6, 16, 20, 27, 30, 35, 41, 45, 57, 60, 65, 71, 73, 80, 84, 89, 100};
    for (int k : keys)
    {
        // std::cout << std::dec;
        std::cout << "Key: " << k << std::endl;
        // std::cout << std::hex;
        tree.insert(k);
        tree.printBPlusTree();
    }
for (int i = 0; i < 1000; i++)
{
    tree.insert(i);
}
bool go = true;
while (go)
{

    std::cout << "1 - Print Tree" << std::endl;
    std::cout << "2 - Search Key" << std::endl;
    std::cout << "3 - Insert Key" << std::endl;
    std::cout << "4 - Delete Key" << std::endl;
    std::cout << "5 - Delete Range of Keys" << std::endl;
    std::cout << "6 - Erase Tree" << std::endl;
    std::cout << "7 - Print Leaves" << std::endl;
    std::cout << "0 - Exit" << std::endl;

    int menu;
    int key;
    std::cin >> menu;
    switch (menu)
    {
    case 1:
        tree.printBPlusTree();
        break;
    case 2:
        std::cout << "Key: ";
        std::cin >> key;
        std::cout << tree.search(key) << std::endl;
        break;
    case 3:
        std::cout << "Key: ";
        std::cin >> key;
        tree.insert(key);
        break;
    case 4:
        std::cout << "Key: ";
        std::cin >> key;
        tree.delete_key(key);
        break;
    case 5:
        int keyStart, keyEnd;
        std::cout << "Range Start: ";
        std::cin >> keyStart;
        std::cout << "Range End: ";
        std::cin >> keyEnd;
        tree.deleteRangeOfKeys(keyStart, keyEnd);
        break;
    case 6:
        tree.eraseTree();
        break;
    case 7:
        tree.printLeaves();
        break;
    default:
        go = false;
        // tree.eraseTree();
        break;
    }
    tree.printBPlusTree();
}
}
*/
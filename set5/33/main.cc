#include <set>
#include <string>
#include <iostream>
#include <sstream>

int main()
{
    std::set<std::string> set;
    std::string line;
    std::cout << "Type words to insert into container: ";
    
    std::getline(std::cin, line);

    std::istringstream stream(line);
    std::string word;

    while (stream >> word)
    {
        set.insert(word);
    } 

    std::cout << "Ordered words after insertion into container:";
    for (const auto& word : set)
    {
        std::cout << " " << word;
    }

    std::cout << std::endl;

    return 0;
}
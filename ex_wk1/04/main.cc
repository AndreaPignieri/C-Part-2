#include <iostream>
#include <fstream>
#include <string>

//bool
std::istream& promptGet(std::istream &in, std::string &str)
{
    std::cout << "Enter a line or ^D\n";     // ^D signals end-of-input
    // return static_cast<bool>(getline(in, str));
    return (getline(in, str));
}

void process(std::string str)
{
    std::cout << str << std::endl;
}

int main()
{
    std::string str;
    while (promptGet(std::cin, str))
        process(str);
}


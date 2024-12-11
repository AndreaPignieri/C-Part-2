#include "str.hh"
#include <iostream>

using namespace std;

int main()
{
    String str = "Hello world";

    str.string::insert(11, 4, '!');

    cout << str << '\n';

    std::cout << (str == str) << "\n";
    std::cout << (str != str) << "\n";  
    std::cout << (str < str) << "\n";   
    std::cout << (str <= str) << "\n"; 
    std::cout << (str > str) << "\n";   
    std::cout << (str >= str) << "\n";  
}
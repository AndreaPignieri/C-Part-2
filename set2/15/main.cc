#include <string>
#include <iostream>

class Example
{
    std::string name;

    public:
        Example()
        {
            std::cout << "Example constructor\n";
            name = "Hello";
        };
        ~Example()
        {
            std::cout << "Example destructor\n";
        };
        void fun()
        {
            std::cout << "Function inside example\n";
        }
};

int main()
{
    Example *example = new Example;
    example->fun();
    std::exit(3);
}
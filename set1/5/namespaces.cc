#include <iostream>

namespace First{ 
    enum Enum{};
    void fun(First::Enum symbol)
    {
        std::cout << "Fun called from namespace First" << std::endl;
    };
}

namespace Second{
    void fun(First::Enum symbol)
    {
        std::cout << "Fun called from namespace Second" << std::endl;
    };
}


/* void fun(First::Enum symbol)
{
    std::cout << "New function" << std::endl;
}*/

int main()
{
    First::Enum symbol = {};
    fun(symbol);
}

#include <iostream>
using namespace std;

namespace First
{
    enum Enum{};

    void fun(Enum symbol)
    {
        cout << "First::fun() called \n";
    }
}

namespace Second
{
    void fun(First::Enum symbol)
    {
        cout << "Second::fun() called \n";
    }
}

int main()
{
    fun(static_cast<First::Enum>(0));   
}
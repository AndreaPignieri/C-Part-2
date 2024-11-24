#include <iostream>

// Define the First namespace
namespace First
{
    enum Enum {}; // Empty enum declaration

    void fun(Enum symbol)
    {
        std::cout << "First::fun called\n";
    }
}

// Define the Second namespace
namespace Second
{
    void fun(First::Enum symbol)
    {
        std::cout << "Second::fun called\n";
    }
}

// Function declared above main in the global namespace
void fun(First::Enum symbol)
{
    std::cout << "Global fun called\n";
}

int main()
{
    First::Enum symbol; // Declare a symbol of type First::Enum

    fun(symbol); // Call fun; by default, this calls First::fun because of ADL.

    // Explicitly call Second::fun
    Second::fun(symbol);

    // Explicitly call the global fun
    ::fun(symbol);

    return 0;
}


#include "base/base.ih"

int main()
{
    cout << "Calling Derived Default:\n";
    Derived der1;

    cout << "Calling Derived Copy:\n";
    Derived der2 = der1;

    cout << "Calling Derived Move:\n";
    Derived der3 = move(der1);
}

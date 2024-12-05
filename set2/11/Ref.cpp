#include "num.hh"
#include <iostream>

using namespace std;

int main()
try 
{
    Num object(0);
    throw object;
}

catch(Num &object)
{
    cerr << "this is version (" << object.get() << ")\n";
}

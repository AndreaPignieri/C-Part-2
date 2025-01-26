#include "workforce/workforce.hh"
#include <iostream>

using namespace std;

int main()
try
{
    Workforce workforce;
    workforce.run("input.txt", "output.txt");
}
catch(...)
{
    cerr << "a file didn't open";
}
#include "workforce/workforce.hh"
#include <iostream>

using namespace std;

int main(int argc, char **argv)
try
{
    Workforce workforce;
    workforce.run(*(argv + 1), *(argv + 2));
}
catch(...)
{
    cerr << "a file didn't open";
}
#include "Demo.hh"
 
int main()
try
{
    Demo demo{1};
}
catch (...)
{
    std::cerr << "main\n";
}
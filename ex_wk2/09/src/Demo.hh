#include <iostream>

class Demo
{
    public:
        Demo();
        Demo(int constructorArg);
        ~Demo();
};
Demo::~Demo()
{
    std::cout << "Destructor of demo" << std::endl;
}

Demo::Demo(int constructorArg)
try
{
    try
    {
        std::cout << "Constructor of demo with argument: " << constructorArg;
        std::cout << std::endl;
        throw constructorArg;
    }
    catch(int exception)
    {
    }
}
catch(int exception)
{
    std::cout << "Exception caught\n";
}
#include <iostream>

using namespace std;

struct Demo
{
    Demo();          //default constructor
    Demo(int value); //constructor accepts int
    ~Demo()          //destructor
    {
        cerr << "Destructor called.\n";
    }
};

//Constructor for Demo with int
Demo::Demo(int value)
{
    //the throw statement was originally here
    //and caught in main
    try 
    {
        throw value;         //the moved throw statement 
        cerr << value << "\n";
    }
    catch (int caught)
    {
        cerr << "Caught value: " << caught << "\n";
    }
}
//Provided in question
int main()
{
    try
    {
	Demo demo{1};
    }
    catch (...)
    {
	cerr << "main\n";
    }
}

#ifndef INCLUDED_BASE_
#define INCLUDED_BASE_
#include <iostream>

using namespace std;

class Base
{
    public:
        //default constructor
        Base()
        {
            cout << "Base: Default Constructor.\n";
        }
        //copy constructor
        Base(const Base&)
        {
            cout << "Base: Copy Constructor.\n";
        }
        //move constructor
        Base(Base&&)
        {
            cout << "Base: Move Constructor.\n";
        }
};

//Derived class inheriting Base
class Derived : public Base
{
    public:
        //default constructor
        Derived() 
        {}
        //Copy constructor
        Derived(const Derived &src)
        {}
        //Move constructor
        Derived(Derived &&src)
        {}
};

#endif

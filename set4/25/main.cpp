#include "base/base.hh"
#include "derived/derived.hh"
#include "message/message.hh"

#include <iostream>

int main()
{
    Base base;
    Derived derived("derived text");
    Message mssg1(base);
    
    Base &br = derived;
    Message mssg2(br);

    mssg1.show(std::cout);      //Base::vHello called
    mssg2.show(std::cout);      //Derived::vHello called

}
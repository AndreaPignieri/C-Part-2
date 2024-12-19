#ifndef BASE_HH
#define BASE_HH

#include <fstream>
#include <iostream>

class Base
{
    public:
        Base() = default;
        virtual ~Base() = default;
            //polymorphism is used so the destructor needs
            //to be virtual too, to handle pointers

        void hello(std::ostream &out) const;
        virtual void vHello (std::ostream &out) const;
            //creates Vtable with &Base::vHello
        
};

inline void Base::hello(std::ostream &out) const
{
    vHello(out);  //it calls the vHello indicated by the vTable
}

inline void Base::vHello(std::ostream &out) const
{
    out << "hello from Base\n";
}

#endif
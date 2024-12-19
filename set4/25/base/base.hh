#ifndef BASE_HH
#define BASE_HH

#include <fstream>

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
}//an exception can be made to the rule of no inline implementation 
//to virtual members, since we know that vHello will be first called
//by a Base object thus creating an adress for it at the Vtable

#endif

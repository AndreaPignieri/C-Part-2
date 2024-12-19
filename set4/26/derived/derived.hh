#ifndef DERIVED_HH
#define DERIVED_HH

#include "../base/base.hh"
#include <fstream>

Base **derivedFactory(size_t size);

class Derived: public Base
{
    std::string d_text;

    public:
        Derived();
        Derived(std::string text);
        ~Derived() = default;

        void *operator new(size_t size); 
            //to properly allocate memory to the array of pointers pointing
            //to Derived objects
        void operator delete(void *ptr);

        void vHello(std::ostream &out) const override;
            //in the Vtable it has &Derived::vHello
};

inline Derived::Derived()
:
    Base(),
    d_text("hello from Derived")
{}

inline Derived::Derived(std::string text)
:
    Base(),       //initialise Base() classes first
    d_text(text)
{}

inline void *Derived::operator new(size_t size)
{
    std::cout<<"making derived obj\n";
    return ::operator new(size);
}

inline void Derived::operator delete(void *ptr)
{
    std::cout<<"we delete these derived obj\n";
    ::delete static_cast<Derived*>(ptr);
}

inline void Derived::vHello(std::ostream &out) const
{
    out << d_text << '\n';
}


#endif

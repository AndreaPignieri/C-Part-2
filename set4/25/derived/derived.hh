#ifndef DERIVED_HH
#define DERIVED_HH

#include <fstream>

class Derived: public Base
{
    std::string d_text;

    public:
        Derived(std::string text);
        ~Derived() = default;

        void vHello(std::ostream &out) const override;
            //in the Vtable it has &Derived::vHello
};

inline Derived::Derived(std::string text)
:
    Base(),       //initialise Base() classes first
    d_text(text)
{}

inline void Derived::vHello(std::ostream &out) const
{
    out << d_text << '\n';
}

#endif
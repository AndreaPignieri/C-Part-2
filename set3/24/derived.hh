#ifndef _DERIVED_HH
#define _DERIVED_HH

#include "base.hh"
#include <iosfwd>


class Derived: public Base
{
    std::ofstream out;

    public:
        Derived(std::string const &name);
};

#endif
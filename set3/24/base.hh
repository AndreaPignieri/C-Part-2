#ifndef _BASE_HH
#define _BASE_HH

#include <fstream>

class Base
{
    std::ostream &d_out;

    public:
        Base(std::ostream &out);    // assigns out to d_out

            // other members
};

inline Base::Base(std::ostream &out)
:
    d_out(out)
{}

#endif
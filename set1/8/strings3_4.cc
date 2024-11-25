#include "strings.ih"

Strings &Strings::operator=(Strings const &rhs)
{
    if (this != &rhs)
    {
        if (d_shared && --(*d_shared) == 0)
        {
            delete[] d_str;
            delete d_shared;
        }

        d_shared = rhs.d_shared;
        d_size = rhs.d_size;
        d_str = rhs.d_str;

        ++(*d_shared);
    }
    return *this;
}

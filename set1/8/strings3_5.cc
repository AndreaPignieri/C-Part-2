#include "strings.ih"

Strings &Strings::operator=(Strings &&rhs) noexcept
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

        rhs.d_shared = nullptr;
        rhs.d_str = nullptr;
        rhs.d_size = 0;
    }
    return *this;
}

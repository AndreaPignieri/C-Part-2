#include "strings.ih"

Strings &Strings::operator=(Strings const &rhs)
{
    if (this != &rhs)
    {
        delete[] d_str;

        d_size = rhs.d_size;
        d_str = new std::string[d_size];

        for (size_t idx = 0; idx < d_size; ++idx)
        {
            d_str[idx] = rhs.d_str[idx];
        }
    }
    return *this;
}

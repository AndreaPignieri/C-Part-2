#include "strings.ih"

std::string const &Strings::operator[](size_t idx) const
{
    return d_str[idx];
}

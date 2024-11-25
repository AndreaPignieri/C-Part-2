#include "strings.ih"

std::string const &Strings::at(size_t idx) const
{
    return d_str[idx];
}

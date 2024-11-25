#include "strings.ih"

std::string &Strings::at(size_t idx)
{
    return d_str[idx];
}

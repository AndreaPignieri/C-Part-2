#include "strings.ih"

//read-only operator[]
string const &Strings::operator[](size_t idx) const
{
    return d_str[idx];
}

//operator[]
string &Strings::operator[](size_t idx)
{
    deepCopy(idx);     //COW
    return d_str[idx];
}

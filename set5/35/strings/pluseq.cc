#include "strings.ih"
//operator +=
Strings &Strings::operator+=(string const &str)
{
    d_str.push_back(str); //append string to vector
    return *this    //return this object
}

#include "strings.ih"
//operator +=
Strings &Strings::operator+=(string const &str)
{
    d_str.push_back(make_shared<string>(str)); //append string to vector
    return *this    //return this object
}

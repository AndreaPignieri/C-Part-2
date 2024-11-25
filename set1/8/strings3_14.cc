#include "strings.ih"

Strings::Proxy &Strings::Proxy::operator=(std::string const &value)
{
    d_owner->cow();
    d_owner->d_str[d_index] = value;
    return *this;
}

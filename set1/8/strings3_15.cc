#include "strings.ih"

Strings::Proxy::operator std::string() const
{
    return d_owner->d_str[d_index];
}

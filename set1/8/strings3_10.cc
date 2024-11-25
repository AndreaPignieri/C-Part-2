#include "strings.ih"

Strings::Proxy Strings::operator[](size_t idx)
{
    return Proxy(this, idx);
}

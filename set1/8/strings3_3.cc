#include "strings.ih"

Strings::Strings(Strings const &other)
    : d_shared(other.d_shared), d_size(other.d_size), d_str(other.d_str)
{
    ++(*d_shared);
}

#include "strings.ih"

Strings::Strings(Strings &&tmp) noexcept
    : d_shared(tmp.d_shared), d_size(tmp.d_size), d_str(tmp.d_str)
{
    tmp.d_shared = nullptr;
    tmp.d_str = nullptr;
    tmp.d_size = 0;
}

#include "strings.ih"

std::ostream &operator<<(std::ostream &out, Strings::Proxy const &proxy)
{
    out << static_cast<std::string>(proxy);
    return out;
}

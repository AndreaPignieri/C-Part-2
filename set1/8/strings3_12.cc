#include "strings.ih"

void Strings::allocate(size_t size)
{
    d_size = size;
    d_shared = new size_t(1);
    d_str = new std::string[d_size];
}

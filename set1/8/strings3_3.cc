#include "strings.ih"

Strings::~Strings()
{
    if (d_shared && --(*d_shared) == 0)
    {
        delete[] d_str;
        delete d_shared;
    }
}

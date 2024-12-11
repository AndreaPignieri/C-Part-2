#include "str.ih"

Str::Str(size_t count, string const &str)
:
    string()
{
    append(str);
}
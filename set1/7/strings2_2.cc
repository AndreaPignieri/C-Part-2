#include "strings.ih"

Strings::Strings(char **environLike)
{
    size_t count = 0;

    while (environLike[count])
    {
        ++count;
    }

    d_size = count;
    d_str = new std::string[d_size];

    for (size_t idx = 0; idx < d_size; ++idx)
    {
        d_str[idx] = environLike[idx];
    }
}

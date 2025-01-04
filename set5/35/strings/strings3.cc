#include "strings.ih"
//constructor 3
Strings::Strings(char **environLike)
{
    while (*environLike)
        d_str.push_back(*environLike++);
}

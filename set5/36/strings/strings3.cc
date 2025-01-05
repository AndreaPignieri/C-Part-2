#include "strings.ih"
//constructor 3, environment-like array
Strings::Strings(char **environLike)
{
    while (*environLike)
        d_str.push_backmake_shared<string>(*environLike++));
}

#include "strings.ih"
//constructor 2
Strings::Strings(int argc, char **argv)
{
    for (size_t idx = 0; idx != argc; ++idx)
        d_str.push_back(argv[idx]); //append arguments to d_str
}

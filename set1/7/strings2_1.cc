#include "strings.ih"

Strings::Strings(int argc, char **argv)
    : d_size(argc), d_str(new std::string[d_size])
{
    for (size_t idx = 0; idx < d_size; ++idx)
    {
        d_str[idx] = argv[idx];
    }
}

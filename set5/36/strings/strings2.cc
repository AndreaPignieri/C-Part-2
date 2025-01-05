#include "strings.ih"
//constructor 2
Strings::Strings(int argc, char **argv)
{
    for (size_t idx = 0; idx != argc; ++idx)
        //append arguments to d_str
        d_str.push_back(make_shared<string>(argv[idx])); 
}

#include "strings.ih"

void Strings::cow()
{
    if (*d_shared > 1)
    {
        --(*d_shared);

        std::string *newData = new std::string[d_size];

        for (size_t idx = 0; idx < d_size; ++idx)
        {
            newData[idx] = d_str[idx];
        }

        d_shared = new size_t(1);
        d_str = newData;
    }
}

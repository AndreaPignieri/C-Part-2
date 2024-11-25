#include "numbers.ih"

size_t Numbers::compare(Numbers const &rhs) const
{
    for (size_t idx = 0; idx != d_size; ++idx)
    {
        if (d_nums[idx] != rhs[idx])
            return idx + 1;
    }

    return 0;
}
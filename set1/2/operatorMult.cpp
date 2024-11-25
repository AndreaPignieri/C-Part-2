#include "numbers.ih"

Numbers Numbers::operator*(int rhs) const
{
    Numbers tmp(d_size);
    for (size_t idx = 0; idx != d_size; ++idx)
        tmp[idx] = d_nums[idx] * rhs;

    return tmp;
}

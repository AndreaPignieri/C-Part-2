#include "../headers/Numbers.ih"

void Numbers::times(int const rhs)
{
    for (size_t idx = 0; idx != d_size; ++idx)
    {
        d_nums[idx] *= rhs;
    }
}
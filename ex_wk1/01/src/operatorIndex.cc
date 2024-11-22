#include "../headers/Numbers.hh"

int &Numbers::operatorIndex(size_t idx) const
{
    boundary(idx);
    return d_nums[idx];
}
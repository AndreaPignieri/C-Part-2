#include "numbers.ih"

Numbers Numbers::operator/(int rhs)
{
    Numbers tmp( d_size );
    if(rhs == 0)
    {
        cerr << "You cannot divide by 0\n";
        return *this;
    }

    for (size_t idx = 0; idx != d_size; ++idx)
        tmp[idx] = d_nums[idx] / rhs;

    return tmp;
}
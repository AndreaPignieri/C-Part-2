#include "numbers.ih"

Numbers Numbers::operator+(Numbers const &other)
{
    Numbers tmp( d_size );
    if (d_size != other.d_size)
    {
        cerr << "Numbers of different size cannot be added together";
        return *this;
    }

    for (size_t idx = 0; idx != d_size; ++idx)
        tmp[idx] = d_nums[idx] + other[idx];

    return tmp;
}
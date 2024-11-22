#include "../headers/Numbers.ih"

void Numbers::minus(Numbers const &rhs)
{
    if (d_size != rhs.d_size)
    {
        std::cerr << "Unequal sizes for addition" << std::endl;
        return; 
    }
    
    for (size_t idx = 0; idx != d_size; ++idx)
    {
        d_nums[idx] -= rhs.d_nums[idx];
    }
}
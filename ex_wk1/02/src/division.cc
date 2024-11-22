#include "../headers/Numbers.ih"

void Numbers::division(int const rhs)
{
    if (rhs == 0)
    {
        std::cerr << "Right-hand side can not be 0 for division" << std::endl;
        return;
    }
    
    for (size_t idx = 0; idx != d_size; ++idx)
    {
        d_nums[idx] /= rhs;
    }
}
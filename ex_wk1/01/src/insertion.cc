#include "../headers/Numbers.ih"

std::ostream &operator<<(std::ostream &out, Numbers &numbers)
{
    for (size_t idx = 0; idx != numbers.d_size; ++idx)
    {
        out << numbers.d_nums[idx] << " ";
    }
    return out;
}
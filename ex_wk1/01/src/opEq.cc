#include "../headers/Numbers.ih"

bool Numbers::operator==(Numbers const &other) const
{
    if (d_size != other.d_size)
        return false;
    
    bool retValue = true;
    size_t idx = 0;

    while (retValue == true && idx != d_size)
    {
        if (d_nums[idx] != other.d_nums[idx])
            retValue = false;
        ++idx;
    }
    return retValue;
}
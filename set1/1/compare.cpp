#include "numbers.ih"

size_t Numbers::compare(Numbers const &rhs) const
{//will return the first index the 2 objects have different
    for (size_t idx = 0; idx != d_size; ++idx)
    {
        if (d_nums[idx] != rhs[idx])
            return idx + 1;    //allows it to be used as bool func
                        //returning false if they have a different value
    }

    return 0;
}

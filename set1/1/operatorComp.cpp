#include "numbers.ih"

strong_ordering operator<=>(Numbers const &lhs, Numbers const &rhs)
{
    if (lhs.d_size < rhs.d_size)
        return strong_ordering::less;
        
    else if (lhs.d_size > rhs.d_size)
        return strong_ordering::greater;

    //idx is defined to indicate the first number that differs
    //in case there is any. (there is the small adjusting needed
    //to be made for idx since it's pointing one further (explained in compare)
    else if (size_t idx = lhs.compare(rhs))
        return lhs[idx - 1] < rhs[idx - 1] ? strong_ordering::less :
               lhs[idx - 1] > rhs[idx - 1] ? strong_ordering::greater :
                                             strong_ordering::equal;

    return strong_ordering::equal;
}

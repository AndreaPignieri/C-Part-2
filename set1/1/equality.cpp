#include "numbers.ih"

bool operator==(Numbers const &lhs, Numbers const &rhs)
{
    if (lhs.d_size == rhs.d_size && !lhs.compare(rhs))  
        return 1;

    return 0;
}
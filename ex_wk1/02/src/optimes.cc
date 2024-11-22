#include "../headers/Numbers.ih"

Numbers operator*(Numbers const &lhs, int const rhs)
{
    Numbers tmp { lhs };
    tmp.times(rhs);
    return tmp;
}

Numbers operator*(int const lhs, Numbers const &rhs)
{
    Numbers tmp { rhs };
    tmp.times(lhs);
    return tmp;
}
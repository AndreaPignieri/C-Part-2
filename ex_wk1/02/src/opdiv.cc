#include "../headers/Numbers.ih"

Numbers operator/(Numbers const &lhs, int const rhs)
{
    Numbers tmp { lhs };
    tmp.division(rhs);
    return tmp;
}
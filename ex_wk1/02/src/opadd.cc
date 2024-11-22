#include "../headers/Numbers.ih"

Numbers operator+(Numbers const &lhs, Numbers const &rhs)
{
    Numbers tmp { lhs };
    tmp.add(rhs);
    return tmp;
}
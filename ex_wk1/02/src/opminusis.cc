#include "../headers/Numbers.ih"

Numbers &Numbers::operator-=(Numbers const &rhs)
{
    Numbers tmp{ *this };
    tmp.minus(rhs);
    swap(tmp);
    return *this;
}
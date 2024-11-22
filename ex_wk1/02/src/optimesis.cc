#include "../headers/Numbers.ih"

Numbers &Numbers::operator*=(int const rhs)
{
    Numbers tmp{ *this };
    tmp.times(rhs);
    swap(tmp);
    return *this;
}
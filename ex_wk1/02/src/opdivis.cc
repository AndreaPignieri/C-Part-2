#include "../headers/Numbers.ih"

Numbers &Numbers::operator/=(int const rhs)
{
    Numbers tmp{ *this };
    tmp.division(rhs);
    swap(tmp);
    return *this;
}
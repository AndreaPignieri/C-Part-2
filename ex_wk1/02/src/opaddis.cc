#include "../headers/Numbers.ih"

Numbers &Numbers::operator+=(Numbers const &rhs)
{
    Numbers tmp{ *this };
    tmp.add(rhs);
    swap(tmp);
    return *this;
}
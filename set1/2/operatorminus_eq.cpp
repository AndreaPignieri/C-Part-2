#include "numbers.ih"

Numbers &Numbers::operator-=(Numbers const &other)
{
    Numbers tmp (*this);
    tmp = tmp - other;
    swap(tmp);
    return *this;
}

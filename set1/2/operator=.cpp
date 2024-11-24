#include "numbers.ih"

Numbers &Numbers::operator*=(int rhs)
{
    Numbers tmp( *this );
    tmp = tmp * rhs;
    swap(tmp);
    return *this;
}
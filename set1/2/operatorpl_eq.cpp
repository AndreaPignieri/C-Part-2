#include "numbers.ih"

Numbers &Numbers::operator+=(Numbers const &other)
{
    Numbers tmp( *this );  //copy of this
    tmp = tmp + other;   //use operator+
    swap(tmp);          //no throwing here
    return *this;      
}

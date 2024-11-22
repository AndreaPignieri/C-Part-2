#include "../headers/Numbers.ih"

int const &Numbers::operator[](size_t idx) const
{
    return operatorIndex(idx);
}
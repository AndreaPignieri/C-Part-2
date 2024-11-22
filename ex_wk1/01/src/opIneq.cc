#include "../headers/Numbers.ih"

bool Numbers::operator!=(Numbers const &other) const
{
    return not(*this == other);
}
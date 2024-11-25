#include "numbers.ih"

ostream &operator<<(ostream &out, Numbers const &numbers)
{
    for (size_t idx = 0; idx != numbers.d_size; ++idx)
        out << numbers[idx] << ' ';

    return out;
}
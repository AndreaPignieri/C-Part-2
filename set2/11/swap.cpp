#include "num.ih"

void Num::swap (Num &other)
{
    int tmp_counter = other.d_counter;
    other.d_counter = d_counter;
    d_counter =tmp_counter;
}
#include "num.ih"

Num::Num(Num const &other)
:
    d_counter(0)
{
    Num tmp(0);
    tmp.d_counter = other.d_counter;
    swap(tmp);

    cerr << "copy of object (" << d_counter++ << ") created\n";
}
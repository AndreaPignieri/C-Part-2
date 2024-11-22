#include "../headers/Numbers.ih"

int &Numbers::operator[](size_t idx)
{
    return operatorIndex(idx);
}
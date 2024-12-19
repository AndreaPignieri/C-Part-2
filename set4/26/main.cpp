#include "base/base.hh"
#include "derived/derived.hh"

int main()
{
    Base **bp = derivedFactory(10);

    for (size_t idx = 0; idx != 10; ++idx)
        delete bp[idx];   //delete every pointer to a derived obj

    delete[] bp;
}
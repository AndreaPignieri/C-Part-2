#include "derived.hh"

Base **derivedFactory(size_t size)
{
    Base **arr = new Base*[size];
    //a Base pointer pointing to size pointers

    for (size_t idx = 0; idx != size; ++idx)
        arr[idx] = new Derived();
    //which pointers are pointing to Derived objects
    
    return arr;
}

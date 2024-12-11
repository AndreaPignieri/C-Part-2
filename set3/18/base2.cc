#include "base/base.ih"


//Copy constructor, Explicitly call Base move
Derived::Derived(const Derived &src) : Base(move(src))
{}
//Move constructor, Explicitly call Base copy
Derived::Derived(Derived &&src) : Base(src)
{}


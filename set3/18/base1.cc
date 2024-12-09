#include "base/base.ih"


//Copy constructor, Explicitly call Base copy
Derived::Derived(const Derived &src) : Base(src)
{}
//Move constructor, Explicitly call Base move
Derived::Derived(Derived &&src) : Base(move(src))
{}


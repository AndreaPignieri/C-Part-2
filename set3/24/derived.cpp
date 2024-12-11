#include "derived.ih"

Derived::Derived(string const &name)
:
    Base(out),
    out(name)
{}
#include "strings.ih"

Strings::Proxy::Proxy(Strings *owner, size_t index)
    : d_owner(owner), d_index(index) {}

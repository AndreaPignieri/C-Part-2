#include "symtab.ih"

// Returns the index of the given ID if it exists, otherwise throws an exception.
size_t Symtab::operator[](std::string const &id) const
{
    StrUMapConstIter it = d_idMap.find(id);
    if (it == d_idMap.end())
        throw std::string("ID '" + id + "' not available");
    return it->second.idx;
}
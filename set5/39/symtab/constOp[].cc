#include "symtab.ih"

// Returns the ID corresponding to the given index, or throws an exception if the index is out of range.
std::string const &Symtab::operator[](size_t idx) const
{
    if (idx >= d_idVector.size())
        throw std::string("Index " + std::to_string(idx) + " not available");
    return d_idVector[idx];
}
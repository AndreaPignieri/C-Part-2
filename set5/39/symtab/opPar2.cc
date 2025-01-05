#include "symtab.ih"

// Returns a reference to the value of the ID at the given index, allowing modifications. Throws if the index is invalid.
int &Symtab::operator()(size_t idx)
{
    if (idx >= d_idVector.size())
        throw std::string("Index " + std::to_string(idx) + " not available");
    StrUMapIter it = d_idMap.find(d_idVector[idx]); // Using index to access corresponding ID.
    return it->second.value;
}
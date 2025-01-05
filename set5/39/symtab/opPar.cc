#include "symtab.ih"
// Returns a reference to the value of the given ID, allowing modifications. Throws if the ID does not exist.
int &Symtab::operator()(std::string const &id)
{
    StrUMapIter it = d_idMap.find(id); // Using a mutable iterator to modify the value.
    if (it == d_idMap.end())
        throw std::string("ID '" + id + "' not available");
    return it->second.value;
}

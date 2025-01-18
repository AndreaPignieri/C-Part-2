#include "main.ih"

size_t multiples(vector<size_t> const &vs)
{
    vector<size_t> newVs;
    unique_copy(vs.begin(), vs.end(), back_inserter(newVs));

    return (vs.size() - newVs.size());

    //if multipies didnt require to have a const ref a unique would 
    //also work and with less memory
}
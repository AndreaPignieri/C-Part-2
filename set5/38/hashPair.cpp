#include "address.ih"

size_t hashPair::operator()(pair<string, string> const &info) const
{
    hash<string> hashAdd;

    return hashAdd(info.first) + hashAdd(info.second);
}
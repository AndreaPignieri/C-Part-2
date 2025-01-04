#include "strings.ih"

std::string &Strings::at(size_t idx)
{
    //throw exception if index out of bound
    if (idx >= d_str.size())
	throw out_of_range("Index out of range");
    return d_str[idx]; //return chosen string
}

std::string const &Strings::at(size_t idx) const
{
    //throw exception if index out of bound
    if (idx >= d_str.size())
	throw out_of_range("Index out of range");
    return d_str[idx]; //return chosen string
}


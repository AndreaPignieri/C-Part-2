#include "address.ih"

bool Address::personExist(string &line, pair<string, string> &info)
{
    size_t idx = line.find_first_of(';'); //end of name
    d_data[info].push_back(line.substr(0, idx));  //add name without ;
    line.erase(0, idx + 1);  //erase the name and ;

    if (idx == string::npos) // no more names in the input
        return false;

    return true;
}
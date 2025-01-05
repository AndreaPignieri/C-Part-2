#include "address.ih"

istream &Address::insertFrom(istream &source)
{
    string line;
    while (getline(source, line))   //each address is one line
    {
        pair<string, string> info;   //postal code and address
        addAddress(line, info);    // adds address on the map(no residents)

        while (personExist(line, info))  //goes through personExist until there
        {}                         //arent any unrecorded residents
    }

    return source;
}
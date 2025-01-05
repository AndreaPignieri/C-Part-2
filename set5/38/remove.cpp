#include "address.ih"

size_t Address::remove(string const &postalCode)
{
    set<pair<string, string>> KeySet;    
    //we use the postal COde to put them in Lexicographical order
    //and we need the number to reverse engineer their locations
    fillSet(KeySet);   

    setItSS const stop =  KeySet.lower_bound(make_pair(stopCode(postalCode), ""));
    //pointing where the initial numbers change
    
    for (setItSS idx = KeySet.lower_bound(make_pair(postalCode, "")); 
            eligible(idx, stop, KeySet); ++idx) 
//go through the range of postal codes that start with those numbers
        d_data.erase(d_data.find(*idx));        


    return d_data.size();
}
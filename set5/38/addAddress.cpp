#include "address.ih"

void Address::addAddress(string &line, pair<string, string> &info)
{
    size_t idx = line.find_first_of(';');  
    info.first = line.substr(0, idx); //postalCode
    line.erase(0, idx + 1);  //delete postalCode from line
    
    idx = line.find_first_of(';');
    info.second = line.substr(0, idx);  //number
    line.erase(0, idx + 1);  //delete number from line

    d_data[info];  //create the address in the map
}
#include "address.ih"

bool Address::eligible( setItSS const &idx, setItSS const &stop, 
                        set<pair<string,string>> const &KeySet)
{
    return (idx != KeySet.end() && stop != idx);
    //the iterator isnt on the end of set
    //also it hasnt reached the upper iterator
}
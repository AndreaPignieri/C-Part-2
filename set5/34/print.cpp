#include "main.ih"

void print(multiset<string> &words)
{
    iteratorMultiSet idx = words.begin(); //set an iterator at the start of container
    while (idx != words.end()) //end of container
    {
        cout << *idx << " was used " << words.count(*idx) << " times\n";

        idx = words.equal_range(*idx).second; 
        //skip all the repetitions of same word
    }
}
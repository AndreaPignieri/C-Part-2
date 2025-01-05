#include "main.ih"

void print(set<string> &words)
{
    for (iteratorSet idx = words.begin(); idx != words.end(); ++idx)
        cout << *idx << '\n';
}
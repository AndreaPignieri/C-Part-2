#include "main.ih"

void print(multiset<string> &words);

int main()
{
    multiset <string> words;
    string input;

    while(cin >> input)    //non-spaced string
        words.insert(input); 

    print(words);
}
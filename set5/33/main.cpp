#include "main.ih"

int main()
{
    set <string> words;
    while(cin)
    {
        string input;
        cin >> input;
        words.insert(input);
    }

    print(words);
}
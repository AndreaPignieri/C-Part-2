#include "main.ih"

int main()
{
    set <string> words;  //will sort them automatically
    while(cin)
    {
        string input;
        cin >> input;
        words.insert(input);
    }

    print(words);
}

#include "word_store.h"

void WordStore::readFromFile(const std::string &filename)
{
    std::ifstream file(filename);
    std::unordered_set<std::string> uniqueWords;
    std::string word;

    while (file >> word)
    {
        uniqueWords.insert(word);
    }

    words.assign(uniqueWords.begin(), uniqueWords.end());
}

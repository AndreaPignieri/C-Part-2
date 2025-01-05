#include "read_unique_words.h"
#include <unordered_set>
#include <fstream>

std::vector<std::string> readUniqueWords(const std::string &filename)
{
    std::ifstream file(filename);
    std::unordered_set<std::string> uniqueWords;
    std::string word;

    while (file >> word)
    {
        uniqueWords.insert(word);
    }

    return std::vector<std::string>(uniqueWords.begin(), uniqueWords.end());
}

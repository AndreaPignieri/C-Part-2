#ifndef WORD_STORE_H
#define WORD_STORE_H

#include <vector>
#include <string>
#include <unordered_set>
#include <fstream>

class WordStore
{
public:
    WordStore() = default;                     // Default constructor

    void readFromFile(const std::string &filename); // Read unique words from a file
    void addWord(const std::string &word);         // Add a new word
    void shedExcessCapacity();                     // Shed excess capacity
    size_t size() const;                           // Get the size of the vector

private:
    std::vector<std::string> words;               // Stores unique words
};

#endif // WORD_STORE_H

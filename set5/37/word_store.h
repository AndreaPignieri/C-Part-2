#ifndef WORD_STORE_H
#define WORD_STORE_H

#include <vector>
#include <string>
#include <fstream>
#include <unordered_set>

class WordStore {
private:
    std::vector<std::string> words;

public:
    WordStore() = default;

    // Read unique words from a file
    void readFromFile(const std::string &filename) {
        std::ifstream file(filename);
        std::unordered_set<std::string> uniqueWords;
        std::string word;
        while (file >> word) {
            uniqueWords.insert(word);
        }
        words.assign(uniqueWords.begin(), uniqueWords.end());
    }

    // Add a new word
    void addWord(const std::string &word) {
        words.push_back(word);
    }

    // Shed excess capacity
    void shedExcessCapacity() {
        std::vector<std::string>(words).swap(words);
    }

    // Get size
    size_t size() const {
        return words.size();
    }
};

#endif // WORD_STORE_H
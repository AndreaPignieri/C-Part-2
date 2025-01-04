#include "word_store.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <unordered_set>

std::vector<std::string> readUniqueWords(const std::string &filename) {
    std::ifstream file(filename);
    std::unordered_set<std::string> uniqueWords;
    std::string word;
    while (file >> word) {
        uniqueWords.insert(word);
    }
    return std::vector<std::string>(uniqueWords.begin(), uniqueWords.end());
}

int main() {
    // Part 1: Demonstrate size and capacity of std::vector
    auto words = readUniqueWords("example.txt");
    std::cout << "Initial size: " << words.size() << ", capacity: " << words.capacity() << "\n";

    words.push_back("new_word");
    std::cout << "After adding one word - size: " << words.size() << ", capacity: " << words.capacity() << "\n";

    std::vector<std::string>(words).swap(words); // Shed excess capacity
    std::cout << "After shedding capacity - size: " << words.size() << ", capacity: " << words.capacity() << "\n";

    // Part 2: Using the WordStore class
    WordStore store;
    store.readFromFile("example.txt");
    std::cout << "Initial WordStore size: " << store.size() << "\n";

    store.addWord("new_word");
    std::cout << "After adding one word - WordStore size: " << store.size() << "\n";

    store.shedExcessCapacity();
    std::cout << "After shedding capacity - WordStore size: " << store.size() << "\n";

    return 0;
}
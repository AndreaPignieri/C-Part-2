#include "WordStore/word_store.h"
#include "Utils/read_unique_words.h"
#include <iostream>

int main()
{
    WordStore store;

    // Use readUniqueWords to get unique words
    auto uniqueWords = readUniqueWords("example.txt");
    std::cout << "Words read using readUniqueWords: ";
    for (const auto &word : uniqueWords)
        std::cout << word << " ";
    std::cout << "\n";

    // Use WordStore to manage words
    store.readFromFile("example.txt");
    std::cout << "Initial WordStore size: " << store.size() << "\n";

    // Test adding a new word
    store.addWord("new_word");
    std::cout << "After adding one word - WordStore size: " << store.size() << "\n";

    // Test shedding excess capacity
    store.shedExcessCapacity();
    std::cout << "After shedding capacity - WordStore size: " << store.size() << "\n";

    return 0;
}

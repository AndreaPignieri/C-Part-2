#include "../WordStore/word_store.h"

void WordStore::shedExcessCapacity()
{
    std::vector<std::string>(words).swap(words);
}

#include "fillunique.ih"

void FillUnique::fill(std::vector<size_t> &vec, size_t amount)
{
    set<size_t> uniqueVals;  //initialize set for ease of checking
    // set value iteratively
    for (size_t idx = 0; idx != amount; ++idx)
    {
        //current value
        size_t value;
        //set value and check uniqueness
        do
        {
            value = randGen(); //set random value
        }
        while (uniqueVals.find(value) != uniqueVals.end());
        //store value in set and vector
        storeValue(vec, uniqueVals, value);
    }
}

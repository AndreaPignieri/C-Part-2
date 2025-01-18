#ifndef INCLUDED_FILLUNIQUE_
#define INCLUDED_FILLUNIQUE_
#include <vector>
#include <set>
#include "random/random.h"
//fill vector with unique values
class FillUnique
{
    //hold random object
    Random &randGen;
    public:
        //constructor initializes with random obj
        FillUnique(Random &gen) : randGen(gen){};
        
        //fill vector member
        void fill(std::vector<size_t> &vec, size_t amount);
    private:
        //helper function to store values
        void storeValue(std::vector<size_t> &vec,
                        std::set<size_t> &vals, size_t val);
};

//inline definitions
inline void FillUnique::storeValue(std::vector<size_t> &vec,
                                   std::set<size_t> &vals,
                                   size_t val)
{
    vec.push_back(val);
    vals.insert(val);
}

#endif

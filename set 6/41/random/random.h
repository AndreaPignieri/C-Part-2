#ifndef INCLUDED_RANDOM_
#define INCLUDED_RANDOM_
#include <random>
#include <ctime>
//Generate Random numbers
class Random
{
    //random number generator
    static std::mt19937 s_engine;
    //random number distribution
    std::uniform_int_distribution<size_t> dist;
    public:
        //constructor that takes range
        Random(size_t low, size_t high) : dist(low, high)
        {};
        
        //function call operator
        size_t operator()();
        //return range
        size_t range();
};


//inline definitions
inline size_t Random::operator()()
{
    return dist(s_engine);
}

inline size_t Random::range()
{
    return dist.max() - dist.min() + 1;
}
#endif

#include "main.ih"

std::vector<size_t> erastothenesSieve(size_t primesToFind)
{
    //Literal implementation of the erastothenes sieve
    std::vector<size_t> primes;
    primes.push_back(2);
    size_t nextToCheck = 3;

    while (primes.size() < primesToFind)
    {
        std::vector<size_t>::const_iterator begin = primes.cbegin();
        bool isPrime = true;
        while (isPrime == true && begin != primes.cend())
        {
            if (nextToCheck % *begin == 0)
            {
                isPrime = false;
            }
            ++begin;
        }
        if (isPrime)
        {
            primes.push_back(nextToCheck);
        }
        ++nextToCheck;
    }
    return primes;
}
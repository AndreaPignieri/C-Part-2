#include <iostream>
#include <thread>
#include <chrono>
#include <vector>

void loading(std::stop_token stopToken)
{
    //Prints a dot every second until stopToken is requested
    while (!stopToken.stop_requested())
    {
        std::cerr << ".";
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

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

int main(int argc, char* argv[])
{
    //Created alias for easier qualification of the chrono namespace
    namespace chrono = std::chrono;

    if (argc != 2)
    {
        std::cerr << "Missing argument, number of primes to find" << std::endl;
        return 1;
    }

    //Save the starting time
    chrono::time_point startTime = std::chrono::system_clock::now();
    //Save as time_t and tm for easier printing
    std::time_t startTimeT = std::chrono::system_clock::to_time_t(startTime);
    tm startTimeTm = *std::localtime(&startTimeT);

    //Start the thread to print loading dots
    std::jthread loadingThread(loading);

    //Find the primes
    size_t primesToFind = std::stoi(argv[1]);
    std::vector<size_t> primes = erastothenesSieve(primesToFind);

    //Stop the loading thread
    loadingThread.request_stop();
    std::cerr << std::endl;

    //Save the ending time
    chrono::time_point endTime = std::chrono::system_clock::now();
    //Save as time_t and tm for easier printing
    std::time_t endTimeT = std::chrono::system_clock::to_time_t(endTime);
    tm endTimeTm = *std::localtime(&endTimeT);

    //Calculate the elapsed time
    chrono::seconds elapsedSeconds = chrono::duration_cast<chrono::seconds>(endTime - startTime);

    //Print the results
    for (size_t prime : primes)
    {
        std::cout << prime << " ";
    }
    std::cout << std::endl;

    //Print the time
    std::cout << "Starting time: " << std::put_time(&startTimeTm, "%c") << std::endl;
    std::cout << "Ending time:   " << std::put_time(&endTimeTm, "%c") << std::endl;
    std::cout << "Computation of " << primesToFind << " primes took " << elapsedSeconds << " seconds" << std::endl;

    return 0;
}
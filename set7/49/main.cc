#include "main.ih"
#include "functions.hh"

int main(int argc, char* argv[])
{
    //Created alias for easier qualification of the chrono namespace
    namespace chrono = std::chrono;

    if (argc != 2)
    {
        throw std::invalid_argument("Missing argument for number of primes to find");
    }

    chrono::time_point startTime = std::chrono::system_clock::now();
    //Save as time_t and tm for easier printing
    std::time_t startTimeT = std::chrono::system_clock::to_time_t(startTime);
    tm startTimeTm = *std::localtime(&startTimeT);

    std::jthread loadingThread(loading);

    size_t primesToFind = std::stoi(argv[1]);
    std::vector<size_t> primes = erastothenesSieve(primesToFind);

    //Stop the loading thread
    loadingThread.request_stop();
    std::cerr << std::endl;

    chrono::time_point endTime = std::chrono::system_clock::now();
    //Save as time_t and tm for easier printing
    std::time_t endTimeT = std::chrono::system_clock::to_time_t(endTime);
    tm endTimeTm = *std::localtime(&endTimeT);

    chrono::seconds elapsedSeconds = chrono::duration_cast<chrono::seconds>(endTime - startTime);

    for (size_t prime : primes)
    {
        std::cout << prime << " ";
    }
    std::cout << std::endl;

    //Print the time
    std::cout << "Starting time: " << std::put_time(&startTimeTm, "%c") << std::endl;
    std::cout << "Ending time:   " << std::put_time(&endTimeTm, "%c") << std::endl;
    std::cout << "Computation of " << primesToFind << " primes took " << elapsedSeconds << " seconds" << std::endl;

}
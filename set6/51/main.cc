#include "main.ih"
#include "functions.hh"

int main(int argc, char* argv[])
{
    //Created alias for easier qualification of the chrono namespace
    namespace chrono = std::chrono;

    //Check for the correct number of arguments
    if (argc != 2)
    {
        throw std::invalid_argument("Missing argument for time addition");
    }
    
    chrono::seconds durationToAdd = getDurationToAdd(argv[1]);
    
    chrono::time_point currentTime = chrono::system_clock::now();
    std::time_t currentTimeT = chrono::system_clock::to_time_t(currentTime);
    tm currentTimeTm = *std::localtime(&currentTimeT);
    
    chrono::time_point newTime = currentTime + durationToAdd;
    
    std::time_t newTimeT = chrono::system_clock::to_time_t(newTime);
    tm newTimeTm = *std::localtime(&newTimeT);

    //Print the new time
    std::cout << "GMT time:\t" << std::put_time(gmtime(&currentTimeT), "%c") << std::endl;
    std::cout << "Current time:\t" << std::put_time(&currentTimeTm, "%c") << std::endl;
    std::cout << "Adjusted time:\t" << std::put_time(&newTimeTm, "%c") << std::endl;

}
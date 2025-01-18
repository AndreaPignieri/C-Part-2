#include <iostream>
#include <chrono>

int main(int argc, char* argv[])
{
    //Created alias for easier qualification of the chrono namespace
    namespace chrono = std::chrono;

    //Check for the correct number of arguments
    if (argc != 2)
    {
        std::cerr << "Value to add/subtract to current time" << std::endl;
        return 1;
    }

    //Convert argument to integer
    int timeToAdd = std::stoi(argv[1]);
    //Get the current time
    chrono::time_point currentTime = chrono::system_clock::now();
    //Add the time to the current time
    chrono::time_point newTime = currentTime + chrono::seconds(timeToAdd);
    //Convert the time to a time_t
    std::time_t newTimeT = chrono::system_clock::to_time_t(newTime);
    //Convert the time_t to a tm
    tm newTimeTm = *std::localtime(&newTimeT);
    //Print the new time
    std::cout << "Current time" << std::put_time(&newTimeTm, "%c") << std::endl;
    std::cout << "New time" << std::put_time(&newTimeTm, "%c") << std::endl;

    return 0;
}
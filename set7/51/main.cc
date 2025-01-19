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
    
    chrono::seconds durationToAdd;

    //Get the time to add/subtract
    try {
        // Parse the input argument
        std::string input = argv[1];
        char unit = input.back(); // Last character specifies the unit (s, m, h)
        input.pop_back();         // Remove the unit to get the numeric part
        int value = std::stoi(input);

        
        switch (unit) {
            case 's': // Seconds
                durationToAdd = chrono::seconds(value);
                break;
            case 'm': // Minutes
                durationToAdd = duration_cast<chrono::seconds>(chrono::minutes(value));
                break;
            case 'h': // Hours
                durationToAdd = duration_cast<chrono::seconds>(chrono::hours(value));
                break;
            default:
                throw std::invalid_argument("Invalid time unit. Use 's', 'm', or 'h'.");
        }
    } catch (const std::exception& e) {
        throw std::invalid_argument("Failed to parse input. Ensure the format is <value><unit>, e.g., 10s, -5m.");
    }

    //Get the current time
    chrono::time_point currentTime = chrono::system_clock::now();
    //Convert the current time to a time_t
    std::time_t currentTimeT = chrono::system_clock::to_time_t(currentTime);
    //Convert the time_t to a tm
    tm currentTimeTm = *std::localtime(&currentTimeT);
    //Add the time to the current time
    chrono::time_point newTime = currentTime + durationToAdd;
    //Convert the time to a time_t
    std::time_t newTimeT = chrono::system_clock::to_time_t(newTime);
    //Convert the time_t to a tm
    tm newTimeTm = *std::localtime(&newTimeT);
    //Print the new time
    std::cout << "GMT time:\t" << std::put_time(gmtime(&currentTimeT), "%c") << std::endl;
    std::cout << "Current time:\t" << std::put_time(&currentTimeTm, "%c") << std::endl;
    std::cout << "Adjusted time:\t" << std::put_time(&newTimeTm, "%c") << std::endl;

    return 0;
}
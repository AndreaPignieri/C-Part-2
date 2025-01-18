#include <iostream>
#include <chrono>

template <typename To, typename From>
double durationCast(From from)
{
    return static_cast<double>(from.count()) * 
                        To::period::den * From::period::num /
                        (To::period::num * From::period::den);
} 

int main(int argc, char *argv[])
{
    //Created alias for easier qualification of the chrono namespace
    namespace chrono = std::chrono;

    //Check for the correct number of arguments
    if (argc != 3)
    {
        std::cerr << "Missing arguments for conversion" << std::endl;
        return 1;
    }

    //Convert arguments to integers
    size_t hoursToMinutes = std::stoi(argv[1]);
    size_t secondsToMinutes = std::stoi(argv[2]);

    //Convert hours to minutes
    chrono::minutes minutesFromHours = chrono::duration_cast<chrono::minutes>(chrono::hours(hoursToMinutes));

    //Convert seconds to minutes
    double doubleMinutes = durationCast<chrono::minutes>(chrono::seconds(secondsToMinutes));
    chrono::minutes minutesFromSeconds = chrono::duration_cast<chrono::minutes>(chrono::seconds(secondsToMinutes));
    
    std::cout << "Minutes converted from hours: " << minutesFromHours.count() << std::endl;
    std::cout << "Precise value of minutes produced from seconds: " << doubleMinutes << std::endl;
    std::cout << "Rounded value of minutes produced from seconds: " << minutesFromSeconds.count() << std::endl;

    return 0;
}
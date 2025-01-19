#include "main.ih"
#include "durationcast.hh"

int main(int argc, char *argv[])
{
    //Created alias for easier qualification of the chrono namespace
    namespace chrono = std::chrono;

    //Check for the correct number of arguments
    if (argc != 3)
    {
        throw std::invalid_argument("Missing argument for time addition");
    }


    size_t hoursToMinutes = std::stoi(argv[1]);
    size_t secondsToMinutes = std::stoi(argv[2]);


    chrono::minutes minutesFromHours = chrono::duration_cast<chrono::minutes>(chrono::hours(hoursToMinutes));

    double doubleMinutes = durationCast<chrono::minutes>(chrono::seconds(secondsToMinutes));
    chrono::minutes minutesFromSeconds = chrono::duration_cast<chrono::minutes>(chrono::seconds(secondsToMinutes));
    
    std::cout << "Minutes converted from hours: " << minutesFromHours.count() << std::endl;
    std::cout << "Precise value of minutes produced from seconds: " << doubleMinutes << std::endl;
    std::cout << "Rounded value of minutes produced from seconds: " << minutesFromSeconds.count() << std::endl;

}
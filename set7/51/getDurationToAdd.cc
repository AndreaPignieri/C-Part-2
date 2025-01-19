#include "main.ih"

std::chrono::seconds getDurationToAdd(std::string input)
{
    //Created alias for easier qualification of the chrono namespace
    namespace chrono = std::chrono;

    char unit = input.back(); // Last character specifies the unit (s, m, h)
    input.pop_back();         // Remove the unit to get the numeric part
    int value = std::stoi(input);

    switch (unit) {
        case 's': // Seconds
            return chrono::seconds(value);
        case 'm': // Minutes
            return duration_cast<chrono::seconds>(chrono::minutes(value));
        case 'h': // Hours
            return duration_cast<chrono::seconds>(chrono::hours(value));
        default:
            throw std::invalid_argument("Invalid time unit. Use 's', 'm', or 'h'.");
    }
}
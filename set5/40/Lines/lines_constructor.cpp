#include "../Lines/lines.h"

// Static member definition
std::vector<std::vector<std::string>> Lines::allLines;

Lines::Lines(std::istream &in)
{
    std::vector<std::string> currentLines;
    std::string line;

    // Read lines until an empty line or EOF
    while (std::getline(in, line) && !line.empty())
    {
        currentLines.push_back(line);
    }

    // Store the current object's lines in the shared container
    allLines.push_back(currentLines);
    index = allLines.size() - 1; // Set the index for this object
}

#include "../Lines/lines.h"

const std::vector<std::string> &Lines::get(size_t idx) const
{
    if (idx < allLines.size())
        return allLines[idx];
    static const std::vector<std::string> empty; // Return an empty vector for invalid indices
    return empty;
}

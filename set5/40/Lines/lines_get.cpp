#include "../Lines/lines.h"

const std::vector<std::string> &Lines::get() const
{
    return allLines[index];
}

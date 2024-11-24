#include "strings.h"
#include <iostream>

// Overloaded insertion operator
std::ostream &operator<<(std::ostream &out, Strings const &strings)
{
    strings.insertInto(out);
    return out;
}

// Pseudo-manipulator for separator
Strings const &Strings::operator()(char const *separator)
{
    d_sep = separator;
    return *this;
}

// Pseudo-manipulator for custom manipulator
Strings const &Strings::operator()(void (*manip)(std::ostream &, Strings const &, size_t))
{
    d_manip = manip;
    return *this;
}

// Insertion logic
std::ostream &Strings::insertInto(std::ostream &out) const
{
    for (size_t idx = 0; idx < d_size; ++idx)
    {
        // Call the manipulator function for each element
        d_manip(out, *this, idx);

        // Add separator unless it's the last element
        if (idx < d_size - 1)
            out << d_sep;
    }

    // Reset to default behavior after use
    d_sep = "\n";
    d_manip = &Strings::stdInsertion;

    return out;
}

// Default insertion behavior: insert each string as-is
void Strings::stdInsertion(std::ostream &out, Strings const &strings, size_t idx)
{
    out << strings.at(idx);
}

// Example custom manipulator: only insert the first two strings
void Strings::only2(std::ostream &out, Strings const &strings, size_t idx)
{
    if (idx == 0)
        out << strings.at(idx);
    else if (idx == 1)
        out << ", and: " << strings.at(idx);
}


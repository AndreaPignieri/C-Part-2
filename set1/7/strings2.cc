#include "strings.h"
#include <iostream>
#include <cstring> // For std::memcpy

// Constructor: Initialize from command-line arguments
Strings::Strings(int argc, char **argv)
    : d_size(argc), d_str(new std::string[argc]), d_manip(&Strings::stdInsertion)
{
    for (size_t idx = 0; idx < d_size; ++idx)
    {
        d_str[idx] = argv[idx]; // Copy each argument
    }
}

// Constructor: Initialize from environment-like array
Strings::Strings(char **environLike)
{
    size_t count = 0;

    // Count the number of entries in the environ-like array
    while (environLike[count])
    {
        ++count;
    }

    d_size = count;
    d_str = new std::string[d_size];
    d_manip = &Strings::stdInsertion;

    for (size_t idx = 0; idx < d_size; ++idx)
    {
        d_str[idx] = environLike[idx]; // Copy each environment entry
    }
}

// Copy constructor
Strings::Strings(Strings const &other)
    : d_size(other.d_size), d_str(new std::string[other.d_size]),
      d_sep(other.d_sep), d_manip(other.d_manip)
{
    for (size_t idx = 0; idx < d_size; ++idx)
    {
        d_str[idx] = other.d_str[idx]; // Copy each string
    }
}

// Move constructor
Strings::Strings(Strings &&tmp) noexcept
    : d_size(tmp.d_size), d_str(tmp.d_str), d_sep(std::move(tmp.d_sep)),
      d_manip(tmp.d_manip)
{
    tmp.d_size = 0;
    tmp.d_str = nullptr;
    tmp.d_manip = nullptr;
}

// Destructor
Strings::~Strings()
{
    delete[] d_str; // Release dynamically allocated memory
}

// Copy assignment operator
Strings &Strings::operator=(Strings const &rhs)
{
    if (this != &rhs) // Prevent self-assignment
    {
        delete[] d_str; // Release existing resources

        d_size = rhs.d_size;
        d_str = new std::string[d_size];
        d_sep = rhs.d_sep;
        d_manip = rhs.d_manip;

        for (size_t idx = 0; idx < d_size; ++idx)
        {
            d_str[idx] = rhs.d_str[idx]; // Copy each string
        }
    }
    return *this;
}

// Move assignment operator
Strings &Strings::operator=(Strings &&rhs) noexcept
{
    if (this != &rhs) // Prevent self-assignment
    {
        delete[] d_str; // Release existing resources

        d_size = rhs.d_size;
        d_str = rhs.d_str;
        d_sep = std::move(rhs.d_sep);
        d_manip = rhs.d_manip;

        rhs.d_size = 0;
        rhs.d_str = nullptr;
        rhs.d_manip = nullptr;
    }
    return *this;
}

// Swap contents with another Strings object
void Strings::swap(Strings &other)
{
    std::swap(d_size, other.d_size);
    std::swap(d_str, other.d_str);
    std::swap(d_sep, other.d_sep);
    std::swap(d_manip, other.d_manip);
}

// Return the number of strings
size_t Strings::size() const
{
    return d_size;
}

// Access a string at a given index (const)
std::string const &Strings::at(size_t idx) const
{
    return d_str[idx];
}

// Access a string at a given index (non-const)
std::string &Strings::at(size_t idx)
{
    return d_str[idx];
}

// Add a new string to the collection
void Strings::add(std::string const &next)
{
    std::string *newData = new std::string[d_size + 1];

    // Copy existing strings
    for (size_t idx = 0; idx < d_size; ++idx)
    {
        newData[idx] = d_str[idx];
    }

    newData[d_size] = next; // Add the new string

    delete[] d_str; // Release old memory
    d_str = newData;
    ++d_size;
}

// Set the separator
Strings const &Strings::operator()(char const *separator)
{
    d_sep = separator;
    return *this;
}

// Set a custom manipulator
Strings const &Strings::operator()(void (*manip)(std::ostream &, Strings const &, size_t))
{
    d_manip = manip;
    return *this;
}

// Overloaded insertion operator
std::ostream &operator<<(std::ostream &out, Strings const &strings)
{
    strings.insertInto(out); // Use the internal insertInto function
    return out;
}

// Insert strings into the output stream
std::ostream &Strings::insertInto(std::ostream &out) const
{
    for (size_t idx = 0; idx < d_size; ++idx)
    {
        d_manip(out, *this, idx); // Call the manipulator for each string

        if (idx < d_size - 1) // Add separator for all but the last string
        {
            out << d_sep;
        }
    }

    return out;
}

// Default insertion behavior: insert strings as-is
void Strings::stdInsertion(std::ostream &out, Strings const &strings, size_t idx)
{
    out << strings.d_str[idx];
}

// Example custom manipulator: insert only the first two strings
void Strings::only2(std::ostream &out, Strings const &strings, size_t idx)
{
    if (idx == 0)
    {
        out << strings.d_str[idx];
    }
    else if (idx == 1)
    {
        out << ", and: " << strings.d_str[idx];
    }
}

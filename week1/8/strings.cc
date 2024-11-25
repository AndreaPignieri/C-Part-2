#include "strings.h"
#include <iostream>
#include <cstring> // For std::memcpy

// Constructor: Initialize from command-line arguments
Strings::Strings(int argc, char **argv)
    : d_shared(new size_t(1)), d_size(argc), d_str(new std::string[d_size])
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

    while (environLike[count]) // Count entries in the array
    {
        ++count;
    }

    allocate(count);

    for (size_t idx = 0; idx < d_size; ++idx)
    {
        d_str[idx] = environLike[idx]; // Copy each entry
    }
}

// Copy constructor
Strings::Strings(Strings const &other)
    : d_shared(other.d_shared), d_size(other.d_size), d_str(other.d_str)
{
    ++(*d_shared); // Increment shared count
}

// Move constructor
Strings::Strings(Strings &&tmp) noexcept
    : d_shared(tmp.d_shared), d_size(tmp.d_size), d_str(tmp.d_str)
{
    tmp.d_shared = nullptr;
    tmp.d_str = nullptr;
    tmp.d_size = 0;
}

// Destructor
Strings::~Strings()
{
    if (d_shared && --(*d_shared) == 0)
    {
        delete[] d_str;
        delete d_shared;
    }
}

// Copy assignment operator
Strings &Strings::operator=(Strings const &rhs)
{
    if (this != &rhs) // Prevent self-assignment
    {
        if (d_shared && --(*d_shared) == 0)
        {
            delete[] d_str;
            delete d_shared;
        }

        d_shared = rhs.d_shared;
        d_size = rhs.d_size;
        d_str = rhs.d_str;

        ++(*d_shared); // Increment shared count
    }
    return *this;
}

// Move assignment operator
Strings &Strings::operator=(Strings &&rhs) noexcept
{
    if (this != &rhs) // Prevent self-assignment
    {
        if (d_shared && --(*d_shared) == 0)
        {
            delete[] d_str;
            delete d_shared;
        }

        d_shared = rhs.d_shared;
        d_size = rhs.d_size;
        d_str = rhs.d_str;

        rhs.d_shared = nullptr;
        rhs.d_str = nullptr;
        rhs.d_size = 0;
    }
    return *this;
}

// Add a new string (operator+=)
Strings &Strings::operator+=(std::string const &next)
{
    cow(); // Ensure exclusive ownership

    std::string *newData = new std::string[d_size + 1];

    for (size_t idx = 0; idx < d_size; ++idx)
    {
        newData[idx] = d_str[idx]; // Copy existing strings
    }

    newData[d_size] = next; // Add new string

    delete[] d_str;
    d_str = newData;
    ++d_size;

    return *this;
}

// Copy-on-write logic
void Strings::cow()
{
    if (*d_shared > 1)
    {
        --(*d_shared); // Decrement shared count

        std::string *newData = new std::string[d_size];

        for (size_t idx = 0; idx < d_size; ++idx)
        {
            newData[idx] = d_str[idx]; // Copy existing strings
        }

        d_shared = new size_t(1);
        d_str = newData;
    }
}

// Swap contents with another Strings object
void Strings::swap(Strings &other)
{
    std::swap(d_shared, other.d_shared);
    std::swap(d_size, other.d_size);
    std::swap(d_str, other.d_str);
}

// Get the number of strings
size_t Strings::size() const
{
    return d_size;
}

// Access string at index (const)
std::string const &Strings::operator[](size_t idx) const
{
    return d_str[idx];
}

// Access string at index (non-const, returns Proxy)
Strings::Proxy Strings::operator[](size_t idx)
{
    return Proxy(this, idx);
}

// Allocate memory for strings
void Strings::allocate(size_t size)
{
    d_size = size;
    d_shared = new size_t(1);
    d_str = new std::string[d_size];
}

// Proxy constructor
Strings::Proxy::Proxy(Strings *owner, size_t index)
    : d_owner(owner), d_index(index) {}

// Assignment operator for Proxy
Strings::Proxy &Strings::Proxy::operator=(std::string const &value)
{
    d_owner->cow(); // Ensure exclusive ownership
    d_owner->d_str[d_index] = value;
    return *this;
}

// Conversion to string
Strings::Proxy::operator std::string() const
{
    return d_owner->d_str[d_index];
}

// Insertion operator for Proxy
std::ostream &operator<<(std::ostream &out, Strings::Proxy const &proxy)
{
    out << static_cast<std::string>(proxy);
    return out;
}

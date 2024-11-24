#include "strings.h"
#include <iostream>
#include <cstring> // For std::memcpy

// Constructor: Initialize from command-line arguments
Strings::Strings(int argc, char **argv)
    : d_size(argc), d_shared(new size_t(1)), d_str(new std::string[argc])
{
    for (size_t i = 0; i < d_size; ++i)
        d_str[i] = argv[i];
}

// Constructor: Initialize from environ-like array
Strings::Strings(char **environLike)
{
    size_t count = 0;
    while (environLike[count])
        ++count;

    allocate(count);
    for (size_t i = 0; i < count; ++i)
        d_str[i] = environLike[i];
}

// Copy constructor (reference counting)
Strings::Strings(Strings const &other)
    : d_shared(other.d_shared), d_str(other.d_str), d_size(other.d_size)
{
    ++(*d_shared); // Increment reference count
}

// Move constructor
Strings::Strings(Strings &&tmp) noexcept
    : d_shared(tmp.d_shared), d_str(tmp.d_str), d_size(tmp.d_size)
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
    if (this != &rhs)
    {
        if (d_shared && --(*d_shared) == 0)
        {
            delete[] d_str;
            delete d_shared;
        }

        d_shared = rhs.d_shared;
        d_str = rhs.d_str;
        d_size = rhs.d_size;
        ++(*d_shared); // Increment reference count
    }
    return *this;
}

// Move assignment operator
Strings &Strings::operator=(Strings &&rhs) noexcept
{
    if (this != &rhs)
    {
        if (d_shared && --(*d_shared) == 0)
        {
            delete[] d_str;
            delete d_shared;
        }

        d_shared = rhs.d_shared;
        d_str = rhs.d_str;
        d_size = rhs.d_size;

        rhs.d_shared = nullptr;
        rhs.d_str = nullptr;
        rhs.d_size = 0;
    }
    return *this;
}

// Allocate memory for strings
void Strings::allocate(size_t size)
{
    d_size = size;
    d_shared = new size_t(1);
    d_str = new std::string[d_size];
}

// Add a new string (operator+=)
Strings &Strings::operator+=(std::string const &next)
{
    cow(); // Ensure exclusive ownership
    std::string *newData = new std::string[d_size + 1];
    std::memcpy(newData, d_str, d_size * sizeof(std::string));
    newData[d_size] = next;

    delete[] d_str;
    d_str = newData;
    ++d_size;

    return *this;
}

// Copy-on-write
void Strings::cow()
{
    if (*d_shared > 1)
    {
        --(*d_shared); // Decrement reference count

        // Make a deep copy
        std::string *newData = new std::string[d_size];
        std::memcpy(newData, d_str, d_size * sizeof(std::string));

        d_shared = new size_t(1);
        d_str = newData;
    }
}

// Swap two Strings objects
void Strings::swap(Strings &other)
{
    std::swap(d_shared, other.d_shared);
    std::swap(d_str, other.d_str);
    std::swap(d_size, other.d_size);
}

// Size accessor
size_t Strings::size() const
{
    return d_size;
}

// Index operator for const Strings
std::string const &Strings::operator[](size_t idx) const
{
    return d_str[idx];
}

// Index operator for non-const Strings (returns Proxy)
Strings::Proxy Strings::operator[](size_t idx)
{
    return Proxy(this, idx);
}

// Proxy constructor
Strings::Proxy::Proxy(Strings *owner, size_t index)
    : d_owner(owner), d_index(index) {}

// Assignment operator for Proxy (copy-on-write)
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


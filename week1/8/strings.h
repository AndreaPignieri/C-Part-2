#ifndef INCLUDED_STRINGS_
#define INCLUDED_STRINGS_

#include <string>
#include <vector>
#include <iostream>
#include <memory> // For std::shared_ptr

// Represents a collection of strings with reference counting and copy-on-write
class Strings
{
    class Proxy; // Forward declaration of Proxy

    size_t *d_shared = nullptr;          // Shared count
    std::string *d_str = nullptr;        // Pointer to dynamic array of strings
    size_t d_size = 0;                   // Number of strings

public:
    // Constructors and Destructor
    Strings() = default;
    Strings(int argc, char **argv);
    Strings(char **environLike);
    Strings(Strings const &other);       // Copy constructor
    Strings(Strings &&tmp) noexcept;    // Move constructor
    ~Strings();

    Strings &operator=(Strings const &rhs); // Copy assignment
    Strings &operator=(Strings &&rhs) noexcept; // Move assignment

    // Member functions
    Strings &operator+=(std::string const &next); // Add string (replaces add)

    size_t size() const;
    void swap(Strings &other);

    // Index operators
    std::string const &operator[](size_t idx) const; // For const Strings
    Proxy operator[](size_t idx);                    // For non-const Strings

private:
    void cow(); // Copy-on-write logic

    // Helper function for allocation
    void allocate(size_t size);
};

// Nested Proxy class
class Strings::Proxy
{
    Strings *d_owner; // Owning Strings object
    size_t d_index;   // Index in the Strings object

public:
    Proxy(Strings *owner, size_t index);
    Proxy &operator=(std::string const &value); // Assignment operator
    operator std::string() const;              // Conversion to string

    friend std::ostream &operator<<(std::ostream &out, Proxy const &proxy);
};

#endif // INCLUDED_STRINGS_

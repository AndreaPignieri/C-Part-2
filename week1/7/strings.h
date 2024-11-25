#ifndef INCLUDED_STRINGS_
#define INCLUDED_STRINGS_

#include <string>
#include <iostream>
#include <functional>

// Represents a collection of strings
class Strings
{
    size_t d_size = 0;                  // Number of strings
    std::string *d_str = nullptr;       // Dynamic array of strings

    std::string d_sep = "\n";           // Default separator
    std::function<void(std::ostream &, Strings const &, size_t)> d_manip =
        &Strings::stdInsertion;         // Manipulator for formatted output

public:
    // Constructors
    Strings() = default;
    Strings(int argc, char **argv);    // Initialize from command-line arguments
    Strings(char **environLike);       // Initialize from environment-like array

    // Rule of five
    Strings(Strings const &other);     // Copy constructor
    Strings(Strings &&tmp) noexcept;  // Move constructor
    ~Strings();                        // Destructor

    Strings &operator=(Strings const &rhs); // Copy assignment operator
    Strings &operator=(Strings &&rhs) noexcept; // Move assignment operator

    // Utility functions
    void swap(Strings &other);              // Swap contents with another object
    size_t size() const;                    // Get the number of strings
    std::string const &at(size_t idx) const; // Access string at index (const)
    std::string &at(size_t idx);            // Access string at index (non-const)
    void add(std::string const &next);      // Add a new string to the collection

    // Pseudo-manipulators
    Strings const &operator()(char const *separator); // Set separator
    Strings const &operator()(void (*manip)(std::ostream &, Strings const &, size_t)); // Set manipulator

    // Insertion operator
    friend std::ostream &operator<<(std::ostream &out, Strings const &strings);

private:
    // Internal helper functions
    std::ostream &insertInto(std::ostream &out) const; // Insert strings into stream

    // Default insertion behavior
    static void stdInsertion(std::ostream &out, Strings const &strings, size_t idx);

    // Example custom manipulator
    static void only2(std::ostream &out, Strings const &strings, size_t idx);
};

#endif // INCLUDED_STRINGS_

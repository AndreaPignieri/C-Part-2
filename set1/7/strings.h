#ifndef INCLUDED_STRINGS_
#define INCLUDED_STRINGS_

#include <string>
#include <vector>
#include <iostream>

// Represents a collection of strings
class Strings
{
    std::string *d_str = nullptr;  // Pointer to the array of strings
    size_t d_size = 0;             // Number of strings

public:
    Strings() = default;
    Strings(int argc, char **argv); // From strings2_1.cc
    Strings(char **environLike);    // From strings2_2.cc

    ~Strings();                     // From strings2_3.cc

    Strings &operator=(Strings const &rhs); // From strings2_4.cc

    void add(std::string const &next); // From strings2_5.cc

    size_t size() const;              // From strings2_6.cc
    std::string const &at(size_t idx) const; // From strings2_7.cc
    std::string &at(size_t idx);      // From strings2_8.cc
};

#endif // INCLUDED_STRINGS_

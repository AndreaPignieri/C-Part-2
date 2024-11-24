#ifndef INCLUDED_STRINGS_
#define INCLUDED_STRINGS_

#include <string>
#include <iostream>
#include <functional>

class Strings
{
    size_t d_size = 0;
    std::string *d_str = nullptr;

    // Member variables for manipulators
    std::string d_sep = "\n"; // Default separator
    std::function<void(std::ostream &, Strings const &, size_t)> d_manip = &Strings::stdInsertion;

public:
    // Constructors
    Strings() = default;
    Strings(int argc, char **argv);    // From strings2.cc
    Strings(char **environLike);       // From strings3.cc

    // Rule of five
    Strings(Strings const &other);     // From part 1
    Strings(Strings &&tmp);            // From part 1
    ~Strings();

    Strings &operator=(Strings const &rhs); // From part 1
    Strings &operator=(Strings &&rhs);      // From part 1

    // Utility functions
    void swap(Strings &other);
    size_t size() const;
    std::string const &at(size_t idx) const;
    std::string &at(size_t idx);
    void add(std::string const &next);

    // Pseudo-manipulators
    Strings const &operator()(char const *separator);
    Strings const &operator()(void (*manip)(std::ostream &, Strings const &, size_t));

    // Insertion operator
    friend std::ostream &operator<<(std::ostream &out, Strings const &strings);

private:
    // Internal helper functions
    std::ostream &insertInto(std::ostream &out) const;

    // Default insertion behavior
    static void stdInsertion(std::ostream &out, Strings const &strings, size_t idx);

    // Example custom manipulator
    static void only2(std::ostream &out, Strings const &strings, size_t idx);
};

#endif


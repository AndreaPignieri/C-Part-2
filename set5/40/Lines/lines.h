#ifndef LINES_H
#define LINES_H

#include <iostream>
#include <vector>
#include <string>

class Lines
{
public:
    Lines(std::istream &in);                   // Constructor
    ~Lines();                                  // Destructor

    const std::vector<std::string> &get() const;    // Get current object's lines
    const std::vector<std::string> &get(size_t idx) const; // Get lines of other objects by index

    Lines(const Lines &) = delete;            // Disable copy constructor
    Lines &operator=(const Lines &) = delete; // Disable copy assignment

private:
    size_t index;                             // Index of the current object in the shared container

    static std::vector<std::vector<std::string>> allLines; // Shared container for all objects' lines
};

#endif // LINES_H

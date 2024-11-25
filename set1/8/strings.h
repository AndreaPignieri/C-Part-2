#ifndef INCLUDED_STRINGS_
#define INCLUDED_STRINGS_

#include <string>
#include <vector>
#include <iostream>
#include <memory>

class Strings
{
    class Proxy; // Forward declaration of Proxy

    size_t *d_shared = nullptr;          // Shared count
    std::string *d_str = nullptr;        // Pointer to dynamic array of strings
    size_t d_size = 0;                   // Number of strings

public:
    Strings() = default;
    Strings(int argc, char **argv);      // From strings2_1.cc
    Strings(char **environLike);         // From strings2_2.cc
    Strings(Strings const &other);       // From strings3_1.cc
    Strings(Strings &&tmp) noexcept;    // From strings3_2.cc
    ~Strings();                         // From strings3_3.cc

    Strings &operator=(Strings const &rhs);     // From strings3_4.cc
    Strings &operator=(Strings &&rhs) noexcept; // From strings3_5.cc

    Strings &operator+=(std::string const &next); // From strings3_6.cc

    size_t size() const;                        // From strings3_7.cc
    void swap(Strings &other);                  // From strings3_8.cc

    std::string const &operator[](size_t idx) const; // From strings3_9.cc
    Proxy operator[](size_t idx);                    // From strings3_10.cc

private:
    void cow(); // From strings3_11.cc

    void allocate(size_t size); // From strings3_12.cc
};

// Nested Proxy class
class Strings::Proxy
{
    Strings *d_owner; // Owning Strings object
    size_t d_index;   // Index in the Strings object

public:
    Proxy(Strings *owner, size_t index);  // From strings3_13.cc
    Proxy &operator=(std::string const &value); // From strings3_14.cc
    operator std::string() const;              // From strings3_15.cc

    friend std::ostream &operator<<(std::ostream &out, Proxy const &proxy); // From strings3_16.cc
};

#endif // INCLUDED_STRINGS_

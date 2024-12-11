#ifndef STRING_HH
#define STRING_HH

#include <string>
#include <iostream>

class String: public std::string
{
    public:
        String() = default;

        using std::string::string;       //string constructors
        using std::string::operator=;

        ~String() = default;

        String &insert(std::string const &txt);
        bool operator==(String const &other);
        bool operator!=(String const &other);
        bool operator>=(String const &other);
        bool operator<=(String const &other);
        bool operator<(String const &other);
        bool operator>(String const &other);
};

inline String &String::insert(std::string const &txt)
{
    std::string::insert(0, txt);
    return *this;
}

inline bool String::operator==(String const &other)
{
    return (static_cast<std::string const &>(*this)) == 
        (static_cast<std::string const &>(other));
}

inline bool String::operator!=(String const &other)
{
    return (static_cast<std::string const &>(*this)) != 
        (static_cast<std::string const &>(other));
}

inline bool String::operator<=(String const &other)
{
    return (static_cast<std::string const &>(*this)) <= 
        (static_cast<std::string const &>(other));
}

inline bool String::operator>=(String const &other)
{
    return (static_cast<std::string const &>(*this)) >= 
        (static_cast<std::string const &>(other));
}

inline bool String::operator<(String const &other)
{
    return (static_cast<std::string const &>(*this)) < 
        (static_cast<std::string const &>(other));
}

inline bool String::operator>(String const &other)
{
    return (static_cast<std::string const &>(*this)) > 
        (static_cast<std::string const &>(other));
}

#endif
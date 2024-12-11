#ifndef STR_HH
#define STR_HH

#include <string>

class Str: public std::string
{
    public:
        Str() = default;
        Str(size_t count, std::string const &str);//the new constructor

        using std::string::string;       //string constructors
        using std::string::operator=;

        ~Str() = default;
};

#endif
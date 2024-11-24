#ifndef MSG_H
#define MSG_H

#include <type_traits>
#include <iostream>
#include <string>

// Strongly typed enum with bit flags
enum class Msg
{
    NONE = 0,
    DEBUG   = 1 << 0,
    INFO    = 1 << 1,
    NOTICE  = 1 << 2,
    WARNING = 1 << 3,
    ERR     = 1 << 4,
    CRIT    = 1 << 5,
    ALERT   = 1 << 6,
    EMERG   = 1 << 7,
    ALL     = (1 << 8) - 1
};

// Bitwise OR
inline Msg operator|(Msg lhs, Msg rhs)
{
    return static_cast<Msg>(
        static_cast<std::underlying_type_t<Msg>>(lhs) |
        static_cast<std::underlying_type_t<Msg>>(rhs)
    );
}

// Bitwise AND
inline Msg operator&(Msg lhs, Msg rhs)
{
    return static_cast<Msg>(
        static_cast<std::underlying_type_t<Msg>>(lhs) &
        static_cast<std::underlying_type_t<Msg>>(rhs)
    );
}

// Bitwise XOR
inline Msg operator^(Msg lhs, Msg rhs)
{
    return static_cast<Msg>(
        static_cast<std::underlying_type_t<Msg>>(lhs) ^
        static_cast<std::underlying_type_t<Msg>>(rhs)
    );
}

// Bitwise NOT
inline Msg operator~(Msg value)
{
    return static_cast<Msg>(
        ~static_cast<std::underlying_type_t<Msg>>(value) &
        static_cast<std::underlying_type_t<Msg>>(Msg::ALL)
    );
}

// Compound assignment operators
inline Msg &operator|=(Msg &lhs, Msg rhs)
{
    lhs = lhs | rhs;
    return lhs;
}

inline Msg &operator&=(Msg &lhs, Msg rhs)
{
    lhs = lhs & rhs;
    return lhs;
}

inline Msg &operator^=(Msg &lhs, Msg rhs)
{
    lhs = lhs ^ rhs;
    return lhs;
}

// Equality and inequality operators
inline bool operator==(Msg lhs, Msg rhs)
{
    return static_cast<std::underlying_type_t<Msg>>(lhs) ==
           static_cast<std::underlying_type_t<Msg>>(rhs);
}

inline bool operator!=(Msg lhs, Msg rhs)
{
    return !(lhs == rhs);
}

// Logical NOT operator
inline bool operator!(Msg value)
{
    return value == Msg::NONE;
}

// Show function
inline void show(Msg msg)
{
    // Array of enum names, matching the order of Msg values
    const char *const MsgNames[] = {
        "NONE", "DEBUG", "INFO", "NOTICE", "WARNING",
        "ERR", "CRIT", "ALERT", "EMERG", "ALL"
    };

    if (msg == Msg::NONE) // Handle Msg::NONE explicitly
    {
        std::cout << "NONE\n";
        return;
    }

    bool first = true; // To manage spacing
    for (size_t i = 1; i <= 8; ++i) // Iterate over bit positions (1 << 0 to 1 << 7)
    {
        Msg current = static_cast<Msg>(1 << (i - 1));
        if (static_cast<std::underlying_type_t<Msg>>(msg) &
            static_cast<std::underlying_type_t<Msg>>(current))
        {
            if (!first)
                std::cout << " ";
            std::cout << MsgNames[i];
            first = false;
        }
    }
    std::cout << "\n";
}

#endif // MSG_H

/*
Output is from given main code is:

NONE
EMERG
CRIT ALERT
WARNING ERR
DEBUG INFO WARNING ERR CRIT ALERT EMERG
*/

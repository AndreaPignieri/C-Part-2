#ifndef MSG_HH
#define MSG_HH

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

Msg operator&(Msg lhs, Msg rhs);    // and
Msg operator|(Msg lhs, Msg rhs);     // or
Msg operator^(Msg lhs, Msg rhs);    // xor
Msg operator~(Msg rhs);            // not bitwise
bool operator==(Msg lhs, Msg rhs);   //equality test
bool operator!=(Msg lhs, Msg rhs);   // inequality test
bool operator!(Msg rhs);             // not operator
void show(Msg msg);


#endif

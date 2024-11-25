#include "msg.ih"

Msg operator&(Msg lhs, Msg rhs)
{
    return static_cast<Msg>
        (static_cast<unsigned int>(lhs) & static_cast<unsigned int>(rhs));
}
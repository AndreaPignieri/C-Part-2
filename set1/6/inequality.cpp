#include "msg.ih"

bool operator!=(Msg lhs, Msg rhs)
{
    return (static_cast<unsigned int>(lhs) != static_cast<unsigned int>(rhs));
}
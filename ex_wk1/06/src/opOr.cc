#include "../headers/msg.ih"

Msg operator|(Msg lhs, Msg rhs)
{
    return static_cast<Msg>(static_cast<int>(rhs) | static_cast<int>(lhs));
}
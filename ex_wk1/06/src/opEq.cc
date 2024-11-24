#include "../headers/msg.ih"

bool operator==(Msg lhs, Msg rhs)
{
    return (static_cast<int>(rhs) == static_cast<int>(lhs));
}
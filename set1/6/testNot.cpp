#include "msg.ih"

bool operator!(Msg rhs)
{
    if (rhs == Msg::NONE)
        return true;

    return false;
}
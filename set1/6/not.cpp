#include "msg.ih"

Msg operator~(Msg rhs)
{
    return static_cast<Msg>
        (~static_cast<unsigned int>(rhs));
}
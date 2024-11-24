#include "../headers/msg.ih"

Msg operator~(Msg msg)
{
    return static_cast<Msg>(~static_cast<int>(msg));
}
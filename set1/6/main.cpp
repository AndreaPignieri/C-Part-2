#include "msg.hh"
#include <iostream>

using namespace std;

int main()
{
    show(Msg::NONE);
    show(Msg::EMERG);
    show(Msg::ALERT | Msg::CRIT);
    show(Msg::ALL   & (Msg::ERR | Msg::WARNING));
    show(~Msg::NOTICE);
}
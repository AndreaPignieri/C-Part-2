#ifndef HANDLER_HH
#define HANDLER_HH

#include "../base/base.hh"

class Handler : public Base
{
    public:
    // The enum class Msg is available for its members but not outside of this class
        Msg message;    
};

#endif

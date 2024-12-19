#ifndef HANDLER_HH
#define HANDLER_HH

#include "../base/base.hh"

class Handler : private Base
{ //because of private not even a class inheriting Handler can use Msg
    // The enum class Msg is available for its members but not outside of this class
        Msg message;    

    public:
        //member functions that can use Msg
};

#endif

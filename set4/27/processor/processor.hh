#ifndef PROCESSOR_HH
#define PROCESSOR_HH

#include "../base/base.hh"

class Processor : private Base
{//because of private not even a class inheriting Processor can use enum

    // The enum class Msg is available for its members but not outside of this class
    Msg message;

    public:
        //processor member functions
};

#endif

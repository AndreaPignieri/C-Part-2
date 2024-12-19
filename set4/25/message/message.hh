#ifndef MESSAGE_HH
#define MESSAGE_HH

#include "../base/base.hh"
#include <fstream>

class Message
{
    Base &d_base;

    public:
        Message(Base &base);
        ~Message() = default;

        void show(std::ostream &out) const;
};

inline Message::Message(Base &base)
:
    d_base(base)
{}

inline void Message::show(std::ostream &out) const
{
    d_base.hello(out);   //calls Base::hello
}

#endif
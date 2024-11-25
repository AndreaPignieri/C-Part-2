#include "msg.ih"

void show(Msg msg)
{   //static file so that it is only created once
    static char const *flags[] = 
        {"DEBUG", "INFO", "NOTICE", "WARNING", 
            "ERR", "CRIT", "ALERT", "EMERG"};
    
    if (!msg)             //special case
        cout << "NONE";

    for (size_t idx = 0; idx != 8; ++idx)   //go through the enum flags
    {
        //in the following if statement we construct 8 bits with a single 1
        //at the position we are checking if its occupied and convert it to Msg
        //Then through bitwise & we have Msg::NONE (which shows this flag is not raised)
        //or something else. Then we use double not operator. The first is the overloaded
        // operator!(Msg) the second is the operator!(bool).
        //This is the result of not using a class wrapper that would allow an operator bool()
        //conversion operator.
        if (!! (msg & static_cast<Msg>(1 << idx)))  
            cout << flags[idx] << ' ';
    }

    cout << '\n';
}

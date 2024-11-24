#include "msg.ih"

void show(Msg msg)
{
    static char const *flags[] = 
        {"DEBUG", "INFO", "NOTICE", "WARNING", 
            "ERR", "CRIT", "ALERT", "EMERG"};
    
    if (!msg)
        cout << "NONE";

    for (size_t idx = 0; idx != 8; ++idx)
    {
        if (!! (msg & static_cast<Msg>(1 << idx)))
            cout << flags[idx] << ' ';
    }

    cout << '\n';
}
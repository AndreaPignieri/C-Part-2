#include "../headers/msg.ih"

void show(Msg msg)
{
    char const *messages[] = {"DEBUG", "INFO", "NOTICE",
     "WARNING", "ERR", "CRIT", "ALERT", "EMERG", "ALL"};
    
    if (msg == Msg::NONE)
    {
        std::cout << "NONE" << std::endl;
        return;
    }
    
    for (int idx = 0; idx != 8; ++idx)
    {
        Msg current = Msg(1 << idx);
        if ((msg & current) == current)
        {
            std::cout << messages[idx] << " ";
        }
    }
    std::cout << std::endl;
}
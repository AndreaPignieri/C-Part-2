#include "main.ih"

void loading(std::stop_token stopToken)
{
    while (!stopToken.stop_requested())
    {
        std::cerr << ".";
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}
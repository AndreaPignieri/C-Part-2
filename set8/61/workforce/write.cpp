#include "workforce.ih"

void Workforce::write(ostream &out)
{
    d_outHandler.notify(); // the out-handler is on-line
    while (true)
    {
        string line;
        d_result.wait(); // wait for available result
        if (not another(line, d_resultQ))
            break;
        d_outHandler.notify_all(); // multiple handlers
        out << line << '\n'; // so use notify_all!
    }
}
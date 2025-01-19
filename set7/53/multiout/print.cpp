#include "multiout.ih"

void MultiOut::print(size_t threadNr)
{
    osyncstream out{cout};

    for (size_t lineNr = 0; lineNr != 4; ++lineNr)
    {
        cout << "thread " << threadNr << '\n';
        out << "Line " << lineNr << " from thread " << threadNr << '\n';
    }

}
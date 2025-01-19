#include "main.ih"

int main(int argc, char** argv)
try
{
    if (argc == 1)
        throw;
    
    jthread threadarr[argc];
    Storage storage[argc];

    createThreads(threadarr, storage, argc, argv);

    string line;
    while (getline(cin, line))
        storage[0].push(line);      //only static members

    storage[0].finished();

    for (auto &thr : threadarr)
    {
        if (thr.joinable())
            thr.join();
    }
}
catch(...)
{
    cerr << "an exception was thrown";
}
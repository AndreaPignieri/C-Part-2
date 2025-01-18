#ifndef MULTIOUT_HH
#define MUTLTIOUT_HH

#include <cstddef>
#include <string>

class MultiOut
{
    size_t d_threadNr;

    public:
        MultiOut(std::string const threadNr);

        void run();
        static void print(size_t threadCount);
};

inline MultiOut::MultiOut(std::string const threadNr)
:
    d_threadNr(stoul(threadNr))
{}

#endif
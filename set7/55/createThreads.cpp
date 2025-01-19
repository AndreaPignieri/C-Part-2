#include "main.ih"

void createThreads(jthread* const &threadarr, Storage* const &storage,
                    int argc, char**argv)
{
    for (int idx = 1; idx != argc; ++idx) 
        threadarr[idx - 1] = jthread
        ( &Storage::newThread, ref(storage[idx - 1]), argv[idx], argc);
    //idx is set to 1 for better readability 
    //int for compatibility with argc
}
#include "storage.ih"

void Storage::newThread(string const &fileName, size_t threadNr)
{
    ofstream out(fileName);
    if (!out.is_open())
        throw;


    while (!s_finished || !empty())                 
    {//empty needed to avoid skipping one lines, finished() is called outside of here
    
        this_thread::sleep_for(chrono::seconds(1));

        if (!empty())
            write(out, threadNr);
    }
}
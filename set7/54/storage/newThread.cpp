#include "storage.ih"

void Storage::newThread(string const &fileName)
{
    ofstream out(fileName);
    if (!out.is_open())
        throw;


    while (!d_finished || !empty())                 
    {//empty needed to avoid skipping lines in the end, 
        //finished() is called outside of here
    
        this_thread::sleep_for(chrono::seconds(1));

        write(out);
    }
}
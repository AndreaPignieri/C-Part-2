#include "workforce.ih"

bool Workforce::another(string &line, queue<string> &queue)
{
    lock_guard<mutex> _(d_mutex);   //multiple workers mean process might try adding on queue
                                    //at the same time despite the Semaphores
    if (queue.empty())              //end the program
        return false;
        
    line = queue.front();
    queue.pop();
    return true;
}
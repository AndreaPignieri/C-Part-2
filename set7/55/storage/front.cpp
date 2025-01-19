#include "storage.ih"

string Storage::front()
{
    string temp;                            //declared here to save time outside the lock
    shared_lock<shared_mutex> _(shMutex); 
    temp = s_lines.front();
    return temp;
}//fron needs to return a string value instead of a reference and it's better for readability 
//to have the locks withing the function call, no danger of exception thrown and messing up
//the queue since we are only reading
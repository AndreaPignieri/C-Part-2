#include "storage.ih"

void Storage::push(string const &value)
{
    string temp {value};                     //safe rollback
    unique_lock<shared_mutex> _(s_mutex);   //the state of queue will change
    d_lines.push(temp);                     
}
//whenever .push() is called we'll have to change the state of queue thus it needs
//to be locked from the rest of the threads till the push() is complete
//in case exception is thrown during temp copying nothing will be added to d_lines
//keeping the state of the queue safe.

#include "storage.ih"

void Storage::write(ostream &out)
{
    if (!empty())
    {
        string temp;                //decrease time within the lock
        unique_lock<shared_mutex> lock(s_mutex);   //pop requires uniq_lock
        temp = front(); 
        pop();
        lock.unlock();
        out << temp << "\n";       //decrease the time within the lock
    }//unlocking
}
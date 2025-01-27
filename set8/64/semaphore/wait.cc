#include "semaphore.ih"

void Semaphore::wait ()
{
    unique_lock<mutex> lk(d_mutex);    //get lock
    while (d_available == 0)
        d_cond.wait(lk);
    --d_available;
}
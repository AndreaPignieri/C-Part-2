#include "semaphore.ih"

void Semaphore::notify ()
{
    lock_guard<mutex> lk(d_mutex);
    if (d_available++ == 0)
        d_cond.notify_one();
}

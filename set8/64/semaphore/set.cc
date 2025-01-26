#include "semaphore.ih"

void Semaphore::set(size_t nAvailable)
{
    lock_guard<mutex> lk(d_mutex);
    d_available.store(nAvailable);
    d_cond.notify_all();         //all waiting threads notified
}



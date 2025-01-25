#include "semaphore.ih"

void Semaphore::notify_all() 
{
    lock_guard<mutex> _(d_mutex);
    if (++d_nAvailable == 1)       //checks if d_nAvailabe was 0 when notify was called
        d_cv.notify_all();
}
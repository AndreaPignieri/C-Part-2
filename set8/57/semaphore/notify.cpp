#include "semaphore.ih"

void Semaphore::notify() 
{
    lock_guard<mutex> _(d_mutex);
    if (++d_nAvailable == 1)       //checks if d_nAvailabe was 0 when notify was called
        d_cv.notify_one();
}
//in the annotations postfix increment is used with 0
//if we use prefix increment and check for 1, we evade one copy
//also atomic increment is noexcept, so its exception safe.
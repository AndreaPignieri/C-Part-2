#include "semaphore.ih"

void Semaphore::wait()
{
    unique_lock<mutex> lock(d_mutex); //gets the lock of d_mutex
    while (d_nAvailable == 0)
        d_cv.wait(lock);               //releases the lock
                                        //retakes the lock after wait release
    --d_nAvailable;                   //rest of the threads will wait more

}//lock released now
//the rest of waits actually wait to aquire the lock
//so only one wait will be released
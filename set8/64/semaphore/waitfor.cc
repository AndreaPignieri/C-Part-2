#include "sephamore.ih"

bool Semaphore::wait_for(size_t seconds)
{
    unique_lock<mutex> lk(d_mutex);
    bool success = d_cond.wait_for(lk, chrono::seconds(seconds),
        [this](){return d_available > 0; });
    if (success)
        --d_available;
    return success;
}

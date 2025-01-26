#ifndef INCLUDED_SEMAPHORE_
#define INCLUDED_SEMAPHORE_
#include <mutex>
#include <atomic>
#include <condition_variable>

class Semaphore
{
    mutable std::mutex d_mutx;
    std::condition_variable d_cond;
    std::atomic<size_t> d_available;

    public:
        Semaphore(size_t nAvailable);
        
        void wait();
        void notify_all();
        void notify();
        size_t size() const;
        void set(size_t nAvailable);
        bool wait_for(size_t seconds);
    private:
};
   

inline Sephemore::Semaphore(size_t nAvailable)
:
    d_available(nAvailable)
{}

inline size_t Semaphore::size() const
{
    return d_available.load();
}


#endif

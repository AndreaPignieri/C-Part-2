#ifndef INCLUDED_SEMAPHORE_HH
#define INCLUDED_SEMAPHORE_HH
#include <mutex>
#include <atomic>
#include <condition_variable>

class Semaphore
{
    mutable std::mutex d_mutex;
    std::condition_variable d_cond;
    std::atomic<size_t> d_available;

    public:
        Semaphore(size_t nAvailable);
        Semaphore();
        void wait();
        void notify_all();
        void notify();
        size_t size() const;
        void set(size_t nAvailable);
        bool wait_for(size_t seconds);
    private:
};
   

inline Semaphore::Semaphore(size_t nAvailable)
:
    d_available(nAvailable)
{}

inline size_t Semaphore::size() const
{
    return d_available.load();
}


#endif

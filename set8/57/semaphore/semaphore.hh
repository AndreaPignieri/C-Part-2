#ifndef SEMAPHORE_HH
#define SEMAPHORE_HH

#include <atomic>
#include <mutex>
#include <condition_variable>

class Semaphore 
{
    std::condition_variable d_cv;
    std::mutex d_mutex;
    std::atomic<size_t> d_nAvailable;       //available threads

    public:
        Semaphore(size_t nAvailable);

        void notify();
        void notify_all();
        std::atomic<size_t> size() const;
        void wait();
};

inline Semaphore::Semaphore(size_t nAvailable)
:
    d_nAvailable(nAvailable)
{}

inline std::atomic<size_t> Semaphore::size() const
{
    return d_nAvailable.load();
}

#endif
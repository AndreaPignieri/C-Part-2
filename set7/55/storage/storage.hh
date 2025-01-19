#ifndef STORAGE_HH
#define STORAGE_HH

#include <queue>
#include <mutex>
#include <shared_mutex>
#include <atomic>
#include <cstring>
#include <fstream>
#include <condition_variable>

class Storage 
{
    static std::condition_variable topop;
    std::mutex d_wait;
    static std::shared_mutex shMutex;
    static std::queue<std::string> s_lines;
    static std::atomic<bool> s_finished;
    static std::atomic<size_t> s_waiting;
    std::atomic<size_t> d_size = 0;

    public:
        Storage() = default;

        void newThread(std::string const &file, size_t threadNr);
        void write(std::ostream &out, size_t threadNr);

        std::string front();
        void pop();
        void push(std::string const &line);
        bool empty();

        void finished();
        size_t size() const;
};

inline void Storage::pop()
{
    s_lines.pop();
}

inline void Storage::finished()
{
    s_finished.store(true);
}

inline size_t Storage::size() const
{
    return d_size;
}

#endif
#ifndef STORAGE_HH
#define STORAGE_HH

#include <queue>
#include <mutex>
#include <shared_mutex>
#include <thread>
#include <atomic>
#include <cstring>
#include <fstream>

class Storage 
{
    std::queue<std::string> d_lines;        
    std::atomic<bool> d_finished {false};
    static std::shared_mutex s_mutex;       //for reading and changing the queue

    public:
        Storage() = default;

        void newThread(std::string const &file);
        void write(std::ostream &out);

        std::string front() const;
        void pop();
        void push(std::string const &line);
        bool empty();
        void finished();
};

inline std::string Storage::front() const
{
    return std::string{d_lines.front()};
}//front() will be returning to a different thread, the original member
//returned a reference which is not safe to be sent to a different thread
//we send the value instead

inline void Storage::pop()
{
    d_lines.pop();
}

inline void Storage::finished()
{
    d_finished.store(true);
}

#endif
#ifndef INCLUDED_TASK_
#define INCLUDED_TASK_
#include <iostream>
#include <fstream>
#include <string>
#include <mutex>

class Task
{
    std::string d_fileName;    //filename
    std::string d_label;        //task label
    size_t d_count = 0;       //no. of chars
    bool (*charSelect)(char);  //func pointer for character select
    mutable std::mutex d_mutex; //protect access to d_count
    
    public:
        //Constructor takes function and label
        Task(bool (selector)(char), const std::string &taskLabel)
            : d_label(taskLabel), charSelect(*selector) {}
        
        void setFileName(const std::string &file); //setter for d_fileName
        void operator()();   //lets Task be called
        size_t getCount() const;  //getter for d_count
        const std::string &getLabel() const;   //getter for d_label
    private:
};

//Simple inline definitions
inline void Task::setFileName(const std::string &file)
{
    d_fileName = file;
}

inline size_t Task::getCount() const
{
    std::lock_guard<std::mutex> lg(d_mutex);
    return d_count;
}

inline const std::string &Task::getLabel() const
{
    return d_label;
}
#endif

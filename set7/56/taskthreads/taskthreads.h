#ifndef INCLUDED_TASKTHREADS_
#define INCLUDED_TASKTHREADS_
#include <array>
#include <thread>
#include <iostream>
#include <chrono>
#include <string>
#include <cstring>
#include "task/task.h"

class TaskThreads
{
    std::string d_fileName;    //filename
    std::array<Task, 4> d_tasks;  //array of task objects
    std::array<std::thread, 4> d_threads;  //array of threads
    bool d_sequential;  //sequential or paralell
    std::chrono::duration<double> d_time;  //to track time

    public:
        //Constructor takes file and mode
        TaskThreads(const std::string &file, bool sequential);
        void run();   //runs multithread of Task
        void display() const; //display time and results
};


#endif

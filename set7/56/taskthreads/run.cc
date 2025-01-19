#include "taskthreads.ih"

void TaskThreads::run()
{
    //start time
    auto start = chrono::high_resolution_clock::now();
    //set filename for all tasks
    for (auto &task : d_tasks)
        task.setFileName(d_fileName);
    //check for sequential or paralell    
    if (d_sequential)
    {
        //call tasks for each d_task
        for (auto &task : d_tasks)
            task();
    }
    else //paralell
    {
        //creates thread for each d_thread
        for (size_t idx = 0; idx != d_tasks.size(); ++idx)
            d_threads[idx] = thread(ref(d_tasks[idx]));
        for (auto &t : d_threads)
        {
            if (t.joinable())
                t.join();
        }
    }
    //record end time
    auto end = chrono::high_resolution_clock::now();
    d_time = end - start;
}

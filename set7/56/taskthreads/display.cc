#include "taskthreads.ih"

void TaskThreads::display() const
{
    //display results for each task
    for (const auto &task : d_tasks)
        cout << task.getLabel() << ": " << task.getCount() << "\n";
    //display time elapsed
    cout << "Time elapsed: " << d_time << " seconds\n";
}

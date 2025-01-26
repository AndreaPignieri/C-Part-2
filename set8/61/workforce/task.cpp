#include "workforce.ih"

void Workforce::task()
{
    d_worker.notify();          //increment the number of workers

    while (true)
    {
        d_job.wait();        //wait for a job
        string line;

        if (not another(line, d_workQ))
        {
            d_job.notify();
            break;
        }
        d_worker.notify();         //continue inputs to workQ
        d_outHandler.wait();      //used for locking for resultQ

        reverse(line.begin(), line.end());                 //reverse the letters
        d_resultQ.push(line);           
        d_result.notify();               //notifies that a line is ready for output
    }
}
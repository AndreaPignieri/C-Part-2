#include "workforce.ih"

void Workforce::process(istream &in)
{
    string line;
    while (getline(in, line))
    {
        d_worker.wait();                //wait for available workers

        {
            lock_guard<mutex> _(d_mutex);
            d_workQ.push(line);              //add new job
        }

        d_job.notify_all();          //notify all workers there is a new job in the q
    }
}
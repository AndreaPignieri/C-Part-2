#include "workforce.ih"

void Workforce::run(istream &in, ostream &out)
{
    thread output(&Workforce::write, this, ref(out));
    thread worker1(&Workforce::task, this);
    thread worker2(&Workforce::task, this);

    process(in);

    d_job.notify_all();  //end of program makes workers check Q and see its empty

    worker1.join();
    worker2.join();

    d_result.notify();      //for output to exit its loop as well
    output.join();
}
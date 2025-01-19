#include "storage.ih"

//threadNr also counts 
void Storage::write(ostream &out, size_t threadNr)
{    
    out << front() << "\n";                 //take the front element to the stream
    ++d_size;                              //for final use
    
    if (++s_waiting == threadNr - 1)     //signal this thread has wrote down this front
    {                                     //and check if it is the last thread to do so
        unique_lock<shared_mutex> _(shMutex);   //its for editing
        pop();
        s_waiting.store(0, memory_order_release); //reset for the next line to be read
        topop.notify_all();                       //notify the threads that finished 1st
    }
    else 
    {
        unique_lock<mutex> lock(d_wait);          
        //while protects in case of a wait escape for no reason
        //and in case a thread is delayed but not last, will not enter wait
        //when notify_all has already been sent
        while (s_waiting.load(memory_order_acquire) != 0)    
            topop.wait(lock);              //wait for every thread to read the line
    }

    //topop.notify_one();
}
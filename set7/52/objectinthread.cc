#include "main.ih"

void objectinthread(const string &filename, const string &input)
{
    thread t2([&]()   
    {   //append stream to file
        ofstream file(filename, std::ios::app);
        Handler h;          //initialize object in thread Lambda
        h.shift(file, input);   //shift object
    
    });
    t2.join();      //wait for thread to complete
}

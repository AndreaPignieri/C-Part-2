#include "main.ih"

void objectinmain(const string &filename, const string &input)
{
    Handler h;                //initialize handler object
    ofstream file(filename);  //stream to file
    
    if (!file)                //throw if no file
        throw string("no file");
    
    //thread and shift h object
    thread t1([&h, &file, input](){h.shift(file, input);});
    t1.join();     //wait for complete
}

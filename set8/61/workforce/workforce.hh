#ifndef WORKFORCE_HH
#define WORKFORCE_HH

#include "../../57/semaphore/semaphore.hh"
#include <string>
#include <fstream>
#include <queue>
#include <mutex>

class Workforce 
{
    std::mutex d_mutex;                         //for changes in workQ
    std::queue<std::string> d_workQ;            //unporcessed lines
    std::queue<std::string> d_resultQ;          //processed lines
    Semaphore d_result{0};                      //resultQ availability
    Semaphore d_outHandler{0};                  //write thread avail
    Semaphore d_worker{0};                      //task thread avail
    Semaphore d_job{0};                         //workQ avail
    
    public:
        void run(std::string const &inFile, std::string const &outFile);
        void run(std::istream &in, std::ostream &out);

    private:
        void process(std::istream &in);
        bool another(std::string &line, std::queue<std::string> &queue);    //checking emptiness of queue and copies/pops front elemnt
        void task();
        void write(std::ostream &out);
};

#endif
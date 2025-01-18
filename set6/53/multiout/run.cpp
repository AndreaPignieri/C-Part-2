#include "multiout.ih"

void MultiOut::run()
{
    thread thread0{ print, 0};
    thread thread1{ print, 1};
    thread thread2{ print, 2};

    thread0.join();
    thread1.join();
    thread2.join();
}
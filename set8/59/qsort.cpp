#include "main.ih"

void Qsort(int *beg, int *end)
{
    if (end - beg <= 1)
        return;

    int lhs = *beg;
    int *mid = partition(beg + 1, end, 
        [&](int arg)
        {
            return arg < lhs;
        }
    );
    
    swap(*beg, *(mid - 1));
    
    //simple qsort but using threads
    auto fut1 = async(launch::async, Qsort, beg, mid);
    auto fut2 = async(launch::async, Qsort, mid, end);

    fut1.get();
    fut2.get();
}
#include <iostream>
#include <future>

using namespace std;

string threadFun()
{
    cerr << "entry\n";
    
    this_thread::sleep_for(chrono::seconds(5));
    cerr << "first cerr\n";
    
    this_thread::sleep_for(chrono::seconds(5));
    cerr << "second cerr\n";
    
    return "end the program";
}

int main()
{
    size_t count = 0;
    auto future = async(launch::async, threadFun);

    while (true)
    {
        this_thread::sleep_for(chrono::seconds(1));
        cerr << "inspecting: " << ++count << '\n';

        if (future.wait_until(chrono::steady_clock::now()) == future_status::ready)
        {
            if (future.get() == "end the program")   //the returned value indicates to end the program
                break;
        }

    }


    cerr << "done\n";
}

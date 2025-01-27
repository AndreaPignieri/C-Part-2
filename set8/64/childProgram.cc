#include <iostream>
#include <string>
#include <chrono>
#include <thread>

using namespace std;
using namespace chrono;

int main(int argc, char **argv)
try
{
    if (argc == 1)
        throw 1;

    for (size_t count = 0, end = stoul(argv[1]); count != end; )
    {
        cout << "line " << ++count << " from " << argv[0] << endl;
        this_thread::sleep_for(seconds(2));
    }
}
catch (...)
{
    cout << argv[0] << " needs a non-negative integral first argument\n";
}
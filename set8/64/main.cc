#include "main.ih"
using namespace std;


int main(int argc, char **argv)
{
    if (argc < 3)
    {
        cerr << "Name of program to execute and number of lines are needed parameters\n";
        return 1;
    }

    string const childProgram = argv[1];
    string const numLines = argv[2];
    size_t const timeout = argc == 4 ? stoul(argv[3]) : 0;

    Semaphore sem(0); // Initialize semaphore
    bool timeoutOccurred = false;

    LinePrinterFork forkProcess(childProgram, numLines, sem, timeoutOccurred, timeout);

    try
    {
        forkProcess.fork();
    }
    catch (exception const &e)
    {
        cerr << "Exception: " << e.what() << '\n';
        return 1;
    }
}
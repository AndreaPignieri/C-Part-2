#include "linePrinterFork.ih"

void LinePrinterFork::parentRedirections()
{   
    if (d_timeout != 0) // If timeout is set
    {
        if (!d_semaphore.wait_for(d_timeout)) // Semaphore wait with timeout
        {
            // Timeout occurred
            cout << "Program ended at timeout\n";
            kill(pid(), 2);  // Terminate the child process
            return;
        }
    }
    else
    {
        d_semaphore.wait(); // Wait for the child to finish
        cout << "Program ended normally\n";
    }
}
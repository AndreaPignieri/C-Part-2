#include "linePrinterFork.ih"

void LinePrinterFork::parentProcess()
{
    // Parent process waits for the child process to finish
    int status = waitForChild();

    if (WIFSIGNALED(status)) // Check if the child was terminated by a signal
    { 
        d_timeoutOccurred = true;
    }

    // Notify semaphore that the process has finished
    d_semaphore.notify();
}
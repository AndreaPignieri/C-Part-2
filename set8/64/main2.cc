#include "main2.ih"

void monitorProcess(pid_t pid, Semaphore &sem, bool &timeoutOccurred, size_t timeout) 
{
    if (!sem.wait_for(timeout)) 
    {
        // Timeout occurred
        timeoutOccurred = true;
        kill(pid, 2); // Kill the child process
    }
}

int main(int argc, char **argv) 
{
    if (argc < 3) 
    {
        cerr << "Usage: " << argv[0] << " <child_program_path> <num_lines> [timeout_seconds]\n";
        return 1;
    }

    string childProgram = argv[1];
    string numLines = argv[2];
    size_t timeout = argc == 4 ? stoul(argv[3]) : 0;

    Semaphore sem; // Fixed vexing parse issue
    bool timeoutOccurred = false;

    pid_t pid = fork();
    if (pid < 0) 
    {
        cerr << "Failed to fork process\n";
        return 1;
    }

    if (pid == 0) 
    {
        // In child process
        execl(childProgram.c_str(), childProgram.c_str(), numLines.c_str(), nullptr);
        cerr << "Failed to execute child program\n";
        return 1;
    }

    // In parent process
    thread monitorThread;
    if (timeout > 0)
        monitorThread = thread(monitorProcess, pid, ref(sem), ref(timeoutOccurred), timeout);

    // Wait for the child process to complete
    int status;
    waitpid(pid, &status, 0);

    // Notify the semaphore that the process has finished
    sem.notify();

    // If a timeout thread was started, join it
    if (monitorThread.joinable())
        monitorThread.join();

    // Print the appropriate message
    if (timeoutOccurred)
        cout << "Program ended at timeout\n";
    else
        cout << "Program ended normally\n";
}
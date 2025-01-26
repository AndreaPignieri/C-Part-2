#ifndef LINE_PRINTER_FORK_H
#define LINE_PRINTER_FORK_H

#include <string>
#include "../fork/fork.hh"
#include "../semaphore/semaphore.hh"

using namespace std;

class LinePrinterFork : public Fork
{
    string const d_childProgram;
    string const d_numLines;
    Semaphore &d_semaphore;
    bool &d_timeoutOccurred;
    size_t const d_timeout;

    public:
        LinePrinterFork(string const &childProgram, string const &numLines,
        Semaphore &semaphore, bool &timeoutOccurred, size_t timeout)
            : d_childProgram(childProgram), d_numLines(numLines), d_semaphore(semaphore),
            d_timeoutOccurred(timeoutOccurred), d_timeout(timeout) {}
        ~LinePrinterFork();
    private:
        void childRedirections();
        void parentRedirections();
        void childProcess() override;
        void parentProcess() override;
};

#endif
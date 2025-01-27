#include "linePrinterFork.ih"

void LinePrinterFork::childProcess()
{
        execl(d_childProgram.c_str(), d_childProgram.c_str(), d_numLines.c_str(), nullptr);
        cerr << "Failed to execute child program\n";
        exit(1);
}
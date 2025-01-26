#include "workforce.ih"

void Workforce::run(std::string const &inFile, std::string const &outFile)
{
    ifstream in(inFile);
    ofstream out(outFile);

    if (!in.is_open() || !out.is_open())
        throw ;

    run(in, out);
}
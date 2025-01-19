#include "main.ih"

int main(int argc, char** argv)
try
{
    if (argc == 1) //no file input
        throw;

    Storage storage;                
    jthread write ( &Storage::newThread, ref(storage), argv[1]);

    string line;
    while (getline(cin, line))
        storage.push(line);

    storage.finished();
    //input stopped send signal to other thread to stop

    write.join();
}
catch(...)
{
    cerr << "an exception was thrown";
}
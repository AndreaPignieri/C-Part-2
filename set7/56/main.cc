#include "main.ih"

int main(int argc, char *argv[])
{
    try
    {
        //ensure correct no. of arguments
        if (argc < 2)
            throw string("invalid no. of arguments");
        
        //asign arguments to variables
        string fileName = argv[1];
        bool sequential = (argc > 2);
        
        //taskthreads object
        TaskThreads t(fileName, sequential);
        
        t.run();
        t.display();
    }
    catch (const string &err)
    {
        cerr << "Error: " << err << endl;
        return 1;
    }
}

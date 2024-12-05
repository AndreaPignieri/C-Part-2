#include "main.ih"

int main(int argc, char **argv)
try   //outer try block to catch unexpected exceptions
{
    try //inner try block 1
    {
        Arg const &arg = Arg::instance(argc, argv, "ace:fg:h");
    }
    catch (int caught) //catches 0 or 1
    {
        if (caught == 0) //-h specified
            return 0;     //return to OS
        else if (caught == 1)    //abort the program
        {
            cerr << "Exception: invalid argument.\n";
            return 1;
        }
    }
    try  //inner try block 2
    {
        Process process{ Arg::instance(argc, argv, "ace:fg:h") };
    }
    catch (string &fileName)   //catches file that cant be read
    {
        cerr << "Error cannot read: " << fileName << "\n";
        return 1;   //abort the program
    }
    try   //inner try block 3
    {
        Process process{ Arg::instance(argc, argv, "ace:fg:h") };
        process.run();
    }
    catch (exception const &exc)  //catches exception
    {
        cerr << exc.what() << "\n";  //shows what was caught
        return 1;
    }
}
catch (...)  //outer catch for unspecified exceptions
{
    cerr << "unexpected exception \n";
    return 1;
}

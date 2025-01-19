#include "main.ih"

int main()
{
    //get and assign name for file and text
    string file, text;
    cout << "file name: \n";
    getline(cin, file);
    cout << "text: \n";
    getline(cin, text);
    try
    {
        //create handle object then thread shift
        objectinmain(file, text);
        //create handle object IN thread and shift
        objectinthread(file, text);
    }
    catch (const string &err)
    {
        cerr << "Error: " << err << endl;
        return 1;
    }
}

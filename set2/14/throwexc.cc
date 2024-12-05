#include "tempfile/tempfile.ih"
//demonstrate cleanup when exception is thrown
int main()
{
    filesystem::path tempName; //set path
    try
    {
        TempFile temp;   //initialize object
        tempName = temp.name();   //save name
        //output name
        cout << "Temp file exists:" << tempName << "\n";
        //throw exception 
        throw runtime_error("Unrelated exception.");
    }
    catch (const exception &exc)  //catch exception
    {
        cerr << exc.what() << "\n";
    }
    //out of scope check name for "0"
    cout << "File exists out of scope:"
         << filesystem::exists(tempName) << "\n";
}

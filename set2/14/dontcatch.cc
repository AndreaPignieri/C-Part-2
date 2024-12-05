#include "tempfile/tempfile.ih"
//demonstrate tempfile memory leak
int main()
{
    filesystem::path tempName; //set path
    {
        TempFile temp;   //initialize object
        tempName = temp.name();   //save name
        //output name
        cout << "Temp file exists:" << tempName << "\n";
        //throw exception without catch
        throw runtime_error("Unrelated exception.");
        //out of scope check name for "0"
        cout << "File exists out of scope:"
         << filesystem::exists(tempName) << "\n";
    }
}

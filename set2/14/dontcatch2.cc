#include "tempfile/tempfile.ih"
using namespace std;
//demonstrate cleanup when tempfile is out of scope
int main()
{
    filesystem::path tempName; //set path
    {
        TempFile temp(true);   //initialize object
        tempName = temp.name();   //save name
        //output name
        cout << "Temp file exists:" << tempName << "\n";
        //throw exception 
        throw runtime_error("Unrelated exception.");
        //out of scope check name for "0"
        cout << "File exists out of scope:"
         << filesystem::exists(tempName) << "\n";
    }
}


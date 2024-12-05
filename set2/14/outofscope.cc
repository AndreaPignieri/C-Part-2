#include "tempfile/tempfile.ih"
//demonstrate cleanup when tempfile is out of scope
int main()
{
    filesystem::path tempName; //set path
    {
        TempFile temp;   //initialize object
        tempName = temp.name();   //save name
        //output name
        cout << "Temp file exists:" << tempName << "\n";
    }
    //out of scope check name for "0"
    cout << "File exists out of scope:"
         << filesystem::exists(tempName) << "\n";
}

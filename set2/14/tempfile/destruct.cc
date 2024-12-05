#include "tempfile.ih"
//destructor
TempFile::~TempFile()
{
    //close stream delete file
    if (file.is_open())
        file.close();     //close stream
    if (!filename.empty() && filesystem::exists(filename))
            filesystem::remove(filename);    //delete tmp file    
}

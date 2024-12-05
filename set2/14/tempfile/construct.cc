#include "tempfile.ih"

TempFile::TempFile(bool unlinkFile,
                 std::filesystem::path const &directory,
                 std::filesystem::path const &filename_pattern,
                 std::filesystem::perms permissions)
    : filename(directory/ filename_pattern)
{
    //opens a stream to tempfile
    //allows read and write
    try
    {
        file.open(filename, ios::in | ios::out | ios::trunc);
        if (!file)
            throw runtime_error("Failed to create/open tmp file");
        filesystem::permissions(filename, permissions);
    }
    catch (...) 
    {   //cleanup memory if failed to open tempfile
        if (!filename.empty() && filesystem::exists(filename))
            filesystem::remove(filename);  //delete file
        throw;  //rethrow exception to calling function
    }
    if (unlinkFile)   //fstream object
    {
        filesystem::remove(filename);
        filename.clear();
    }
    
}

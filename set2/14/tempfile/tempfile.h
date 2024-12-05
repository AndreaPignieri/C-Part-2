#ifndef INCLUDED_TEMPFILE_
#define INCLUDED_TEMPFILE_
#include <filesystem>
#include <fstream>
#include <stdexcept>
#include <string>
#include <iostream>

class TempFile
{
    std::filesystem::path filename;  //stores path
    std::fstream file;               //file object
    public:
    //Constructor saves file in temp directory
    //names file "XXXXXXXX.tmp"
    //allows read and right
        TempFile(bool unlinkFile = false,
                 std::filesystem::path const &directory
                 = std::filesystem::temp_directory_path(),
                 std::filesystem::path const &filename_pattern
                 = "XXXXXXXX.tmp",
                 std::filesystem::perms permissions
                 = std::filesystem::perms::owner_read
                 | std::filesystem::perms::owner_write);
        ~TempFile();
        //gets name
        std::filesystem::path const &name() const
        {
            return filename;
        }
        //accesses stream
        std::fstream &stream()
        {
            return file;
        }
};


#endif

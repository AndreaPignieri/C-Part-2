#include "BiStream.ih"
#include "BiStream.hh"

BiStream::BiStream(std::ofstream& file1, std::ofstream& file2)
    : buffer(file1, file2), output(&buffer)
{

}
BiStream& BiStream::operator<<(const char* data)
{
    //Use ostream with our custom buffer to write two multiple files
    output << data;
    return *this;
}

BiStream& BiStream::operator<<(std::ostream& (*manip)(std::ostream&))
{
    //Use ostream with our custom buffer to write two multiple files
    output << manip;
    return *this;
}
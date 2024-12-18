#include "BiStream.ih"
#include "BiStream.hh"

BiStream::BiStream(std::ofstream& file1, std::ofstream& file2)
    : buffer(file1, file2), output(&buffer)
{

}
BiStream& BiStream::operator<<(const char* data)
{
    output << data;
    return *this;
}

BiStream& BiStream::operator<<(std::ostream& (*manip)(std::ostream&))
{
    output << manip;
    return *this;
}
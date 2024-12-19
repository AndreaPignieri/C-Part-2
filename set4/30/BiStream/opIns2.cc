#include "BiStream.ih"

inline BiStream& BiStream::operator<<(std::ostream& (*manip)(std::ostream&))
{
    //Use ostream with our custom buffer to write two multiple files
    output << manip;
    return *this;
}
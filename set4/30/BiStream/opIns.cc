#include "BiStream.ih"

inline BiStream& BiStream::operator<<(const char* data)
{
    //Use ostream with our custom buffer to write two multiple files
    output << data;
    return *this;
}
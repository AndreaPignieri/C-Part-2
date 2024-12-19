#include "BiStream.ih"

BiStream::BiStream(std::ofstream& file1, std::ofstream& file2)
    : buffer(file1, file2), output(&buffer)
{

}
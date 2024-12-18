#ifndef BISTREAM_H
#define BISTREAM_H

#include "../BiStreamBuffer/BiStreamBuffer.ih"

class BiStream
{
    private:
        BiStreamBuffer buffer;
        std::ostream output;
    public:
        BiStream(std::ofstream& file1, std::ofstream& file2);

        BiStream& operator<<(std::ostream& (*manip)(std::ostream&));
        BiStream& operator<<(const char* data);
        
};

#endif


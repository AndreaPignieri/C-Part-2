#ifndef BISTREAMBUFFER_H
#define BISTREAMBUFFER_H

#include <streambuf>

class BiStreamBuffer : public std::streambuf
{
    private:
        std::streambuf* buf1;
        std::streambuf* buf2;
    public:
        BiStreamBuffer(std::ostream& file1, std::ostream& file2);

        int sync() override;
        int overflow(int c) override;
};

#endif
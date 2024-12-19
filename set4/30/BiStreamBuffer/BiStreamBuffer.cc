#include "BiStreamBuffer.ih"

BiStreamBuffer::BiStreamBuffer(std::ostream& out1, std::ostream& out2) 
        : buf1(out1.rdbuf()), buf2(out2.rdbuf())
{

}
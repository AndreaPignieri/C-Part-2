#include "BiStreamBuffer.ih"

BiStreamBuffer::BiStreamBuffer(std::ostream& out1, std::ostream& out2) 
        : buf1(out1.rdbuf()), buf2(out2.rdbuf())
{

}

int BiStreamBuffer::sync()
{
    // Use streambufs pubsync methods to flush
    if (buf1->pubsync() == 0 && buf2->pubsync() == 0)
    {
        return 0;
    }
    return -1;
}

int BiStreamBuffer::overflow(int c)
{
    // First sync the buffer
    sync();
    // If not EOF, write the character to both streams
    if (c != EOF) {
        // Write to first stream
        int result1 = buf1->sputc(static_cast<char>(c));
        // Write to second stream
        int result2 = buf2->sputc(static_cast<char>(c));
        // Return EOF if one of the writes fails
        if (result1 == EOF || result2 == EOF)
        {
            return EOF;
        }
    }
    return c;
}
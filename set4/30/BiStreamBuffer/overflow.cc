#include "BiStreamBuffer.ih"

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
#include "BiStreamBuffer.ih"

int BiStreamBuffer::sync()
{
    // Use streambufs pubsync methods to flush
    if (buf1->pubsync() == 0 && buf2->pubsync() == 0)
    {
        return 0;
    }
    return -1;
}
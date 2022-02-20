#ifndef PrivateQueue_H
#define PrivateQueue_H
#include "../Queue/queue.h"

class PrivateQueue : private Queue
{
public:
    PrivateQueue();
    PrivateQueue(queue_data dat) : Queue(dat) {}

    int wrappedGetSize();

    void wrappedPush(int value);
    int  wrappedPop();
    int  wrappedAt(const int index);

    void wrappedPrint();

    int calc();

    queue_data wrappedCopy();
    static queue_data concat(PrivateQueue* a, PrivateQueue* b);
};

#endif // PrivateQueue_H

#ifndef ProtectedQueue_H
#define ProtectedQueue_H

#include "../Queue/queue.h"

class ProtectedQueue : protected Queue
{
public:
    ProtectedQueue();
    ProtectedQueue(queue_data dat) : Queue(dat) {}
    int wrappedGetSize();

    void wrappedPush(int value);
    int  wrappedPop();
    int  wrappedAt(const int index);

    void wrappedPrint();

    static queue_data concat(ProtectedQueue* a, ProtectedQueue* b);
    int calc();
};

#endif // ProtectedQueue_H

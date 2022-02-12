#ifndef PublicQueue_H
#define PublicQueue_H
#include "../Queue/queue.h"

class PublicQueue : public Queue
{
public:
    PublicQueue();
    PublicQueue(queue_data dat) : Queue(dat) {}
    int calc();
};

#endif // PublicQueue_H

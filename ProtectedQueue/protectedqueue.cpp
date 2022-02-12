#include "protectedqueue.h"

ProtectedQueue::ProtectedQueue()
{

}

int ProtectedQueue::wrappedGetSize()
{
    return this->getSize();
}

void ProtectedQueue::wrappedPush(int value)
{
    this->push(value);
}

int ProtectedQueue::wrappedPop()
{
    return this->pop();
}

int ProtectedQueue::wrappedAt(const int index)
{
    return this->at(index);
}

void ProtectedQueue::wrappedPrint()
{
    this->print();
}

int ProtectedQueue::calc(){
    int ret = 0;
    for(int i = 0; i < this->getSize(); i++)
        if(!(this->getQueueHead()[i] % 2))ret ++;
    return ret;
}

queue_data ProtectedQueue::concat(ProtectedQueue *a, ProtectedQueue *b){
    queue_data ret;
    ret.size = a->getSize() + b->getSize();
    ret.new_allocated_head = (int*)std::calloc(ret.size,sizeof(int));

    std::memcpy(ret.new_allocated_head               , a->getQueueHead(), a->getSize());
    std::memcpy(ret.new_allocated_head + a->getSize(), b->getQueueHead(), b->getSize());

    return ret;
}
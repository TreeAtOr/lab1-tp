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

queue_data ProtectedQueue::wrappedCopy(){
    return this->copy();
}

queue_data ProtectedQueue::concat(ProtectedQueue *a, ProtectedQueue *b){
    queue_data ret;
    ret.size = a->getSize() + b->getSize();
    ret.new_allocated_head = new int[ret.size];

    std::copy(a->getQueueHead(), a->getQueueHead() + a->getSize(), ret.new_allocated_head);
    std::copy(b->getQueueHead(), b->getQueueHead() + b->getSize(), ret.new_allocated_head + a->getSize());

    return ret;
}
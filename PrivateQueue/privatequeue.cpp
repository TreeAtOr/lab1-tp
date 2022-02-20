#include "privatequeue.h"

PrivateQueue::PrivateQueue()
{

}

int PrivateQueue::wrappedGetSize()
{
    return this->getSize();
}

void PrivateQueue::wrappedPush(int value)
{
    this->push(value);
}

int PrivateQueue::wrappedPop()
{
    return this->pop();
}

int PrivateQueue::wrappedAt(const int index)
{
    return this->at(index);
}

void PrivateQueue::wrappedPrint()
{
    this->print();
}

int PrivateQueue::calc(){
    int ret = 0;
    for(int i = 0; i < this->getSize(); i++)
        if(!(this->getQueueHead()[i] % 2))ret ++;
    return ret;
}

queue_data PrivateQueue::wrappedCopy(){
    return this->copy();
}

queue_data PrivateQueue::concat(PrivateQueue *a, PrivateQueue *b){
    queue_data ret;
    ret.size = a->getSize() + b->getSize();
    ret.new_allocated_head = (int*)std::calloc(ret.size,sizeof(int));

    std::memcpy(ret.new_allocated_head               , a->getQueueHead(), a->getSize());
    std::memcpy(ret.new_allocated_head + a->getSize(), b->getQueueHead(), b->getSize());

    return ret;
}
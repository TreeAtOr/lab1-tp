#include "queue.h"
#include <iostream>
#include <string>

int *Queue::getQueueHead()
{
    return this->queue_head;
}

int Queue::incrementSize()
{
    return ++this->queue_size;
}

int Queue::decrementSize()
{
    return --this->queue_size;
}

void Queue::setQueueHead(int * head)
{
    this->queue_head = head;
}

void Queue::setSize(int size)
{
    this->queue_size = size;
}

Queue::Queue()
{
    this->queue_size = 0;
}

Queue::Queue(queue_data dat)
{
    this->queue_head = dat.new_allocated_head;
    this->queue_size = dat.size;
}

Queue::~Queue()
{
    free(this->getQueueHead());
}

int Queue::getSize()
{
    return this->queue_size;
}

void Queue::push(int value){
    if(!this->getSize()) {
        this->setQueueHead((int*)std::calloc(1,sizeof(int)));
        this->incrementSize();
    } else {
        this->setQueueHead((int*)std::realloc(this->getQueueHead(),this->incrementSize() * sizeof(int)));
    }
    this->queue_head[this->getSize() - 1] = value;
}
int Queue::pop(){
    if(!queue_size) {
        throw std::string("Empth queue");
    }
    int tmp = this->getQueueHead()[0];
    std::memcpy(this->getQueueHead(),
                this->getQueueHead()+1,
                this->decrementSize() * sizeof(int));
    this->setQueueHead((int*)std::realloc(this->getQueueHead(),this->getSize() * sizeof(int)));
    return tmp;
}
int Queue::at(const int index){
    return this->getQueueHead()[index % this->getSize()];
}
queue_data Queue::copy(){
    queue_data ret;
    ret.size = this->getSize();
    ret.new_allocated_head = (int*)std::calloc(ret.size,sizeof(int));
    std::memcpy(ret.new_allocated_head,this->getQueueHead(),ret.size);
    return ret;
}

queue_data Queue::concat(Queue *a, Queue *b){
    queue_data ret;
    ret.size = a->getSize() + b->getSize();
    ret.new_allocated_head = (int*)std::calloc(ret.size,sizeof(int));

    std::memcpy(ret.new_allocated_head               , a->getQueueHead(), a->getSize());
    std::memcpy(ret.new_allocated_head + a->getSize(), b->getQueueHead(), b->getSize());

    return ret;
}

void Queue::print(){
    for(int i = 0; i < this->getSize(); i++){
        std::cout << this->getQueueHead()[i] << std::endl;
    }
}

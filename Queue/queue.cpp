#include "queue.h"
#include <iostream>
#include <string>
#include <algorithm>

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

void const Queue::push(int value){
    if(!this->getSize()) {
        this->setQueueHead(new int[1]);
        this->incrementSize();
    } else {
        const int* old = this->queue_head;
        int* new_allocated_head = new int[this->incrementSize()];
        std::copy(old, old + this->queue_size, new_allocated_head);
        delete[] old;
        this->setQueueHead(new_allocated_head);
    }
    this->queue_head[this->getSize() - 1] = value;
}
int Queue::pop(){
    if(!queue_size) {
        throw std::string("Empth queue");
    }
    int tmp = this->getQueueHead()[0];

    if(this->queue_size == 1){
        delete[] this->queue_head;
        this->decrementSize();
        return tmp;
    }

    const int* old = this->queue_head;
    int* new_allocated_head = new int[this->decrementSize()];
    std::copy(old + 1, old + this->queue_size + 1, new_allocated_head);
    delete[] old;
    this->setQueueHead(new_allocated_head);

    return tmp;
}
int Queue::at(const int index){
    return this->getQueueHead()[index % this->getSize()];
}
queue_data Queue::copy(){
    queue_data ret;
    const int* old_head = this->getQueueHead();
    ret.size = this->getSize();
    ret.new_allocated_head = new int[ret.size];
    std::copy(old_head, old_head + this->queue_size, ret.new_allocated_head);

    return ret;
}

queue_data Queue::concat(Queue *a, Queue *b){
    queue_data ret;
    ret.size = a->getSize() + b->getSize();
    ret.new_allocated_head = new int[ret.size];

    std::copy(a->getQueueHead(), a->getQueueHead() + a->getSize(), ret.new_allocated_head);
    std::copy(b->getQueueHead(), b->getQueueHead() + b->getSize(), ret.new_allocated_head + a->getSize());

    return ret;
}

void Queue::print(){
    for(int i = 0; i < this->getSize(); i++){
        std::cout << this->getQueueHead()[i] << std::endl;
    }
    std::cout << std::endl;
}

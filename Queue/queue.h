#ifndef QUEUE_H
#define QUEUE_H
#include <memory>
#include <iostream>
#include <cstdlib>
#include <cstring>
struct queue_data {int* new_allocated_head; int size; };

class Queue
{
private:
    int* queue_head;
    int queue_size;
protected:
    int* getQueueHead();

    int incrementSize();
    int decrementSize();

    void setQueueHead(int*);
    void setSize(int);
public:
    Queue();
    Queue(queue_data);
    ~Queue();

    int getSize();

    void push(int value);
    int pop();
    int at(const int index);

    queue_data copy();
    static queue_data concat(Queue* a, Queue* b);

    void print();

};

#endif // QUEUE_H

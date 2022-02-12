#include "publicqueue.h"
PublicQueue::PublicQueue(){}
int PublicQueue::calc(){
    int ret = 0;
    for(int i = 0; i < this->getSize(); i++)
        if(!(this->getQueueHead()[i] % 2))ret ++;
    return ret;
}

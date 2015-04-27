#include "memory.h"
using namespace std;

memory::memory(int send,int ready,int trans,int bus,watcher* watch)
{
        Watcher = watch;
        sendTime = send;
        readyTime = ready;
        transferTime = trans;
        busWidth = bus;
}

ull memory::transferData(int size)
{
//debug
//int temp = sendTime+readyTime+transferTime*(size/busWidth);
//printf("Add memory to L2 transfer time (+ %d)\n",temp);
//debug
        return (sendTime+readyTime+transferTime*(size/busWidth));
}

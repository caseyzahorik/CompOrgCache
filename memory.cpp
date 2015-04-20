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
        return (sendTime+readyTime+transferTime*(size/busWidth));
}

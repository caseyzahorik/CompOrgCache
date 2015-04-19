#include "memory.h"

memory::memory(int send,int ready,int trans,int bus,watcher* watch)
{
        Watcher = watch;
        sendTime = send;
        readyTime = ready;
        transferTime = trans;
        busWidth = bus;
}

int memory::transferData(int size)
{
        return (sendTime+readyTime+transferTime*(size/busWidth));
}

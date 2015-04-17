#include "memory.h"

//memory::memory()
//{
//        Watcher = nullptr;
//        sendTime = 10;
//        readyTime = 30;
//        transferTime = 15;
//        busWidth = 8;
//}
//
//memory::memory(watcher* watch)
//{
//        Watcher = watch;
//        sendTime = 10;
//        readyTime = 30;
//        transferTime = 15;
//        busWidth = 8;
//}
//also commented out due to perceived uselessness

memory::memory(int send,int ready,int trans,int bus,watcher* watch)
{
        Watcher = watch;
        sendTime = send;
        readyTime = ready;
        transferTime = trans;
        busWidth = bus;
}

int memory::setWatcher(watcher* watch)
{
        Watcher = watch;
        return 0;
}

int memory::setSendTime(int send);
{
        sendTime = send;
        return 0;
}

int memory::setReadyTime(int ready);
{
        readyTime = ready;
        return 0;
}

int memory::setTransferTime(int trans);
{
        transferTime = trans;
        return 0;
}

int memory::setBusWidth(int bus);
{
        busWidth = bus;
        return 0;
}

int memory::BusWidth()
{
        return busWidth;
}

int memory::transferData(int size)
{
        return (sendTime+readyTime+transferTime*(size/busWidth));
}

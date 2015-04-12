#ifndef __memory
#define __memory

#include "watcher.h"

class memory
{
private:
        watcher* Watcher;

        int sendTime;//time to send address to memory
        int readyTime;//time to ready the memory to transfer
        int transferTime;//time for 1 bus width of data
        int busWidth;//width of the memory interface in bytes
public:
        memory();
        memory(watcher* watch);
        memory(int send,int ready,int trans,int bus,watcher* watch);
        int setWatcher(watcher* watch);
        int setSendTime(int send);
        int setReadyTime(int ready);
        int setTransferTime(int trans);
        int setBusWidth(int bus);
        int BusWidth();//potentially not necessary
        //debate the worth of the l2cache chunking it's own access
        //requests, or just letting main memory handle it in
        //one calculation
        int transferData(int size);
}

#endif

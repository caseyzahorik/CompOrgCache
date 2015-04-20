#ifndef __memory
#define __memory

#include "watcher.h"
using namespace std;

class memory
{
public:
        watcher* Watcher;

        int sendTime;
        //time to send address to memory
        int readyTime;
        //time to ready the memory to transfer
        int transferTime;
        //time for 1 bus width of data
        int busWidth;
        //width of the memory bus in bytes

        memory(int send,int ready,int trans,int bus,watcher* watch);
        ull transferData(int size);
};

#endif

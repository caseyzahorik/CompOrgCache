#ifndef __l2cache
#define __l2cache

#include "way.h"
#include "memory.h"
#include "watcher.h"
#include "types.h"
#include <cmath>

class l2cache
{
public:
        watcher* Watcher;

        int blockSize;
        int cacheSize;
        int associativity;
        int hitTime;
        int missTime;
        int transferTime;
        int busWidth;
        way** set;
        int sets;
        ull blockSizeMask;
        ull indexMask;
        ull indexShift;
        memory* mainMemory;

        l2cache(int block,int cache, int assoc, int hit, int miss, int trans, int bus, memory* Memory,watcher* watch);
        int read(ull address,int block);
        int write(ull address,int block);
        int flushAll();
};

#endif

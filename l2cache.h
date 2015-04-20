#ifndef __l2cache
#define __l2cache

#include "way.h"
#include "memory.h"
#include "watcher.h"
#include "types.h"
#include <cmath>
using namespace std;

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

        ull hitcount;
        ull misscount;
        ull requests;
        ull kickouts;
        ull dirty;
        ull transfer;
        ull flush;

        l2cache(int block,int cache,int assoc, int hit,int miss,int trans,int bus,memory* Memory,watcher* watch);
        ~l2cache();
        ull read(ull address,int block);
        ull write(ull address,int block);
        ull flushAll();
};

#endif

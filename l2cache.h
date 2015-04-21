#ifndef __L2CACHE
#define __L2CACHE

#include <cmath>
#include "types.h"
#include "way.h"
#include "memory.h"
#include "watcher.h"
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

        l2cache(int,int,int,int,int,int,int,memory*,watcher*);
        ~l2cache();
        ull read(ull address,int block);
        ull write(ull address,int block);
        ull flushAll();
};

#endif

#ifndef __l1cache
#define __l1cache

#include "l2cache.h"
#include "watcher.h"
#include "way.h"
#include "types.h"
#include <cmath>
#include <climits>

class l1cache
{
private:
public:
        watcher* Watcher;
        int blockSize;
        int cacheSize;
        int associativity;
        int hitTime;
        int missTime;
        way** set;
        int sets;// number of sets
        ull blockSizeMask;
        ull indexMask;
        ull indexShift;
        l2cache* L2;

        l1cache(int block,int cache,int assoc,int hit,int miss,l2cache* l2,watcher* watch);
        ~l1cache();
        ull read(ull address);
        ull write(ull address);
        ull flushAll();
};

#endif

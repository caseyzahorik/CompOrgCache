#ifndef __l1cache
#define __l1cache

#include "l2cache.h"
#include "watcher.h"
#include "way.h"
#include "types.h"
#include <cmath>

class l1cache
{
private:
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
public:
        l1cache(int block,int cache,int assoc,int hit,int miss,l2cache* l2);
        int BlockSize();
        int CacheSize();
        int Associativity();
        int HitTime();
        int MissTime();
        int read(ull address);
        int write(ull address);
        int flushAll();
};

#endif

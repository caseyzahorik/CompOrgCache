#ifndef __l1cache
#define __l1cache

#include <cmath>
#include "types.h"
#include "way.h"
#include "watcher.h"
#include "l2cache.h"
using namespace std;

class l1cache
{
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

        ull hitcount;
        ull misscount;
        ull requests;
        ull kickouts;
        ull dirty;
        ull transfer;
        ull flush;

        l1cache(int,int,int,int,int,l2cache*,watcher*);
        ~l1cache();
        ull read(ull address);
        ull write(ull address);
        ull flushAll();
};

#endif

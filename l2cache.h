#ifndef __l2cache
#define __l2cache

#include "way.h"
#include "memory.h"
#include "watcher.h"
#include "types.h"

class l2cache
{
private:
        watcher* Watcher;

        //everything must be written without l1 pointers.
        //pointers flow down the chain, function returns flow up
        int blockSize;//block size in bytes //power of two
        int cacheSize;//cache size in bytes //power of two
        int associativity;//associativity of the cache (num ways)
                //power of two
        int hitTime;//time to return item that's a hit
        int missTime;//time to determine a miss and make the request
        int transferTime;//time to transfer 1 bus width
        int busWidth;//width of bus in bytes, //power of two
        way** set;// the array of the sets
        int sets;// number of sets
        memory* mainMemory;//pointer to main memory
public:
        l2cache();
        l2cache(memory* Memory);
        l2cache(int block,int cache, int assoc, int hit, int miss, int trans, int bus, memory* Memory);
        int BlockSize();
        int CacheSize();
        int Associativity();
        int HitTime();
        int MissTime();
        int TransferTime();
        int BusWidth();
        int read(ull address,int block);
        int write(ull address,int block);
        int flushAll();
};

#endif

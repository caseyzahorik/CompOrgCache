#ifndef __watcher
#define __watcher

#include "types.h"

class watcher
{
public:
        //dcache info
        int DcacheSize;
        int DcacheWays;
        int DcacheBlock;
        //icache info
        int IcacheSize;
        int IcacheWays;
        int IcacheBlock;
        //l2cache info
        int L2Size;
        int L2Ways;
        int L2Block;
        //main mem info
        int ReadyTime;
        int ChunkSize;
        int ChunkTime;
        //basic stats
        ull ExecuteTime;
        ull FlushTime;
        ull TotalRef;
        ull InstRef
        ull DataRef
        //reference types
        //cycles per type
        //average cycles/type
        //icache specifics
        //dcache specifics
        //l2 specifics
        //cost data
        //etc

        watcher();
};

#endif

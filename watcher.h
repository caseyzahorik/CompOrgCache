#ifndef __watcher
#define __watcher

#include "types.h"
#include <iostream>

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
        ull InstRef;
        ull DataRef;
        //reference types
        ull ReadCount;
        ull WriteCount;
        ull InstCount;
        //TotalCount same as TotalRef
        //cycles per type
        ull ReadCycles;
        ull WriteCycles;
        ull InstCycles;
        //TotalCycles same as ExecuteTime
        //average cycles/type
        float AvgRead;
        float AvgWrite;
        float AvgInst;
        ull IdealAlign;
        float IdealCPI;
        ull IdealMisAlign;
        float MisCPI;
        //icache specifics
        ull iHitCount;
        ull iMissCount;
        ull iRequests;
        ull iKickouts;
        ull iDirtyKickout;
        ull iTransKickout;
        ull iFlushKickout;
        //dcache specifics
        ull dHitCount;
        ull dMissCount;
        ull dRequests;
        ull dKickouts;
        ull dDirtyKickout;
        ull dTransKickout;
        ull dFlushKickout;
        //l2 specifics
        ull LHitCount;
        ull LMissCount;
        ull LRequests;
        ull LKickouts;
        ull LDirtyKickout;
        ull LTransKickout;
        ull LFlushKickout;
        //cost data
        //just calculate at printing
        //etc
        ull Flushes;
        ull Invalidates;

        watcher();
        int print();
};

#endif

#include "watcher.h"

watcher::watcher()
{
        DcacheSize = 0;
        DcacheWays = 0;
        DcacheBlock = 0;
        IcacheWays = 0;
        IcacheBlock = 0;
        L2Size = 0;
        L2Ways = 0;
        L2Block = 0;
        ReadyTime = 0;
        ChunkSize = 0;
        ChunkTime = 0;
        ExecuteTime = 0;
        FlushTime = 0;
        TotalRef = 0;
        InstRe = 0;
        DataRe = 0;
        ReadCount = 0;
        WriteCount = 0;
        InstCound = 0;
        ReadCycles = 0;
        WriteCycles = 0;
        InstCycles = 0;
        AvgRead = 0;
        AvgWrite = 0;
        AvgInst = 0;
        IdealAlign = 0;
        IdealCPI = 0;
        IdealMisAlign = 0;
        MisCPI = 0;
        iHitCount = 0;
        iMissCount = 0;
        iRequests = 0;
        iKickouts = 0;
        iDirtyKickout = 0;
        iTransKickout = 0;
        iFlushKickout = 0;
        dHitCount = 0;
        dMissCount = 0;
        dRequests = 0;
        dKickouts = 0;
        dDirtyKickout = 0;
        dTransKickout = 0;
        dFlushKickout = 0;
        LHitCount = 0;
        LMissCount = 0;
        LRequests = 0;
        LKickouts = 0;
        LDirtyKickout = 0;
        LTransKickout = 0;
        LFlushKickout = 0;
        Flushes = 0;
        Invalidates = 0;
}

int watcher::print()
{
}

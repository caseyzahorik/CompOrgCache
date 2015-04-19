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
        InstRef = 0;
        DataRef = 0;
        ReadCount = 0;
        WriteCount = 0;
        InstCount = 0;
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
        //Memory System Info
        cout<<"Memory system:"<<endl;
        cout<<"\tDcache size = "<<DcacheSize;
        cout<<" : ways = "<<DcacheWays<<" : ";
        cout<<"block size = "<<DcacheBlock<<endl;
        cout<<"\tIcache size = "<<IcacheSize;
        cout<<" : ways = "<<IcacheWays<<" : ";
        cout<<"block size = "<<IcacheBlock<<endl;
        cout<<"\tL2-cache size = "<<L2Size;
        cout<<" : ways = "<<L2Ways<<" : ";
        cout<<"block size = "<<L2Block<<endl;
        cout<<"\tMemory ready time = "<<ReadyTime;
        cout<<" : chunksize = "<<ChunkSize<<" : ";
        cout<<"chunktime = "<<ChunkTime<<endl;
        cout<<endl;
        //Basic Statistics
        cout<<"Execute time = "<<ExecuteTime<<"; ";
        cout<<"Total Refs = "<<TotalRef<<endl;
        cout<<"Flush time = "<<FlushTime<<endl;
        cout<<"Inst Refs = "<<InstRef<<"; ";
        cout<<"Data Refs = "<<DataRef<<endl;
        cout<<endl;
        //reference types
        cout<<"Number of reference types: [Percentage]"<<endl;
        cout<<"\tReads = "<<ReadCount;
        float percentage = (float)100*float(ReadCount)/float(TotalRef)
        cout<<"\t["<<percentage<<"]"<<endl;
        cout<<"\tWrites = "<<WriteCount;
        percentage = (float)100*float(WriteCount)/float(TotalRef)
        cout<<"\t["<<percentage<<"]"<<endl;
        cout<<"\tInst. = "<<InstCount;
        percentage = (float)100*float(InstCount)/float(TotalRef)
        cout<<"\t["<<percentage<<"]"<<endl;
        cout<<"\tTotal = "<<TotalRef<<endl;
        //cycles per type
        cout<<"Total cycles for activities: [Percentage]"<<endl;
        cout<<"\tReads = "<<ReadCycles;
        percentage = (float)100*float(ReadCycles)/float(ExecuteTime)
        cout<<"\t["<<percentage<<"]"<<endl;
        cout<<"\tWrites = "<<WriteCycles;
        percentage = (float)100*float(WriteCycles)/float(ExecuteTime)
        cout<<"\t["<<percentage<<"]"<<endl;
        cout<<"\tInst. = "<<InstCycles;
        percentage = (float)100*float(InstCycles)/float(ExecuteTime)
        cout<<"\t["<<percentage<<"]"<<endl;
        cout<<"\tTotal = "<<ExecuteTime<<endl;

        return 0;
}

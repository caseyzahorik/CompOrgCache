#include "watcher.h"
using namespace std;

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
        cout<<fixed;
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
        float percentage=(float)100*float(ReadCount)/float(TotalRef);
        cout<<"\t["<<percentage<<"]"<<endl;
        cout<<"\tWrites = "<<WriteCount;
        percentage = (float)100*float(WriteCount)/float(TotalRef);
        cout<<"\t["<<percentage<<"]"<<endl;
        cout<<"\tInst. = "<<InstCount;
        percentage = (float)100*float(InstCount)/float(TotalRef);
        cout<<"\t["<<percentage<<"]"<<endl;
        cout<<"\tTotal = "<<TotalRef<<endl;
        cout<<endl;
        //cycles per type
        cout<<"Total cycles for activities: [Percentage]"<<endl;
        cout<<"\tReads = "<<ReadCycles;
        percentage = (float)100*float(ReadCycles)/float(ExecuteTime);
        cout<<"\t["<<percentage<<"]"<<endl;
        cout<<"\tWrites = "<<WriteCycles;
        percentage=(float)100*float(WriteCycles)/float(ExecuteTime);
        cout<<"\t["<<percentage<<"]"<<endl;
        cout<<"\tInst. = "<<InstCycles;
        percentage = (float)100*float(InstCycles)/float(ExecuteTime);
        cout<<"\t["<<percentage<<"]"<<endl;
        cout<<"\tTotal = "<<ExecuteTime<<endl;
        cout<<endl;
        //average cycles per activity
        AvgRead = float(ReadCycles)/float(ReadCount);
        AvgWrite = float(WriteCycles)/float(WriteCount);
        AvgInst = float(InstCycles)/float(InstCount);
        cout<<"Average cycles per activity:";
        cout<<endl<<"\tRead = ";
        cout<<setprecision(1)<<AvgRead<<"; ";
        cout<<endl<<"\tWrite = ";
        cout<<setprecision(1)<<AvgWrite<<"; ";
        cout<<endl<<"\tInst = ";
        cout<<setprecision(1)<<AvgInst<<"; ";
        cout<<endl;
        cout<<"Ideal: Exec. Time = ";
        IdealAlign = TotalRef+InstRef;
        cout<<IdealAlign<<"; CPI = ";
        cout<<0<<endl;//TODO
        cout<<"Ideal mis-aligned: Exec. Time = ";
        IdealMisAlign = InstRef+iRequests+dRequests;
        cout<<IdealMisAlign<<"; CPI = ";
        cout<<0<<endl;//TODO
        cout<<endl;
        //l1i memory
        cout<<"Memory Level: L1i"<<endl;
        cout<<"\tHit Count = "<<iHitCount;
        cout<<" Miss Count = "<<iMissCount<<endl;
        cout<<"\tTotal Requests = "<<iRequests<<endl;
        percentage = float(iHitCount)/float(iRequests);
        cout<<"\tHit Rate = ";
        cout<<setprecision(1)<<percentage<<"%";
        percentage = float(iMissCount)/float(iRequests);
        cout<<" Miss Rate = ";
        cout<<setprecision(1)<<percentage<<"%"<<endl;
        cout<<"\tKickouts = "<<iKickout<<"; ";
        cout<<"Dirty Kickouts = "<<iDirtyKickout<<"; ";
        cout<<"Transfers= "<<iTransKickout<<"; "<<endl;
        cout<<"Flush Kickouts = "<<iFlushKickout<<endl;
        cout<<endl;
        //l1d memory
        cout<<"Memory Level: L1d"<<endl;
        cout<<"\tHit Count = "<<dHitCount;
        cout<<" Miss Count = "<<dMissCount<<endl;
        cout<<"\tTotal Requests = "<<dRequests<<endl;
        percentage = float(dHitCount)/float(dRequests);
        cout<<"\tHit Rate = ";
        cout<<setprecision(1)<<percentage<<"%";
        percentage = float(dMissCount)/float(dRequests);
        cout<<" Miss Rate = ";
        cout<<setprecision(1)<<percentage<<"%"<<endl;
        cout<<"\tKickouts = "<<dKickout<<"; ";
        cout<<"Dirty Kickouts = "<<dDirtyKickout<<"; ";
        cout<<"Transfers= "<<dTransKickout<<"; "<<endl;
        cout<<"Flush Kickouts = "<<dFlushKickout<<endl;
        cout<<endl;
        //l2 memory
        cout<<"Memory Level: L2"<<endl;
        cout<<"\tHit Count = "<<LHitCount;
        cout<<" Miss Count = "<<LMissCount<<endl;
        cout<<"\tTotal Requests = "<<LRequests<<endl;
        percentage = float(LHitCount)/float(LRequests);
        cout<<"\tHit Rate = ";
        cout<<setprecision(1)<<percentage<<"%";
        percentage = float(LMissCount)/float(LRequests);
        cout<<" Miss Rate = ";
        cout<<setprecision(1)<<percentage<<"%"<<endl;
        cout<<"\tKickouts = "<<LKickout<<"; ";
        cout<<"Dirty Kickouts = "<<LDirtyKickout<<"; ";
        cout<<"Transfers= "<<LTransKickout<<"; "<<endl;
        cout<<"Flush Kickouts = "<<LFlushKickout<<endl;
        cout<<endl;
        //l1cost
        dcost = 100*(log2(DcacheWays)+1);
        int temp = DcacheSize/4096;
        dcost*=temp
        icost = 100*(log2(IcacheWays)+1);
        temp = IcacheSize/4096;
        icost*=temp
        cout<<"L1 cache cost (ICache $";
        cout<<icost<<") + (Dcache $";
        cout<<dcost<<") = $"<<(icost+dcost);
        cout<<endl;
        //l2cost
        temp = 50*(log2(LcacheWays));
        Lcost= LcacheSize/65536+1;
        Lcost+=temp
        cout<<"L2 cache cost = $"
        cout<<Lcost<<"; ";
        //main mem cost
        cout<<"Memory cost = $75; ";
        //total cost
        cout<<"Total cost = $";
        temp = 75+Lcost+icost+dcost;
        cout<<temp<<endl;
        //flush and invalidate
        cout<<"Flushes = "<<Flushes<<" : ";
        cout<<"Invalidates = "<<Invalidates<<endl;


        return 0;
}

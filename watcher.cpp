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
        dcost=0;
        icost=0;
        Lcost=0;
        Flushes = 0;
        Invalidates = 0;
}

int watcher::print()
{
        //Memory System Info
        cout<<fixed;
        cout<<setprecision(1);
        cout<<"Memory system:"<<endl;
        cout<<"  Dcache size = "<<DcacheSize;
        cout<<" : ways = "<<DcacheWays<<" : ";
        cout<<"block size = "<<DcacheBlock<<endl;
        cout<<"  Icache size = "<<IcacheSize;
        cout<<" : ways = "<<IcacheWays<<" : ";
        cout<<"block size = "<<IcacheBlock<<endl;
        cout<<"  L2-cache size = "<<L2Size;
        cout<<" : ways = "<<L2Ways<<" : ";
        cout<<"block size = "<<L2Block<<endl;
        cout<<"  Memory ready time = "<<ReadyTime;
        cout<<" : chunksize = "<<ChunkSize<<" : ";
        cout<<"chunktime = "<<ChunkTime<<endl;
        cout<<endl;
        //Basic Statistics
        cout<<"Execute time = "<<ExecuteTime<<"; ";
        cout<<"Total refs = "<<TotalRef<<endl;
        cout<<"Flush time = "<<FlushTime<<endl;
        cout<<"Inst refs = "<<InstRef<<"; ";
        cout<<"Data refs = "<<DataRef<<endl;
        cout<<endl;
        //reference types
        cout<<"Number of reference types: [Percentage]"<<endl;
        cout<<"  Reads  = "<<ReadCount;
        float percentage=(float)100*float(ReadCount)/float(TotalRef);
        cout<<"  ["<<percentage<<"]"<<endl;
        cout<<"  Writes = "<<WriteCount;
        percentage = (float)100*float(WriteCount)/float(TotalRef);
        cout<<"  ["<<percentage<<"]"<<endl;
        cout<<"  Inst.  = "<<InstCount;
        percentage = (float)100*float(InstCount)/float(TotalRef);
        cout<<"  ["<<percentage<<"]"<<endl;
        cout<<"  Total  = "<<TotalRef<<endl;
        cout<<endl;
        //cycles per type
        cout<<"Total cycles for activities: [Percentage]"<<endl;
        cout<<"  Reads  = "<<ReadCycles;
        percentage = (float)100*float(ReadCycles)/float(ExecuteTime);
        cout<<"  ["<<percentage<<"]"<<endl;
        cout<<"  Writes = "<<WriteCycles;
        percentage=(float)100*float(WriteCycles)/float(ExecuteTime);
        cout<<"  ["<<percentage<<"]"<<endl;
        cout<<"  Inst.  = "<<InstCycles;
        percentage = (float)100*float(InstCycles)/float(ExecuteTime);
        cout<<"  ["<<percentage<<"]"<<endl;
        cout<<"  Total  = "<<ExecuteTime<<endl;
        cout<<endl;
        //average cycles per activity
        AvgRead = float(ReadCycles)/float(ReadCount);
        AvgWrite = float(WriteCycles)/float(WriteCount);
        AvgInst = float(InstCycles)/float(InstCount);
        cout<<"Average cycles per activity:";
        cout<<endl<<"  Read = "<<AvgRead<<"; ";
        cout<<"Write = "<<AvgWrite<<"; ";
        cout<<"Inst = "<<AvgInst<<"; ";
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
        cout<<"  Hit Count = "<<iHitCount;
        cout<<" Miss Count = "<<iMissCount<<endl;
        cout<<"  Total Requests = "<<iRequests<<endl;
        percentage = float(100)*float(iHitCount)/float(iRequests);
        cout<<"  Hit Rate = "<<percentage<<"%";
        percentage = float(100)*float(iMissCount)/float(iRequests);
        cout<<" Miss Rate = "<<percentage<<"%"<<endl;
        cout<<"  Kickouts = "<<iKickouts<<"; ";
        cout<<"Dirty kickouts = "<<iDirtyKickout<<"; ";
        cout<<"Transfers= "<<iTransKickout<<"; "<<endl;
        cout<<"Flush Kickouts = "<<iFlushKickout<<endl;
        cout<<endl;
        //l1d memory
        cout<<"Memory Level: L1d"<<endl;
        cout<<"  Hit Count = "<<dHitCount;
        cout<<" Miss Count = "<<dMissCount<<endl;
        cout<<"  Total Requests = "<<dRequests<<endl;
        percentage = float(100)*float(dHitCount)/float(dRequests);
        cout<<"  Hit Rate = "<<percentage<<"%";
        percentage = float(100)*float(dMissCount)/float(dRequests);
        cout<<" Miss Rate = "<<percentage<<"%"<<endl;
        cout<<"  Kickouts = "<<dKickouts<<"; ";
        cout<<"Dirty Kickouts = "<<dDirtyKickout<<"; ";
        cout<<"Transfers= "<<dTransKickout<<"; "<<endl;
        cout<<"Flush Kickouts = "<<dFlushKickout<<endl;
        cout<<endl;
        //l2 memory
        cout<<"Memory Level: L2"<<endl;
        cout<<"  Hit Count = "<<LHitCount;
        cout<<" Miss Count = "<<LMissCount<<endl;
        cout<<"  Total Requests = "<<LRequests<<endl;
        percentage = float(100)*float(LHitCount)/float(LRequests);
        cout<<"  Hit Rate = "<<percentage<<"%";
        percentage = float(100)*float(LMissCount)/float(LRequests);
        cout<<" Miss Rate = "<<percentage<<"%"<<endl;
        cout<<"  Kickouts = "<<LKickouts<<"; ";
        cout<<"Dirty Kickouts = "<<LDirtyKickout<<"; ";
        cout<<"Transfers= "<<LTransKickout<<"; "<<endl;
        cout<<"Flush Kickouts = "<<LFlushKickout<<endl;
        cout<<endl;
        //l1cost
        dcost = 100*(log2(DcacheWays)+1);
        int temp = DcacheSize/4096;
        dcost*=temp;
        icost = 100*(log2(IcacheWays)+1);
        temp = IcacheSize/4096;
        icost*=temp;
        cout<<"L1 cache cost (Icache $";
        cout<<icost<<") + (Dcache $";
        cout<<dcost<<") = $"<<(icost+dcost);
        cout<<endl;
        //l2cost
        temp = 50*(log2(L2Ways));
        Lcost= L2Size/65536+1;
        Lcost+=temp;
        cout<<"L2 cache cost = $";
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

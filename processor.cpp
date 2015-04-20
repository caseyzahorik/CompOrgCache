#include "processor.h"

using namespace std;

processor::processor(l1cache* icache,l1cache* dcache,watcher* thewatcher)
{
        Watcher = thewatcher;
        Icache = icache;
        Dcache = dcache;
}

ull processor::decode(char op, ull address, uint bytes)
{
        ull time = 0;
        switch(op)
        {
                case 'I':
                        time += fetchInstr(address, bytes);
                        Watcher->InstRef++;
                        Watcher->InstCount++;
                        Watcher->InstCycles+=time;
                        break;
                case 'R':
                        time += read(address, bytes);
                        Watcher->DataRef++;
                        Watcher->ReadCount++;
                        Watcher->ReadCycles+=time;
                        break;
                case 'W':
                        time += write(address, bytes);
                        Watcher->DataRef++;
                        Watcher->WriteCount++;
                        Watcher->WriteCycles+=time;
                        break;
                default:
                        break;
        }
        Watcher->TotalRef++;
        Watcher->ExecuteTime+=time;
        return time;
}

ull processor::fetchInstr(ull address, uint bytes)
{
        ull time = 0;
        ull mask = 0xfffffffffffc;
        ull base = address&mask;
        ull references = 1+(address-base+(ull)bytes-1)/4;
        for(uint i=0;i<references;i++)
        {
                time+=Icache->read(base+4*i);
        }
        return time;
}

ull processor::read(ull address,uint bytes)
{
        ull time = 0;
        ull mask = 0xfffffffffffc;
        ull base = address&mask;
        ull references = 1+(address-base+(ull)bytes-1)/4;
        for(uint i=0;i<references;i++)
        {
                time+=Dcache->read(base+4*i);
        }
        return time;
}

ull processor::write(ull address, uint bytes)
{
        ull time = 0;
        ull mask = 0xfffffffffffc;
        ull base = address&mask;
        ull references = 1+(address-base+(ull)bytes-1)/4;
        for(uint i=0;i<references;i++)
        {
                time+=Dcache->write(base+4*i);
        }
        return time;
}

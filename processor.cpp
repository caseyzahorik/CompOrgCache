#include "processor.h"

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
                        break;
                case 'R':
                        time += read(address, bytes);
                        break;
                case 'W':
                        time += write(address, bytes);
                        break;
                default:
                        break;
        }
        return time;// we are going to want to keep track of this in the watcher or just pass it back to the main like this
}

ull processor::fetchInstr(ull address, uint bytes)
{
        ull time = 0
        ull mask = 0xfffffffffffc;
        ull base = address&mask;
        ull references = 1+(address-base+(ull)bytes-1)/4
        for(int i=0;i<references;i++)
        {
                time+=Icache->read(base+4*i);
        }
        return time;
}

ull processor::read(ull address,uint bytes)
{
        ull time = 0
        ull mask = 0xfffffffffffc;
        ull base = address&mask;
        ull references = 1+(address-base+(ull)bytes-1)/4
        for(int i=0;i<references;i++)
        {
                time+=Dcache->read(base+4*i);
        }
        return time;
}

ull processor::write(ull address, uint bytes)
{
        ull time = 0
        ull mask = 0xfffffffffffc;
        ull base = address&mask;
        ull references = 1+(address-base+(ull)bytes-1)/4
        for(int i=0;i<references;i++)
        {
                time+=Dcache->write(base+4*i);
        }
        return time;
}

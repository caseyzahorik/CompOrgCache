#include "processor.h"

processor::processor(l1cache* icache,l1cache* dcache,watcher* thewatcher)
{
        Icache = icache;
        Dcache = dcache;
        Watcher = thewatcher;
}

processor::int decode(char op, unsigned long long int address, unsigned int bytes)
{
	unsigned long long int time = 0;
	if(op == 'I')
	{
		//instruction command
		time = fetchInstr(address, bytes);
	}
	else if(op == 'R')
	{
		//Data Read Command
		time = read(address, bytes);
	}
	else if(op == 'W')
	{
		//Data Write command
		time = write(address, bytes); 
	}
	return time; // we are going to want to keep track of this in the watcher or just pass it back to the main like this
}

processor::int fetchInstr(ull address, uint bytes)
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

processor::int read(ull address,uint bytes)
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

processor::int write(ull address, uint bytes)
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

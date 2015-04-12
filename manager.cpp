#include "manager.h"

manager::manager(watcher* thewatcher)
{
        Watcher = thewatcher;
        Disk = new memory(Watcher);
        L2 = new l2cache(Disk,Watcher);
        Icache = new l1cache(L2,Watcher);
        Dcache = new l1cache(L2,Watcher);
        CPU = new processor(Icache,Dcache,Watcher);
}

processor* manager::Processor()
{
        return CPU;
}

l1cache* manager::Icache()
{
        return Icache;
}

l1cache* manager::Dcache()
{
        return Dcache;
}

l2cache* manager::L2cache()
{
        return L2;
}

memory* manager::Memory()
{
        return Disk;
}

watcher* manager::Watcher()
{
        return Watcher;
}

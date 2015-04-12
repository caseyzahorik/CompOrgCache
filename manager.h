#ifndef __manager
#define __manager

#include "processor.h"
#include "l1cache.h"
#include "l2cache.h"
#include "way.h"
#include "memory.h"
#include "watcher.h"
#include "types.h"

class manager
{
private:
        processor* CPU;
        l1cache* Icache;
        l1cache* Dcache;
        l2cache* L2;
        memory* Disk;
        watcher* Watcher;
public:
        manager(watcher* thewatcher);
        processor* Processor();
        l1cache* Icache();
        l1cache* Dcache();
        l2cache* L2cache();
        memory* Memory();
        watcher* Watcher();
};

#endif

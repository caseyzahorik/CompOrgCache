#ifndef __processor
#define __processor

#include "l1cache.h"
#include "watcher.h"
#include "types.h"

class processor
{
private:
        watcher* Watcher;
        l1cache* Icache;
        l1cache* Dcache;
public:
        processor(l1cache* icache,l1cache* dcache,watcher* thewatcher);
        ull decode(char op, ull address, uint bytes);
        ull fetchInstr(ull address, uint bytes);
        ull read(ull address,uint bytes);
        ull write(ull address, uint bytes);
};

#endif

#ifndef __processor
#define __processor

#include "types.h"
#include "watcher.h"
#include "l1cache.h"
using namespace std;

class processor
{
public:
        watcher* Watcher;
        l1cache* Icache;
        l1cache* Dcache;

        processor(l1cache*,l1cache*,watcher*);
        ull decode(char op, ull address, uint bytes);
        ull fetchInstr(ull address, uint bytes);
        ull read(ull address,uint bytes);
        ull write(ull address, uint bytes);
};

#endif

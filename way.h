#ifndef __way
#define __way

#include "types.h"

class way
{
private:
        watcher* Watcher;
        int promote(way** head);
public:

        bool valid;
        ull tag;//do we want to store the whole address
        //or do we just want to store a part of it... is the
        //memory usage worth the hastle of cutting up the address?
        bool dirty;
        way* next;
        way* prev;

        way();
        way(way* prev,way* next);
        int read(way** head, ull address);
        int write(way** head, ull address);
        int fill(way** head, ull address);
        int flush(way** head);//flush all ways
};

#endif

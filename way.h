#ifndef __way
#define __way

#include "types.h"
using namespace std;

class way
{
public:
        int promote(way** head);

        bool valid;
        ull tag;
        bool dirty;
        way* next;
        way* prev;

        way();
        way(way* prev,way* next);
        int read(way** head, ull address);
        int write(way** head, ull address);
        k_ret fill(way** head, ull address);
        int flush(way** head);//flush all ways
};

#endif

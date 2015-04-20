#ifndef __types
#define __types

typedef unsigned long long int ull;

typedef unsigned int uint;

typedef struct kickout
{
        unsigned long long int address;
        bool dirty;
        bool valid;
} k_ret;

#endif

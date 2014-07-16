#include "hash.h"

u64 hash(const char *str)
{
    u64 hash = 5381;
    int c;

    while((c = *str++))
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash;
}
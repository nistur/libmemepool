#include "meme_internal.h"

memeReturn memeClearContext(memeContext* context)
{
    memeReturn(SUCCESS);
}

memeReturn memeInitContext(memeContext** context)
{
    if(context == 0)
        memeReturn(NO_CONTEXT);
    *context = memeMalloc(memeContext);
    if(memeClearContext(*context) != MP_SUCCESS)
       memeTerminateContext(context);
    memeReturn(SUCCESS);
}

memeReturn memeTerminateContext(memeContext** context)
{
    if(*context == 0)
       memeReturn(NO_CONTEXT);
    memeClearContext(*context);
    memeFree(*context);
    *context = 0;
    memeReturn(SUCCESS);
}

const char* memeError()
{
    return g_memeErrors[g_memeError];
}

void* memeMallocInternal(size_t size)
{
    void* x = malloc(size);
    memset(x, 0, size);
    return x;
}
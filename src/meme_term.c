#include "meme_internal.h"

#include "util/hash.h"

memeReturn memeClearTerm(memeTerm* term)
{
    if(term == 0)
        memeReturn(NO_TERM);

    term->class = 0;
    term->data = 0;

    memeReturn(SUCCESS);
}

memeReturn memeInitTerm(memeTerm** term)
{
    if(term == 0)
        memeReturn(NO_TERM);
    *term = memeMalloc(memeTerm);
    if(memeClearTerm(*term) != MP_SUCCESS)
       memeTerminateTerm(term);
    memeReturn(SUCCESS);
}

memeReturn memeTerminateTerm(memeTerm** term)
{
    if(term == 0)
        memeReturn(NO_TERM);
    memeClearTerm(*term);
    memeFree(*term);
    *term = 0;
    memeReturn(SUCCESS);
}

memeReturn memeTermSetClass(memeTerm* term, const char* classStr)
{
    if(term == 0)
        memeReturn(NO_TERM);

    term->class = hash(classStr);

    memeReturn(SUCCESS);
}

memeReturn memeTermSetData(memeTerm* term, const char* data)
{
    if(term == 0)
        memeReturn(NO_TERM);

    term->data = data;

    memeReturn(SUCCESS);
}
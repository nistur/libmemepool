#include "meme_internal.h"

memeReturn memeClearConstruct(memeConstruct* construct)
{
    if(construct == 0)
        memeReturn(NO_CONSTRUCT);

    if(construct->terms != 0)
    {
        int i;
        for(i=0; i<sbcount(construct->terms); ++i)
            memeFree(construct->terms[i]);
        sbfree(construct->terms);
    }

    memeReturn(SUCCESS);
}

memeReturn memeInitConstruct(memeConstruct** construct)
{
    if(construct == 0)
        memeReturn(NO_CONSTRUCT);
    *construct = memeMalloc(memeConstruct);
    if(memeClearConstruct(*construct) != MP_SUCCESS)
       memeTerminateConstruct(construct);
    memeReturn(SUCCESS);
}

memeReturn memeTerminateConstruct(memeConstruct** construct)
{
    if(construct == 0)
        memeReturn(NO_CONSTRUCT);
    memeClearConstruct(*construct);
    memeFree(*construct);
    *construct = 0;
    memeReturn(SUCCESS);
}

memeReturn memeConstructAddTerms(memeConstruct* construct, ...)
{
    va_list argp;
    char* term;
    
    if(construct == 0)
        memeReturn(NO_CONSTRUCT);

    va_start(argp, construct);
    term = va_arg(argp, char*);
    while(term)
    {
        memeTerm* pTerm;
        memeInitTerm(&pTerm);
        if(term[0] == '[')
        {
            // we have a class
            memeTermSetClass(pTerm, term);
        }
        else
        {
            memeTermSetData(pTerm, term);
        }
        sbpush(construct->terms, pTerm);
        term = va_arg(argp, char*);
    }
    va_end(argp);
    memeReturn(SUCCESS);
}

memeReturn memeConstructEvaluate(memeConstruct* construct, memeTerm** terms, int numTerms, char* buffer, int size)
{
    if(construct == 0)
        memeReturn(NO_CONSTRUCT);
    if(terms == 0 || numTerms == 0)
        memeReturn(NO_TERM);

    buffer[0] = 0;

    char* scratch = memeMallocArray(char, size + 1);

    for(int i=0; i<sbcount(construct->terms); ++i)
    {
        memcpy(scratch, buffer, size);
        memeTerm* pTerm = construct->terms[i];
        if(pTerm->class)
        {
            for(int j=0; j<numTerms; ++j)
            {
                if(terms[j]->class == pTerm->class)
                {
                    sprintf(buffer, "%s %s", scratch, terms[j]->data);
                    break;
                }
            }
        }
        else
        {
            sprintf(buffer, "%s %s", scratch, pTerm->data);
        }
    }
    sprintf(scratch, "%s.", buffer);
    memcpy(buffer, &scratch[1], size); // hack so I don't have to do a check on the first term to skip the space
    buffer[0] = toupper(buffer[0]);
    memeFree(scratch);

    memeReturn(SUCCESS);
}

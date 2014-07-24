#include "meme_internal.h"

memeReturn memeClearActor(memeActor* actor)
{
    if(actor == 0)
        memeReturn(NO_ACTOR);

    sbfree( actor->constructs );
    memeReturn(SUCCESS);
}

memeReturn memeInitActor(memeActor** actor)
{
    if(actor == 0)
        memeReturn(NO_ACTOR);
    *actor = memeMalloc(memeActor);
    if(memeClearActor(*actor) != MP_SUCCESS)
       memeTerminateActor(actor);
    memeReturn(SUCCESS);
}

memeReturn memeTerminateActor(memeActor** actor)
{
    if(actor == 0)
        memeReturn(NO_ACTOR);
    memeClearActor(*actor);
    memeFree(*actor);
    *actor = 0;
    memeReturn(SUCCESS);
}

memeReturn memeActorAddConstruct(memeActor* actor, memeConstruct* construct)
{
    if(actor == 0)
        memeReturn(NO_ACTOR);
    if(construct == 0)
        memeReturn(NO_CONSTRUCT);

    sbpush(actor->constructs, construct);

    memeReturn(SUCCESS);
}

memeReturn memeActorMatchConstructs(memeActor* actor, memeTerm** terms, int numTerms, memeConstruct** constructs)
{
    memeConstruct** tempList;
	int i;
    if(actor == 0)
        memeReturn(NO_ACTOR);
    if(terms == 0 || numTerms == 0)
        memeReturn(NO_TERM);
    if(constructs == 0)
        memeReturn(NO_CONSTRUCT);

    for(i = 0; i < sbcount(actor->constructs); ++i)
    {
        // if one of terms isn't in the construct
        // or if one in the construct isn't in the terms
        // then skip this construct,
        // otherwise add it
    }

    // *constructs = memeMallocArray(memeConstruct*, sbcount(tempList))
    // memcpy(*constructs, *tempList, sizeof(memeConstruct*) * sbcount(tempList));
    sbfree(tempList);

    memeReturn(SUCCESS);
}
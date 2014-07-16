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
#ifndef __MEME_ACTOR_H__
#define __MEME_ACTOR_H__

typedef struct _memeActor       memeActor;

MP_EXPORT memeReturn   memeInitActor            (memeActor** actor);
MP_EXPORT memeReturn   memeTerminateActor       (memeActor** actor);

MP_EXPORT memeReturn   memeActorAddConstruct    (memeActor* actor, memeConstruct* construct);

MP_EXPORT memeReturn   memeActorMatchConstructs (memeActor* actor, memeTerm** terms, int numTerms, memeConstruct** constructs);

#endif/*__MEME_ACTOR_H__*/

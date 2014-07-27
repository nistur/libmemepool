#ifndef __MEME_CONSTRUCT_H__
#define __MEME_CONSTRUCT_H__

typedef struct _memeConstruct  memeConstruct;

MP_EXPORT memeReturn   memeInitConstruct      (memeConstruct** construct);
MP_EXPORT memeReturn   memeTerminateConstruct (memeConstruct** construct);

MP_EXPORT memeReturn   memeConstructAddTerms  (memeConstruct* construct, ...);
MP_EXPORT memeReturn   memeConstructEvaluate  (memeConstruct* construct, memeTerm** terms, int numTerms, memeTermList* outTerms);

#endif/*__MEME_CONSTRUCT_H__*/

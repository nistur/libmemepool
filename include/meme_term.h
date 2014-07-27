#ifndef __MEME_TERM_H__
#define __MEME_TERM_H__

typedef struct _memeTerm       memeTerm;
typedef memeTerm*              memeTermPtr;
typedef memeTermPtr*           memeTermList;

MP_EXPORT memeReturn   memeInitTerm         (memeTerm** term);
MP_EXPORT memeReturn   memeTerminateTerm    (memeTerm** term);
MP_EXPORT memeReturn   memeTerminateTermList(memeTermList* list);

MP_EXPORT memeReturn   memeTermSetClass     (memeTerm* term, const char* classStr);
MP_EXPORT memeReturn   memeTermSetData      (memeTerm* term, const char* data);

MP_EXPORT memeReturn   memeTermGetData      (memeTerm* term, char* data, int size);


#endif/*__MEME_TERM_H__*/

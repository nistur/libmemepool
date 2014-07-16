#ifndef __MEME_TERM_H__
#define __MEME_TERM_H__

typedef struct _memeTerm       memeTerm;

MP_EXPORT memeReturn   memeInitTerm        (memeTerm** term);
MP_EXPORT memeReturn   memeTerminateTerm   (memeTerm** term);

MP_EXPORT memeReturn   memeTermSetClass    (memeTerm* term, const char* classStr);
MP_EXPORT memeReturn   memeTermSetData     (memeTerm* term, const char* data);

#endif/*__MEME_TERM_H__*/

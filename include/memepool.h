#pragma once
#ifndef __MEMEPOOL_H__
#define __MEMEPOOL_H__
#ifdef __cplusplus
extern "C" {
#endif/*__cplusplus*/

#ifdef MP_DYNAMIC
# ifdef WIN32
#  ifdef MP_BUILD
#   define MP_EXPORT __declspec( dllexport )
#  else
#   define MP_EXPORT __declspec( dllimport )
#  endif
# endif
#endif
 
#ifndef MP_EXPORT
# define MP_EXPORT
#endif

typedef int memeReturn;

typedef struct _memeContext memeContext;
typedef struct _meme        meme;

#define MP_SUCCESS      0
#define MP_NO_CONTEXT   1
#define MP_NO_CONSTRUCT 2
#define MP_NO_ACTOR     3
#define MP_NO_TERM      4

MP_EXPORT memeReturn   memeInitContext     (memeContext** context);
MP_EXPORT memeReturn   memeTerminateContext(memeContext** context);
MP_EXPORT const char*  memeError();

#include "meme_term.h"
#include "meme_construct.h"
#include "meme_actor.h"

#ifdef __cplusplus
}
#endif/*__cplusplus*/
#endif/*__MEMEPOOL_H__*/

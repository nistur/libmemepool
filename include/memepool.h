#pragma once
#ifndef __TEMPLATE_H__
#define __TEMPLATE_H__
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

#define MP_SUCCESS    0
#define MP_NO_CONTEXT 1

MP_EXPORT memeReturn   memeInitContext     (memeContext** context);
MP_EXPORT memeReturn   memeTerminateContext(memeContext** context);
MP_EXPORT const char*  memeError();

#ifdef __cplusplus
}
#endif/*__cplusplus*/
#endif/*__TEMPLATE_H__*/

#pragma once
#ifndef __MP_INTERNAL_H__
#define __MP_INTERNAL_H__

#include "memepool.h"

/***************************************
 * Library context
 * - holds current state
 ***************************************/
struct _memeContext
{
};

/***************************************
 * Some basic memory management wrappers
 ***************************************/
#include <stdlib.h>
#define memeMalloc(x) (x*)malloc(sizeof(x))
#define memeFree(x)   free(x)

/***************************************
 * Error handling
 ***************************************/
extern memeReturn  g_memeError;
extern const char* g_memeErrors[];
#define memeReturn(x)				\
    {						\
	g_memeError = MP_##x;			\
	return MP_##x;			\
    }



#endif/*__MP_INTERNAL_H__*/

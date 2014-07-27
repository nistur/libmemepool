#pragma once
#ifndef __MP_INTERNAL_H__
#define __MP_INTERNAL_H__

#include "memepool.h"

#include "../util/types.h"
#include "../util/stb.h"

/***************************************
 * Library context
 * - holds current state
 ***************************************/
struct _memeContext
{
    // MSVC complains about empty structs (quite reasonably, I think)
    // so just stick a member in for now until I actually create the
    // context properly
    char PLACEHOLDER;
};

struct _memeConstruct
{
    memeTerm** terms;
};

struct _memeTerm
{
    u64   class;
    const char* data;
};

struct _memeActor
{
    memeConstruct** constructs;
};

/***************************************
 * Some basic memory management wrappers
 ***************************************/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define memeMalloc(x) (x*)memeMallocInternal(sizeof(x))
#define memeMallocArray(x,n) (x*)memeMallocInternal(sizeof(x) * n)
#define memeFree(x)   if(x){ free(x); x=0; }
void* memeMallocInternal(size_t size);

/***************************************
 * Error handling
 ***************************************/
extern memeReturn  g_memeError;
extern const char* g_memeErrors[];
#define memeReturn(x)                \
    {                                \
        g_memeError = MP_##x;        \
        return MP_##x;               \
    }


#include <stdarg.h>

#endif/*__MP_INTERNAL_H__*/


#ifndef BUFFER_H
#define BUFFER_H 1

#include <stdlib.h>

#define INITIAL_BUFFER_SIZE	(1024 * 1024 * 16)	    //	16MB
#define ADDITIVE_BUFFER_SIZE	(1024 * 1024 * 16)	    //	16MB

typedef struct
{
    char *pntr;
    size_t size;
} buffer;

typedef struct 
{
    char *pntr;
    size_t size;
    size_t start;
    size_t len;
} start_buffer;

#endif



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

buffer *allocate_buffer_size(size_t size);
buffer *allocate_buffer();
void free_buffer(buffer *buff);
char *resize_buffer(buffer *buff, size_t size);
char *extend_buffer_size(buffer *buff, size_t size);
char *extend_buffer(buffer *buff);

typedef struct 
{
    char *pntr;
    size_t size;
    size_t start;
    size_t len;
} buffer_start_len;

#endif



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "misc.h"
#include "buffer.h"
#include "string.h"

struct buffer *allocate_buffer_size(size_t size)
{
    struct buffer *result;

    result = malloc(sizeof(struct buffer));
    if (result == NULL)
    {
        return NULL;
    }

    result->pntr = malloc(size);
    if (result->pntr == NULL)
    {
        free(result);
        return NULL;
    }

    result->start = 0;
    result->len = 0;
    result->size = size;

    return result;
}

struct buffer *allocate_buffer()
{
    return allocate_buffer_size(BUFFER_INITIAL_SIZE);
}

void free_buffer(struct buffer *buff)
{
    free(buff->pntr);
    free(buff);
}

char *resize_buffer(struct buffer *buff, size_t size)
{
    char *pntr;

    pntr = realloc(buff->pntr, size);
    if (pntr == NULL)
    {
        return NULL;
    }

    buff->pntr = pntr;
    return pntr;
}

char *extend_buffer_size(struct buffer *buff, size_t size)
{
    
}

char *extend_buffer(struct buffer *buff)
{
    return resize_buffer(buff, BUFFER_ADDITIVE_SIZE);
}


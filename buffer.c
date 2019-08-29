
#include "buffer.h"
#include "memory.h"

void *initialize_buffer_size(buffer *buff, size_t size)
{
    buff->pntr = mem_malloc(size);
    if (buff->pntr == NULL)
    {
    	buff->size = 0;
    	return NULL;
    }

    buff->size = size;
    return buff->pntr;
}

void *initialize_buffer(buffer *buff)
{
    return initialize_buffer_size(buff, INITIAL_BUFFER_SIZE);
}

buffer *allocate_buffer_size(size_t size)
{
    buffer *result;

    result = mem_malloc(sizeof(buffer));
    if (result == NULL)
    {
        return NULL;
    }

    if (initialize_buffer_size(result, size) == NULL)
    {
        mem_free(result);
        return NULL;
    }

    return result;
}


buffer *allocate_buffer()
{
    return allocate_buffer_size(INITIAL_BUFFER_SIZE);
}


void free_buffer(buffer *buff)
{
    mem_free(buff->pntr);
    mem_free(buff);
}


char *resize_buffer(buffer *buff, size_t size)
{
    char *new_pntr;

    new_pntr = mem_realloc(buff->pntr, size);
    if (new_pntr == NULL)
    {
        return NULL;
    }

    buff->pntr = new_pntr;
    buff->size = size;
    return new_pntr;
}


char *extend_buffer_size(buffer *buff, size_t size)
{
    return resize_buffer(buff, buff->size + size);	// TODO: It's not safe.
}


char *extend_buffer(buffer *buff)
{
    return extend_buffer_size(buff, ADDITIVE_BUFFER_SIZE);
}

void *initialize_length_buffer_size(length_buffer *buff, size_t size)
{
    buff->len = 0;
    return initialize_buffer_size( &(buff->internal_buffer), size);
}

void *initialize_length_buffer(length_buffer *buff)
{
    return initialize_length_buffer_size(buff, INITIAL_BUFFER_SIZE);
}

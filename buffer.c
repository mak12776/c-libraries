
#include "buffer.h"
#include "memory.h"


buffer *
allocate_buffer_size(size_t size)
{
    buffer *result;

    result = mem_malloc(sizeof(buffer));
    if (result == NULL)
    {
	return NULL;
    }

    result->pntr = mem_malloc(size);
    if (result->pntr == NULL)
    {
	mem_free(result);
	return NULL;
    }

    result->size = size;
    return result;
}


buffer *
allocate_buffer()
{
    buffer *result;
    return allocate_buffer_size(INITIAL_BUFFER_SIZE);
}


void
free_buffer(buffer *buff)
{
    mem_free(buff->pntr);
    mem_free(buff);
}


char *
resize_buffer(buffer *buff, size_t size)
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


char *
extend_buffer_size(buffer *buff, size_t size)
{
    return resize_buffer(buff, buff->size + size);	// TODO: It's not safe.
}


char *
extend_buffer(buffer *buff)
{
    return extend_buffer_size(buff, ADDITIVE_BUFFER_SIZE);
}



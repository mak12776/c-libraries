
#include <stdio.h>
#include <string.h>

#include "string.h"

struct string *new_string_start_len(char *start, size_t len)
{
    struct string *result;
    size_t size;

    result = ALLOCATE_TYPE(struct string);
    if (result == NULL)
    {
        return NULL;
    }

    size = STRING_INITIAL_SIZE;
    while (size < len)
    {
        size += STRING_ADDITIVE_SIZE;
        if (size == STRING_MAX_SIZE)
        {
            free(result);
            return NULL;
        }
    }
    
    result->start = (char *)malloc(size);
    if (result->start == NULL)
    {
        free(result);
        return NULL;
    }

    memcpy(result->start, start, len);

    result->len = len;
    result->size = size;
    result->refcount = 1;

    return result;
}

struct string *new_string()
{
    struct string *result;

    result = ALLOCATE_TYPE(struct string);
    if (result == NULL)
    {
        return NULL;
    }

    result->start = (char *)malloc(STRING_INITIAL_SIZE);
    if (result->start == NULL)
    {
        free(result);
        return NULL;
    }

    result->len = 0;
    result->size = STRING_INITIAL_SIZE;
    result->refcount = 1;

    return result;
}

struct string *new_string_from(struct string *str)
{
    str->refcount ++;
    return str;
}

void delete_string(struct string *str)
{
    str->refcount --;
    if (str->refcount == 0)
    {
        free(str->start);
        free(str);
    }
}

size_t fwrite_string(FILE *outfile, struct string *str)
{
    return fwrite(str->start, 1, str->len, outfile);
}
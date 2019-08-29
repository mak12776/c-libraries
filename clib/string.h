
#ifndef STRING_H
#define STRING_H 1

#include <stdio.h>

#include "memory.h"
#include "types.h"

#define STRING_INITIAL_SIZE 16
#define STRING_ADDITIVE_SIZE 16
#define STRING_MAX_SIZE \
( \
    ((SIZE_MAX - STRING_INITIAL_SIZE) / STRING_ADDITIVE_SIZE) \
    * STRING_ADDITIVE_SIZE) + STRING_INITIAL_SIZE

struct string
{
    char *start;
    size_t len;
    size_t size;
    refcount_t refcount;
};


struct string *new_string();
struct string *new_string_from(struct string *str);
struct string *new_string_start_len(char *start, size_t len);

void delete_string(struct string *str);

size_t fwrite_string(FILE *outfile, struct string *str);

#endif


#ifndef BUFFER_H
#define BUFFER_H 1

#include "error.h"

#define BUFFER_INITIAL_SIZE         1024 * 1024 * 16    // 16 MB
#define BUFFER_ADDITIVE_SIZE        1024 * 1024 * 16    // 16 MB

#define BUFFER_FREAD_MINIMUM_SIZE   1024 * 1024 * 16    // 16 MB

struct buffer
{
    char *pntr;
    size_t start;
    size_t len;
    size_t size;
};

struct buffer *allocate_buffer_size(size_t size);
struct buffer *allocate_buffer();
void free_buffer(struct buffer *buff);

char *resize_buffer(struct buffer *buff, size_t size);
char *extend_buffer(struct buffer *buff);

#endif // #ifndef BUFFER_H

#ifndef MEMORY_H
#define MEMORY_H 1

#include <stdlib.h>

extern void * (*mem_malloc)  (size_t size);
extern void * (*mem_calloc)  (size_t nmemb, size_t size);
extern void * (*mem_realloc) (void *pntr, size_t size);
extern void   (*mem_free)    (void *pntr);

#endif


#include <stdlib.h>

void * (*mem_malloc)  (size_t size)               = malloc;
void * (*mem_calloc)  (size_t nmemb, size_t size) = calloc;
void * (*mem_realloc) (void *pntr, size_t size)   = realloc;
void   (*mem_free)    (void *pntr)                = free;


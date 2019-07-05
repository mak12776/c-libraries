
#include "misc.h"

size_t fread_size(void *pntr, size_t size, FILE *file)
{
    return fread(pntr, size, 1, file);
}

size_t fwrite_size(void *pntr, size_t size, FILE *file)
{
    return fwrite(pntr, size, 1, file);
}


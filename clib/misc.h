
#ifndef MISC_H
#define MISC_H 1

#include <stdio.h>
#include "error.h"

long get_file_size(FILE *file, error_t *error);
size_t fread_size(char *pntr, size_t size, FILE *file, error_t *error);

#endif
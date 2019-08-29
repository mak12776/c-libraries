
#ifndef STREAM_H
#define STREAM_H 1

#include <stdio.h>
#include "error.h"

struct string *buffer_readline(struct buffer *buff, FILE *file, error_t *error);

#endif
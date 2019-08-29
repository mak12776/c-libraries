
#include <stdio.h>
#include <string.h>

#include "error.h"
#include "buffer.h"
#include "string.h"
#include "misc.h"

struct string *buffer_readline(struct buffer *buff, FILE *file, error_t *error)
{
    size_t fread_num;
    size_t index;
    struct string *string_result;

    if (buff->len == 0)
    {
        fread_num = fread_size(buff->pntr, buff->size, file, error);
        if (fread_num == 0)
        {
            if (error->num != NO_ERROR)
            {
                set_error_msg(error, INFO "fread_size() returned 0");
            }
            return NULL;
        }

        buff->start = 0;
        buff->len = fread_num;
    }

    index = 0;

    loop:
    while (index != buff->len)
    {
        if (buff->pntr[buff->start + index] == '\n')
        {
            index ++;

            string_result = 
                new_string_start_len(buff->pntr + buff->start, index);

            if (string_result == NULL)
            {
                error->num = ERROR_NO_MEMORY;
                set_error_msg(error, INFO "can't allocate memory for string");
                return NULL;
            }

            buff->start += index;
            buff->len -= index;

            return string_result;
        }

        index ++;
    }

    if (buff->len == buff->size)
    {
        if (extend_buffer(buff) == NULL)
        {
            error->num = ERROR_NO_MEMORY;
            set_error_msg(error, INFO "can't extend buffer");
            return NULL;
        }
    }
    else if (buff->start != 0)
    {
        memmove(buff->pntr, buff->pntr + buff->start, buff->len);
        buff->start = 0;
    }

    fread_num = fread_size(
        buff->pntr + buff->len, buff->size - buff->len, file, error);

    if (fread_num == 0)
    {
        if (error->num != NO_ERROR)
        {
            set_error_msg(error, INFO "fread_size() returned 0");
            return NULL;
        }

        string_result = new_string_start_len(buff->pntr + buff->start, index);

        if (string_result == NULL)
        {
            error->num = ERROR_NO_MEMORY;
            set_error_msg(error, INFO "can't allocate memory for string");
            return NULL;
        }

        buff->start += index;
        buff->len -= index;

        return string_result;
    }

    buff->len += fread_num;
    goto loop;
}


#include <stdio.h>
#include "error.h"

long get_file_size(FILE *file, error_t *error)
{
    long file_size;

    if (fseek(file, 0L, SEEK_END) == -1)
    {
        error->num = ERROR_IO_OPERATION;
        set_error_msg(error, INFO "fseak(file, 0L, SEEK_END) returned -1");
        return 0;
    }

    if (file_size = ftell(file) == -1)
    {
        error->num = ERROR_IO_OPERATION;
        set_error_msg(error, INFO "ftell(file) returned -1");
        return 0;
    }

    if (fseek(file, 0L, SEEK_SET) == -1)
    {
        error->num = ERROR_IO_OPERATION;
        set_error_msg(error, INFO "fseak(file, 0L, SEEK_SET) returned -1");
        return 0;
    }

    return file_size;
}

size_t fread_size(char *pntr, size_t size, FILE *file, error_t *error)
{
    size_t fread_num;

    fread_num = fread(pntr, 1, size, file);
    if (fread_num == 0)
    {
        if (feof(file))
        {
            error->num = NO_ERROR;
            set_error_msg(error, INFO "end of file");
        }
        else if (ferror(file))
        {
            error->num = ERROR_IO_OPERATION;
            set_error_msg(error, INFO "ferror(file) returned non-zero value");
        }
        else
        {
            error->num = ERROR_UNDEFINED_BEHAVIOR;
            set_error_msg(error, INFO "undefined behavior while reading file");
        }
    }

    return fread_num;
}

size_t fread_fixed_size(char *pntr, size_t size, FILE *file, error_t *error)
{
    size_t fread_num;
    size_t total_fread_num;

    total_fread_num = 0;

    while (total_fread_num != size)
    {
        fread_num = fread_size(pntr, size, file, error);
        if (fread_num == 0)
        {
            if (error->num != NO_ERROR)
            {
                set_error_msg(error, INFO "fread_size() returned 0");
            }
            break;
        }

        total_fread_num += fread_num;
        pntr += fread_num;
    }

    return total_fread_num;
}

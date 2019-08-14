
#include <stdlib.h>
#include <stdio.h>

#include "error.h"

struct error_msg error_msg_array[ERROR_MSG_ARRAY_SIZE];
size_t error_msg_array_index = 0;

void init_error(error_t *error)
{
    error->num = 0;
    error->msg.string = "";
    error->msg.next = NULL;
}

void set_error_msg(error_t *error, const char *string)
{
    struct error_msg *msg;
    struct error_msg **pntr;

    if (error->msg.string == NULL)
    {
        error->msg.string = string;
        return;
    }

    if (error_msg_array_index != ERROR_MSG_ARRAY_SIZE)
    {
        msg = error_msg_array + error_msg_array_index;
        error_msg_array_index ++;
    }
    else
    {
        msg = (struct error_msg *)mem_malloc(sizeof(struct error_msg));
        if (msg == NULL)
        {
            return;
        }
    }

    msg->string = string;
    msg->next = NULL;

    pntr = &(error->msg.next);

    while ((*pntr) != NULL)
    {
        pntr = &((*pntr)->next);
    }

    (*pntr) = msg;
}


#define log_title(title, file) fprintf(file, "[ " title " ]:\n")

void dump_error_num(unsigned int num, FILE *file)
{
    if (num == NO_ERROR)
    {
        log_title("NO ERROR", file);
    }
    else if (num == ERROR_IO_OPERATION)
    {
        log_title("IO OPERATION", file);
    }
    else if (num == ERROR_NO_MEMORY)
    {
        log_title("NO MEMORY", file);
    }
    else if (num == ERROR_FATAL)
    {
        log_title("FATAL ERROR", file);
    }
    else if (num == ERROR_UNDEFINED_BEHAVIOR)
    {
        log_title("UNDEFINED BEHAVIOR", file);
    }
    else
    {
	log_title("UNKNOWN ERROR NUMBER", file);
    }
}

#undef log_title


#define log_msg(msg, file) fprintf(file, "%s\n", msg)

void dump_error_msg(error_t *error, FILE *file)
{
    struct error_msg *msg;

    msg = &(error->msg);

    while (msg != NULL)
    {
        if (msg->string != NULL)
        {
            log_msg(msg->string, file);
        }
        else
        {
            log_msg("NULL", file);
        }
        msg = msg->next;
    }
}

#undef log_msg


void dump_error(error_t *error, FILE *file)
{
    dump_error_num(error->num, file);
    dump_error_msg(error, file);
}



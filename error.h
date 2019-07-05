
#ifndef ERROR_H
#define ERROR_H 1

#define _STR(x) #x
#define STR(x) _STR(x)
#define INFO __FILE__ ":" STR(__LINE__) ": "

#define ERROR_MSG_ARRAY_SIZE 50

#define NO_ERROR 0
#define ERROR_IO_OPERATION 1
#define ERROR_NO_MEMORY 2
#define ERROR_INVALID_ARGUMENTS 3
#define ERROR_FATAL 31
#define ERROR_UNDEFINED_BEHAVIOR 32

struct error_msg
{
    const char *string;
    struct error_msg *next;
};

typedef struct
{
    unsigned int num;
    struct error_msg msg;
} error_t;

void init_error(error_t *error);
void set_error_msg(error_t *error, const char *string);
void dump_error(error_t *error, FILE *file);

#endif // #ifndef ERROR_H



#ifndef LINKED_ARRAY_H
#define LINKED_ARRAY_H 1

#if 0

typedef size_t linked_array_size_t;

typedef struct
{
    void *pntr;
    linked_array len;
    size_t size;
    struct linked_array *next;
} linkedarray;

struct linked_array *allocate_linked_array(size_t size);
void free_linked_array(struct linked_array *array);

#endif

#endif // LINKED_ARRAY_H

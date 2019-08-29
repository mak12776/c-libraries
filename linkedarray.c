
#include <stdlib.h>

#include "linkedarray.h"
#include "error.h"

#if 0

struct linked_array *allocate_linked_array(size_t size)
{
    struct linked_array *result;

    result = malloc(sizeof(struct linked_array));
    if (!result)
    {
        return NULL;
    }

    result->pntr = malloc(size);
    if (!result->pntr)
    {
        free(result);
        return NULL;
    }
    result->len = 0;
    result->size = size;
    result->next = NULL;

    return result;
}


void free_linked_array(struct linked_array *array)
{
    struct linked_array *p1, *p2;

    p1 = array;

    while (p1 != NULL)
    {
        free(p1->pntr);
        p2 = p1->next;
        free(p1);

        p1 = p2;
    }
}


void linked_array_append(struct linked_array *array, void *data, error_t *error)
{
    struct linked_array **p1;

    p1 = &array;

    while ((*p1)->len == (*p1)->size)
    {
        p1 = &((*p1)->next);
        if ((*p1) == NULL)
        {

        }
    }


}

#endif

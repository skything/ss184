#include "Memory.h"

void* SaferMalloc(size_t size)
{
    void** ptr = NULL;

    ptr = (void**)malloc(16);

    if (ptr == NULL)
        return NULL;

    *ptr = malloc(size);

    if (*ptr == NULL)
        return NULL;
    return *ptr;
}

void SaferFree(void** ptr)
{
    if (ptr == NULL || *ptr == NULL)
        return;

    free(*ptr);
    *ptr = NULL;
}

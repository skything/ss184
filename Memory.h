#ifndef _MEMORY_H
#define _MEMORY_H
#include <stdlib.h>

#ifndef NULL
  #ifdef _cplusplus
  #define NULL 0
  #else
  #define NULL (void *)0
  #endif
#endif

void* SaferMalloc(size_t size);
void  SaferFree(void **ptr);

#define SaferMalloc(size) SaferMalloc((size_t)size)
#define SaferFree(ptr) SaferFree((void **)&ptr)

#endif

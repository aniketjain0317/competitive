#include <stdio.h>
#include <stdlib.h>
#include "memory.h"

void *myalloc(size_t t)
{
    void *mem;
    mem = malloc(t);
    space += t;
    return mem;
}

void myfree(void *mem)
{
    space -= sizeof(mem);
    free(mem);
}

#include <stdio.h>
#include <string.h>

#include "seut/seut_alloc.h"

void * SeUt_MAlloc(size_t size)
{
    void * ptr = malloc(size);
    if (ptr == NULL)
    {
        fprintf(stderr, "SeUt_MAlloc: Failed to allocate %zu bytes.\n", size);
        exit(EXIT_FAILURE);
    }
}

void * SeUt_CAlloc(size_t nmemb, size_t size)
{
    void * ptr = calloc(nmemb, size);
    if (ptr == NULL)
    {
        fprintf(stderr,
                "SeUt_CAlloc: Failed to allocate %zu bytes.\n",
                nmemb * size);
        exit(EXIT_FAILURE);
    }
}

void SeUt_Realloc(void * ptr, size_t size)
{
    ptr = SeUt_ReallocNewPtr(ptr, size);
}

void * SeUt_ReallocNewPtr(void * ptr, size_t size)
{
    void * new_ptr = realloc(ptr, size);
    if (new_ptr == NULL)
    {
        fprintf(stderr,
                "SeUt_Realloc: Failed to reallocate %zu bytes.\n",
                size);
        exit(EXIT_FAILURE);
    }
    return new_ptr;
}

void * SeUt_MemCCopy(void * dst, const void * src, int c, size_t size)
{
    void * new_ptr = memccpy(dst, src, c, size);
    if (new_ptr == NULL)
    {
        fprintf(stderr, "SeUt_MemCCopy: Failed to copy %zu bytes.\n", size);
        exit(EXIT_FAILURE);
    }

    return new_ptr;
}

void SeUt_MemCopy(void * dst, const void * src, size_t size)
{
    void * cpy = memcpy(dst, src, size);
    if (cpy == NULL)
    {
        fprintf(stderr, "SeUt_MemCopy: Failed to copy %zu bytes.\n", size);
        exit(EXIT_FAILURE);
    }
}

void SeUt_MemMove(void * dst, const void * src, size_t size)
{
    void * mv = memmove(dst, src, size);
    if (mv == NULL)
    {
        fprintf(stderr, "SeUt_MemMove: Failed to move %zu bytes.\n", size);
        exit(EXIT_FAILURE);
    }
}

void SeUt_Free(void * ptr)
{
    if (ptr != NULL)
        free(ptr);
    else
    {
        fprintf(stderr, "SeUt_Free: NULL pointer.\n");
        exit(EXIT_FAILURE);
    }
}

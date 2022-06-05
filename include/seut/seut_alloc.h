/**
 * @file seut_alloc.h
 * @author Isaac Yee (48425750+IY314@users.noreply.github.com)
 * @brief Allocation functions for the SeUt library.
 * @version 0.1
 * @date 2022-06-04
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef __SEUT_ALLOC_H__
#define __SEUT_ALLOC_H__

#include <stdlib.h>
#include "seut_cfg.h"

seut__begin

    /**
     * @brief Allocate memory.
     *
     * @param size The size of the memory to allocate.
     * @return void * The allocated memory.
     */
    void * SeUt_MAlloc(size_t size);

    /**
     * @brief Allocate memory and initialize it with 0.
     *
     * @param nmemb The number of elements to allocate.
     * @param size The size of each element.
     * @return void * The allocated memory.
     */
    void * SeUt_CAlloc(size_t nmemb, size_t size);

    /**
     * @brief Reallocate memory.
     *
     * @param ptr The memory to reallocate.
     * @param size The size of the memory to allocate.
     * @return void * The allocated memory.
     */
    void SeUt_Realloc(void * ptr, size_t size);

    /**
     * @brief Reallocate memory in a new pointer.
     *
     * @param ptr The memory to reallocate.
     * @param size The size of the memory to allocate.
     * @return void * The allocated memory.
     */
    void * SeUt_ReallocNewPtr(void * ptr, size_t size);

    /**
     * @brief Copy a chunk of memory until a character is reached.
     *
     * @param dst The destination memory.
     * @param src The source memory.
     * @param c The character to stop at.
     * @param size The size of the memory to copy.
     * @return void * The allocated memory.
     */
    void * SeUt_MemCCopy(void * dst, const void * src, int c, size_t size);

    /**
     * @brief Copy a chunk of memory.
     *
     * @param dst The destination memory.
     * @param src The source memory.
     * @param size The size of the memory to copy.
     */
    void SeUt_MemCopy(void * dst, const void * src, size_t size);

    /**
     * @brief Copy a chunk of memory and allow overlap.
     *
     * @param dst The destination memory.
     * @param src The source memory.
     * @param size The size of the memory to copy.
     */
    void SeUt_MemMove(void * dst, const void * src, size_t size);

    /**
     * @brief Free memory.
     *
     * @param ptr The memory to free.
     */
    void SeUt_Free(void * ptr);

seut__end

#endif  // __SEUT_ALLOC_H__

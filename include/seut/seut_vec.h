#ifndef __SEUT_VEC_H__
#define __SEUT_VEC_H__

#include <stdlib.h>

#include "seut_types.h"

seut__begin

    /**
     * @brief A vector of elements.
     *
     */
    typedef struct _SeUt_PubVec
    {
        struct _SeUt_PrivVec * priv;

        SeUt_U32 size;

        /**
         * @brief Get the element at the given index.
         *
         * @param vec The vector.
         * @param index The index.
         * @return void * The element.
         */
        void * (*get)(SeUt_Vec *, SeUt_U32);

        /**
         * @brief Set the element at the given index.
         *
         * @param vec The vector.
         * @param index The index.
         * @param value The value.
         */
        void (*set)(SeUt_Vec *, SeUt_U32, void *);

        /**
         * @brief Copy and set the element at the given index.
         *
         * @param vec The vector.
         * @param index The index.
         * @param value The value.
         */
        void (*setcpy)(SeUt_Vec *, SeUt_U32, void *);

        /**
         * @brief Push a new element to the end of the vector.
         *
         * @param vec The vector.
         * @param value The value.
         */
        void (*push)(SeUt_Vec *, void *);

        /**
         * @brief Pop the last element from the vector.
         *
         * @param vec The vector.
         * @return void * The value.
         */
        void * (*pop)(SeUt_Vec *);

        /**
         * @brief Remove the element at the given index.
         *
         * @param vec The vector.
         * @param index The index.
         * @return void * The value.
         */
        void * (*remove)(SeUt_Vec *, SeUt_U32);

        /**
         * @brief Append the given vector to the end of the vector.
         *
         * @param vec The vector.
         * @param other The other vector.
         */
        void (*append)(SeUt_Vec *, SeUt_Vec *);

        /**
         * @brief Free the vector.
         *
         * @param vec The vector.
         */
        void (*delete)(SeUt_Vec *);
    } SeUt_Vec;

    /**
     * @brief Create a new vector.
     *
     * @return SeUt_Vec * The vector.
     */
    SeUt_Vec * SeUt_NewVec(void);

    /**
     * @brief Copy the given vector.
     *
     * @param vec The vector.
     * @return SeUt_Vec * The copy.
     */
    SeUt_Vec * SeUt_CopyVec(SeUt_Vec * vec);

seut__end

#endif  // __SEUT_VEC_H__

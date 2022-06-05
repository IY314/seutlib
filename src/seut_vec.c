#include <string.h>

#include "seut/seut_alloc.h"
#include "seut/seut_vec.h"

struct _SeUt_PrivVec
{
    void ** data;
    SeUt_U32 cap;
};

void * Vec_get(SeUt_Vec * vec, SeUt_U32 index)
{
    if (index >= vec->size) return NULL;
    return vec->priv->data[index];
}

void Vec_set(SeUt_Vec * vec, SeUt_U32 index, void * value)
{
    if (index >= vec->size) return;
    vec->priv->data[index] = value;
}

void Vec_setcpy(SeUt_Vec * vec, SeUt_U32 index, void * value)
{
    if (index >= vec->size) return;
    vec->priv->data[index] = SeUt_Malloc(vec->priv->cap);
    SeUt_MemCopy(vec->priv->data[index], value, vec->priv->cap);
}

void Vec_push(SeUt_Vec * vec, void * value)
{
    if (vec->size >= vec->priv->cap)
    {
        vec->priv->cap *= 2;
        SeUt_Realloc(vec->priv->data, vec->priv->cap * sizeof(void *));
    }
    vec->priv->data[vec->size++] = value;
}

void * Vec_pop(SeUt_Vec * vec)
{
    if (vec->size == 0) return NULL;
    return vec->priv->data[--vec->size];
}

void * Vec_remove(SeUt_Vec * vec, SeUt_U32 index)
{
    if (index >= vec->size) return NULL;
    void * value = vec->priv->data[index];
    for (SeUt_U32 i = index; i < vec->size - 1; i++)
    {
        vec->priv->data[i] = vec->priv->data[i + 1];
    }
    vec->size--;
    return value;
}

void Vec_append(SeUt_Vec * vec, SeUt_Vec * other)
{
    if (other->size == 0) return;
    if (vec->size + other->size >= vec->priv->cap)
    {
        vec->priv->cap *= 2;
        SeUt_Realloc(vec->priv->data, vec->priv->cap * sizeof(void *));
    }
    SeUt_MemCopy(vec->priv->data + vec->size,
                 other->priv->data,
                 other->size * sizeof(void *));
    vec->size += other->size;
}

void Vec_delete(SeUt_Vec * vec)
{
    if (vec->priv->data != NULL)
    {
        for (SeUt_U32 i = 0; i < vec->size; i++)
        {
            SeUt_Free(vec->priv->data[i]);
        }
        SeUt_Free(vec->priv->data);
    }
    SeUt_Free(vec->priv);
    SeUt_Free(vec);
}

SeUt_Vec * SeUt_NewVec(void)
{
    SeUt_Vec * vec  = SeUt_MAlloc(sizeof(SeUt_Vec));
    vec->priv       = SeUt_MAlloc(sizeof(struct _SeUt_PrivVec));
    vec->priv->data = SeUt_MAlloc(sizeof(void *));
    vec->size       = 0;
    vec->priv->cap  = 1;

    vec->get    = Vec_get;
    vec->set    = Vec_set;
    vec->setcpy = Vec_setcpy;
    vec->push   = Vec_push;
    vec->pop    = Vec_pop;
    vec->remove = Vec_remove;
    vec->append = Vec_append;
    vec->delete = Vec_delete;

    return vec;
}

SeUt_Vec * SeUt_CopyVec(SeUt_Vec * vec)
{
    SeUt_Vec * copy = SeUt_MAlloc(sizeof(SeUt_Vec));
    SeUt_MemMove(copy->priv, vec->priv, sizeof(struct _SeUt_PrivVec));

    copy->size = vec->size;

    copy->get    = vec->get;
    copy->set    = vec->set;
    copy->setcpy = vec->setcpy;
    copy->push   = vec->push;
    copy->pop    = vec->pop;
    copy->remove = vec->remove;
    copy->append = vec->append;
    copy->delete = vec->delete;

    return copy;
}

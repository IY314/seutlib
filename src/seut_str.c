#include "seut/seut_alloc.h"
#include "seut/seut_str.h"

struct _SeUt_String
{
    char * str;
    size_t len;
    size_t cap;
};

SeUt_String * SeUt_NewString(const char * str)
{
    SeUt_String * s = SeUt_Malloc(sizeof(SeUt_String));
    s->str          = SeUt_Calloc(strlen(str), sizeof(char));
    strcpy(s->str, str);
    s->len = strlen(str);
    s->cap = s->len;
    return s;
}

void SeUt_DeleteString(SeUt_String * str)
{
    if (str != NULL)
    {
        free(str->str);
        free(str);
    }
}

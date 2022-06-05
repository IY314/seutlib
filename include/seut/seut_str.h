#ifndef __SEUT_STR_H__
#define __SEUT_STR_H__

#include "seut.h"

seut__begin

    typedef struct _SeUt_String SeUt_String;

    SeUt_String * SeUt_NewString(const char * str);

    void SeUt_DeleteString(SeUt_String * str);

seut__end

#endif  // __SEUT_STR_H__

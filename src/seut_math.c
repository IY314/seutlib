#include "seut/seut_math.h"

SeUt_U64 SeUt_Fact(SeUt_U32 n)
{
    unsigned long long r = 1;
    for (; n > 0; n--) r *= n;
    return r;
}

SeUt_U64 SeUt_RFact(SeUt_U32 n) { return n == 0 ? 1 : n * SeUt_RFact(n - 1); }

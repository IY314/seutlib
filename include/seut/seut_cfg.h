#ifndef __SEUT_CFG_H__
#define __SEUT_CFG_H__

#ifdef __cplusplus
    #define seut__begin \
        extern "C"      \
        {
    #define seut__end }
#else
    #define seut__begin
    #define seut__end
#endif  // __cplusplus

#endif  // __SEUT_CFG_H__

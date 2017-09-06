/* Created by plibgen $Revision: 1.31 $ */

#ifndef _PCACHE_P32MX150F128B_H
#define _PCACHE_P32MX150F128B_H

/* Section 1 - Enumerate instances, define constants, VREGs */

#include <xc.h>
#include <stdbool.h>

#include "peripheral/peripheral_common_32bit.h"

/* Default definition used for all API dispatch functions */
#ifndef PLIB_INLINE_API
    #define PLIB_INLINE_API extern inline
#endif

/* Default definition used for all other functions */
#ifndef PLIB_INLINE
    #define PLIB_INLINE extern inline
#endif

typedef enum {

    PCACHE_NUMBER_OF_MODULES

} PCACHE_MODULE_ID;

typedef enum {

    PLIB_PCACHE_PREFETCH_ENABLE_NONE

} PLIB_PCACHE_PREFETCH_ENABLE;

typedef enum {

    PLIB_PCACHE_DATA_ENABLE_NONE

} PLIB_PCACHE_DATA_ENABLE;

/* Section 2 - Feature variant inclusion */

#define PLIB_TEMPLATE PLIB_INLINE

/* Section 3 - PLIB dispatch function definitions */

PLIB_INLINE_API bool PLIB_PCACHE_ExistsWaitState(PCACHE_MODULE_ID index)
{
    switch (index) {
        case PCACHE_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_PCACHE_WaitStateSet(PCACHE_MODULE_ID index, uint32_t clocks)
{
    switch (index) {
        case PCACHE_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API uint32_t _PLIB_UNSUPPORTED PLIB_PCACHE_WaitStateGet(PCACHE_MODULE_ID index)
{
    switch (index) {
        case PCACHE_NUMBER_OF_MODULES :
        default :
            return (uint32_t)0;
    }
}

PLIB_INLINE_API bool PLIB_PCACHE_ExistsPrefetchEnable(PCACHE_MODULE_ID index)
{
    switch (index) {
        case PCACHE_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_PCACHE_PrefetchEnableSet(PCACHE_MODULE_ID index, PLIB_PCACHE_PREFETCH_ENABLE region)
{
    switch (index) {
        case PCACHE_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API PLIB_PCACHE_PREFETCH_ENABLE _PLIB_UNSUPPORTED PLIB_PCACHE_PrefetchEnableGet(PCACHE_MODULE_ID index)
{
    switch (index) {
        case PCACHE_NUMBER_OF_MODULES :
        default :
            return (PLIB_PCACHE_PREFETCH_ENABLE)0;
    }
}

PLIB_INLINE_API bool PLIB_PCACHE_ExistsDataCacheEnable(PCACHE_MODULE_ID index)
{
    switch (index) {
        case PCACHE_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_PCACHE_DataCacheEnableSet(PCACHE_MODULE_ID index, PLIB_PCACHE_DATA_ENABLE dcache_en)
{
    switch (index) {
        case PCACHE_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API PLIB_PCACHE_DATA_ENABLE _PLIB_UNSUPPORTED PLIB_PCACHE_DataCacheEnableGet(PCACHE_MODULE_ID index)
{
    switch (index) {
        case PCACHE_NUMBER_OF_MODULES :
        default :
            return (PLIB_PCACHE_DATA_ENABLE)0;
    }
}

PLIB_INLINE_API bool PLIB_PCACHE_ExistsFlashSECInt(PCACHE_MODULE_ID index)
{
    switch (index) {
        case PCACHE_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_PCACHE_FlashSECIntEnable(PCACHE_MODULE_ID index)
{
    switch (index) {
        case PCACHE_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_PCACHE_FlashSECIntDisable(PCACHE_MODULE_ID index)
{
    switch (index) {
        case PCACHE_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API bool PLIB_PCACHE_ExistsFlashDEDStatus(PCACHE_MODULE_ID index)
{
    switch (index) {
        case PCACHE_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API bool _PLIB_UNSUPPORTED PLIB_PCACHE_FlashDEDStatusGet(PCACHE_MODULE_ID index)
{
    switch (index) {
        case PCACHE_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_PCACHE_FlashDEDStatusClear(PCACHE_MODULE_ID index)
{
    switch (index) {
        case PCACHE_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API bool PLIB_PCACHE_ExistsFlashSECStatus(PCACHE_MODULE_ID index)
{
    switch (index) {
        case PCACHE_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API bool _PLIB_UNSUPPORTED PLIB_PCACHE_FlashSECStatusGet(PCACHE_MODULE_ID index)
{
    switch (index) {
        case PCACHE_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_PCACHE_FlashSECStatusSet(PCACHE_MODULE_ID index)
{
    switch (index) {
        case PCACHE_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_PCACHE_FlashSECStatusClear(PCACHE_MODULE_ID index)
{
    switch (index) {
        case PCACHE_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API bool PLIB_PCACHE_ExistsFlashSECCount(PCACHE_MODULE_ID index)
{
    switch (index) {
        case PCACHE_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_PCACHE_FlashSECCountSet(PCACHE_MODULE_ID index, uint8_t count)
{
    switch (index) {
        case PCACHE_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API uint8_t _PLIB_UNSUPPORTED PLIB_PCACHE_FlashSECCountGet(PCACHE_MODULE_ID index)
{
    switch (index) {
        case PCACHE_NUMBER_OF_MODULES :
        default :
            return (uint8_t)0;
    }
}

PLIB_INLINE_API bool PLIB_PCACHE_ExistsInvalidateOnPFMProgram(PCACHE_MODULE_ID index)
{
    switch (index) {
        case PCACHE_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_PCACHE_InvalidateOnPFMProgramAll(PCACHE_MODULE_ID index)
{
    switch (index) {
        case PCACHE_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_PCACHE_InvalidateOnPFMProgramUnlocked(PCACHE_MODULE_ID index)
{
    switch (index) {
        case PCACHE_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API bool PLIB_PCACHE_ExistsCacheLine(PCACHE_MODULE_ID index)
{
    switch (index) {
        case PCACHE_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_PCACHE_CacheLineSelect(PCACHE_MODULE_ID index, uint32_t cache_line)
{
    switch (index) {
        case PCACHE_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_PCACHE_CacheLineDeselect(PCACHE_MODULE_ID index, uint32_t cache_line)
{
    switch (index) {
        case PCACHE_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_PCACHE_CacheLineData(PCACHE_MODULE_ID index)
{
    switch (index) {
        case PCACHE_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_PCACHE_CacheLineInst(PCACHE_MODULE_ID index)
{
    switch (index) {
        case PCACHE_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API bool _PLIB_UNSUPPORTED PLIB_PCACHE_CacheLineIsInst(PCACHE_MODULE_ID index)
{
    switch (index) {
        case PCACHE_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API bool PLIB_PCACHE_ExistsCacheLineType(PCACHE_MODULE_ID index)
{
    switch (index) {
        case PCACHE_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_PCACHE_CacheLineLock(PCACHE_MODULE_ID index)
{
    switch (index) {
        case PCACHE_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_PCACHE_CacheLineUnlock(PCACHE_MODULE_ID index)
{
    switch (index) {
        case PCACHE_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API bool _PLIB_UNSUPPORTED PLIB_PCACHE_CacheLineIsLocked(PCACHE_MODULE_ID index)
{
    switch (index) {
        case PCACHE_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API bool PLIB_PCACHE_ExistsCacheLineLock(PCACHE_MODULE_ID index)
{
    switch (index) {
        case PCACHE_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_PCACHE_CacheLineValid(PCACHE_MODULE_ID index)
{
    switch (index) {
        case PCACHE_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_PCACHE_CacheLineInvalid(PCACHE_MODULE_ID index)
{
    switch (index) {
        case PCACHE_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API bool _PLIB_UNSUPPORTED PLIB_PCACHE_CacheLineIsValid(PCACHE_MODULE_ID index)
{
    switch (index) {
        case PCACHE_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API bool PLIB_PCACHE_ExistsCacheLineValid(PCACHE_MODULE_ID index)
{
    switch (index) {
        case PCACHE_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_PCACHE_CacheLineAddrSet(PCACHE_MODULE_ID index, uint32_t addr)
{
    switch (index) {
        case PCACHE_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API uint32_t _PLIB_UNSUPPORTED PLIB_PCACHE_CacheLineAddrGet(PCACHE_MODULE_ID index)
{
    switch (index) {
        case PCACHE_NUMBER_OF_MODULES :
        default :
            return (uint32_t)0;
    }
}

PLIB_INLINE_API bool PLIB_PCACHE_ExistsCacheLineAddr(PCACHE_MODULE_ID index)
{
    switch (index) {
        case PCACHE_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_PCACHE_CacheLineFlashTypeBoot(PCACHE_MODULE_ID index)
{
    switch (index) {
        case PCACHE_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_PCACHE_CacheLineFlashTypeInst(PCACHE_MODULE_ID index)
{
    switch (index) {
        case PCACHE_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API bool _PLIB_UNSUPPORTED PLIB_PCACHE_CacheLineFlashTypeIsInst(PCACHE_MODULE_ID index)
{
    switch (index) {
        case PCACHE_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API bool PLIB_PCACHE_ExistsCacheLineFlashType(PCACHE_MODULE_ID index)
{
    switch (index) {
        case PCACHE_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_PCACHE_CacheLineMaskSet(PCACHE_MODULE_ID index, uint32_t mask)
{
    switch (index) {
        case PCACHE_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API uint32_t _PLIB_UNSUPPORTED PLIB_PCACHE_CacheLineMaskGet(PCACHE_MODULE_ID index)
{
    switch (index) {
        case PCACHE_NUMBER_OF_MODULES :
        default :
            return (uint32_t)0;
    }
}

PLIB_INLINE_API bool PLIB_PCACHE_ExistsCacheLineMask(PCACHE_MODULE_ID index)
{
    switch (index) {
        case PCACHE_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API uint32_t _PLIB_UNSUPPORTED PLIB_PCACHE_WordRead(PCACHE_MODULE_ID index, uint32_t word)
{
    switch (index) {
        case PCACHE_NUMBER_OF_MODULES :
        default :
            return (uint32_t)0;
    }
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_PCACHE_WordWrite(PCACHE_MODULE_ID index, uint32_t word, uint32_t data)
{
    switch (index) {
        case PCACHE_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API bool PLIB_PCACHE_ExistsWord(PCACHE_MODULE_ID index)
{
    switch (index) {
        case PCACHE_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API uint32_t _PLIB_UNSUPPORTED PLIB_PCACHE_LeastRecentlyUsedStateRead(PCACHE_MODULE_ID index)
{
    switch (index) {
        case PCACHE_NUMBER_OF_MODULES :
        default :
            return (uint32_t)0;
    }
}

PLIB_INLINE_API bool PLIB_PCACHE_ExistsLeastRecentlyUsedState(PCACHE_MODULE_ID index)
{
    switch (index) {
        case PCACHE_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API uint32_t _PLIB_UNSUPPORTED PLIB_PCACHE_CacheHitRead(PCACHE_MODULE_ID index)
{
    switch (index) {
        case PCACHE_NUMBER_OF_MODULES :
        default :
            return (uint32_t)0;
    }
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_PCACHE_CacheHitWrite(PCACHE_MODULE_ID index, uint32_t data)
{
    switch (index) {
        case PCACHE_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API bool PLIB_PCACHE_ExistsCacheHit(PCACHE_MODULE_ID index)
{
    switch (index) {
        case PCACHE_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API uint32_t _PLIB_UNSUPPORTED PLIB_PCACHE_CacheMissRead(PCACHE_MODULE_ID index)
{
    switch (index) {
        case PCACHE_NUMBER_OF_MODULES :
        default :
            return (uint32_t)0;
    }
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_PCACHE_CacheMissWrite(PCACHE_MODULE_ID index, uint32_t data)
{
    switch (index) {
        case PCACHE_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API bool PLIB_PCACHE_ExistsCacheMiss(PCACHE_MODULE_ID index)
{
    switch (index) {
        case PCACHE_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API uint32_t _PLIB_UNSUPPORTED PLIB_PCACHE_PrefetchAbortRead(PCACHE_MODULE_ID index)
{
    switch (index) {
        case PCACHE_NUMBER_OF_MODULES :
        default :
            return (uint32_t)0;
    }
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_PCACHE_PrefetchAbortWrite(PCACHE_MODULE_ID index, uint32_t data)
{
    switch (index) {
        case PCACHE_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API bool PLIB_PCACHE_ExistsPrefetchAbort(PCACHE_MODULE_ID index)
{
    switch (index) {
        case PCACHE_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

#endif

/* Created by plibgen $Revision: 1.31 $ */

#ifndef _I2C_P32MX250F128B_H
#define _I2C_P32MX250F128B_H

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

    I2C_ID_1 = 0,
    I2C_ID_2,
    I2C_NUMBER_OF_MODULES

} I2C_MODULE_ID;

typedef enum {

    I2C_SDA_MIN_HOLD_TIME_NONE

} I2C_SDA_MIN_HOLD_TIME;

PLIB_INLINE SFR_TYPE* _I2C_MASTER_START_VREG(I2C_MODULE_ID i)
{
    switch (i) {
        case I2C_ID_1 :
            return &I2C1CON;
        case I2C_ID_2 :
            return &I2C2CON;
        case I2C_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _I2C_MASTER_START_REPEAT_VREG(I2C_MODULE_ID i)
{
    switch (i) {
        case I2C_ID_1 :
            return &I2C1CON;
        case I2C_ID_2 :
            return &I2C2CON;
        case I2C_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _I2C_MASTER_STOP_VREG(I2C_MODULE_ID i)
{
    switch (i) {
        case I2C_ID_1 :
            return &I2C1CON;
        case I2C_ID_2 :
            return &I2C2CON;
        case I2C_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _I2C_RECEIVE_1BYTE_VREG(I2C_MODULE_ID i)
{
    switch (i) {
        case I2C_ID_1 :
            return &I2C1CON;
        case I2C_ID_2 :
            return &I2C2CON;
        case I2C_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _I2C_RCVD_BYTE_ACK_ENABLE_VREG(I2C_MODULE_ID i)
{
    switch (i) {
        case I2C_ID_1 :
            return &I2C1CON;
        case I2C_ID_2 :
            return &I2C2CON;
        case I2C_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _I2C_RCVD_BYTE_ACK_DATA_VREG(I2C_MODULE_ID i)
{
    switch (i) {
        case I2C_ID_1 :
            return &I2C1CON;
        case I2C_ID_2 :
            return &I2C2CON;
        case I2C_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _I2C_CLOCK_STRETCH_ENABLE_VREG(I2C_MODULE_ID i)
{
    switch (i) {
        case I2C_ID_1 :
            return &I2C1CON;
        case I2C_ID_2 :
            return &I2C2CON;
        case I2C_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _I2C_GENERAL_CALL_ENABLE_VREG(I2C_MODULE_ID i)
{
    switch (i) {
        case I2C_ID_1 :
            return &I2C1CON;
        case I2C_ID_2 :
            return &I2C2CON;
        case I2C_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _I2C_SMBUS_ENABLE_VREG(I2C_MODULE_ID i)
{
    switch (i) {
        case I2C_ID_1 :
            return &I2C1CON;
        case I2C_ID_2 :
            return &I2C2CON;
        case I2C_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _I2C_HIGH_FREQUENCY_VREG(I2C_MODULE_ID i)
{
    switch (i) {
        case I2C_ID_1 :
            return &I2C1CON;
        case I2C_ID_2 :
            return &I2C2CON;
        case I2C_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _I2C_SLAVE_ADDRESS_10BIT_ENABLE_VREG(I2C_MODULE_ID i)
{
    switch (i) {
        case I2C_ID_1 :
            return &I2C1CON;
        case I2C_ID_2 :
            return &I2C2CON;
        case I2C_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _I2C_RESERVED_ADDR_PROTECT_VREG(I2C_MODULE_ID i)
{
    switch (i) {
        case I2C_ID_1 :
            return &I2C1CON;
        case I2C_ID_2 :
            return &I2C2CON;
        case I2C_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _I2C_SLAVE_CLOCK_HOLD_VREG(I2C_MODULE_ID i)
{
    switch (i) {
        case I2C_ID_1 :
            return &I2C1CON;
        case I2C_ID_2 :
            return &I2C2CON;
        case I2C_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _I2C_STOP_IN_IDLE_VREG(I2C_MODULE_ID i)
{
    switch (i) {
        case I2C_ID_1 :
            return &I2C1CON;
        case I2C_ID_2 :
            return &I2C2CON;
        case I2C_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _I2C_MODULE_ENABLE_VREG(I2C_MODULE_ID i)
{
    switch (i) {
        case I2C_ID_1 :
            return &I2C1CON;
        case I2C_ID_2 :
            return &I2C2CON;
        case I2C_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _I2C_TRANSMITTER_READY_VREG(I2C_MODULE_ID i)
{
    switch (i) {
        case I2C_ID_1 :
            return &I2C1STAT;
        case I2C_ID_2 :
            return &I2C2STAT;
        case I2C_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _I2C_RCVD_BYTE_AVAILABLE_VREG(I2C_MODULE_ID i)
{
    switch (i) {
        case I2C_ID_1 :
            return &I2C1STAT;
        case I2C_ID_2 :
            return &I2C2STAT;
        case I2C_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _I2C_SLAVE_READ_REQUEST_VREG(I2C_MODULE_ID i)
{
    switch (i) {
        case I2C_ID_1 :
            return &I2C1STAT;
        case I2C_ID_2 :
            return &I2C2STAT;
        case I2C_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _I2C_START_DETECT_VREG(I2C_MODULE_ID i)
{
    switch (i) {
        case I2C_ID_1 :
            return &I2C1STAT;
        case I2C_ID_2 :
            return &I2C2STAT;
        case I2C_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _I2C_STOP_DETECT_VREG(I2C_MODULE_ID i)
{
    switch (i) {
        case I2C_ID_1 :
            return &I2C1STAT;
        case I2C_ID_2 :
            return &I2C2STAT;
        case I2C_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _I2C_SLAVE_DATA_DETECT_VREG(I2C_MODULE_ID i)
{
    switch (i) {
        case I2C_ID_1 :
            return &I2C1STAT;
        case I2C_ID_2 :
            return &I2C2STAT;
        case I2C_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _I2C_RCVR_OVERFLOW_VREG(I2C_MODULE_ID i)
{
    switch (i) {
        case I2C_ID_1 :
            return &I2C1STAT;
        case I2C_ID_2 :
            return &I2C2STAT;
        case I2C_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _I2C_TRANS_OVERFLOW_VREG(I2C_MODULE_ID i)
{
    switch (i) {
        case I2C_ID_1 :
            return &I2C1STAT;
        case I2C_ID_2 :
            return &I2C2STAT;
        case I2C_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _I2C_10BIT_ADDRESS_DETECT_VREG(I2C_MODULE_ID i)
{
    switch (i) {
        case I2C_ID_1 :
            return &I2C1STAT;
        case I2C_ID_2 :
            return &I2C2STAT;
        case I2C_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _I2C_GENERAL_CALL_ADDR_DETECT_VREG(I2C_MODULE_ID i)
{
    switch (i) {
        case I2C_ID_1 :
            return &I2C1STAT;
        case I2C_ID_2 :
            return &I2C2STAT;
        case I2C_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _I2C_ARBITRATION_LOSS_VREG(I2C_MODULE_ID i)
{
    switch (i) {
        case I2C_ID_1 :
            return &I2C1STAT;
        case I2C_ID_2 :
            return &I2C2STAT;
        case I2C_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _I2C_TRANS_BYTE_COMPLETE_VREG(I2C_MODULE_ID i)
{
    switch (i) {
        case I2C_ID_1 :
            return &I2C1STAT;
        case I2C_ID_2 :
            return &I2C2STAT;
        case I2C_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _I2C_TRANS_BYTE_ACK_VREG(I2C_MODULE_ID i)
{
    switch (i) {
        case I2C_ID_1 :
            return &I2C1STAT;
        case I2C_ID_2 :
            return &I2C2STAT;
        case I2C_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _I2C_SLAVE_ADDRESS_SET_VREG(I2C_MODULE_ID i)
{
    switch (i) {
        case I2C_ID_1 :
            return &I2C1ADD;
        case I2C_ID_2 :
            return &I2C2ADD;
        case I2C_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _I2C_SLAVE_MASK_VREG(I2C_MODULE_ID i)
{
    switch (i) {
        case I2C_ID_1 :
            return &I2C1MSK;
        case I2C_ID_2 :
            return &I2C2MSK;
        case I2C_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _I2C_BAUD_RATE_VREG(I2C_MODULE_ID i)
{
    switch (i) {
        case I2C_ID_1 :
            return &I2C1BRG;
        case I2C_ID_2 :
            return &I2C2BRG;
        case I2C_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _I2C_TRANS_BYTE_SEND_VREG(I2C_MODULE_ID i)
{
    switch (i) {
        case I2C_ID_1 :
            return &I2C1TRN;
        case I2C_ID_2 :
            return &I2C2TRN;
        case I2C_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _I2C_RCVD_BYTE_GET_VREG(I2C_MODULE_ID i)
{
    switch (i) {
        case I2C_ID_1 :
            return &I2C1RCV;
        case I2C_ID_2 :
            return &I2C2RCV;
        case I2C_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_DATA _I2C_MASTER_START_MASK(I2C_MODULE_ID i)
{
    switch (i) {
        case I2C_ID_1 :
            return _I2C1CON_SEN_MASK;
        case I2C_ID_2 :
            return _I2C2CON_SEN_MASK;
        case I2C_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _I2C_MASTER_START_REPEAT_MASK(I2C_MODULE_ID i)
{
    switch (i) {
        case I2C_ID_1 :
            return _I2C1CON_RSEN_MASK;
        case I2C_ID_2 :
            return _I2C2CON_RSEN_MASK;
        case I2C_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _I2C_MASTER_STOP_MASK(I2C_MODULE_ID i)
{
    switch (i) {
        case I2C_ID_1 :
            return _I2C1CON_PEN_MASK;
        case I2C_ID_2 :
            return _I2C2CON_PEN_MASK;
        case I2C_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _I2C_RECEIVE_1BYTE_MASK(I2C_MODULE_ID i)
{
    switch (i) {
        case I2C_ID_1 :
            return _I2C1CON_RCEN_MASK;
        case I2C_ID_2 :
            return _I2C2CON_RCEN_MASK;
        case I2C_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _I2C_RCVD_BYTE_ACK_ENABLE_MASK(I2C_MODULE_ID i)
{
    switch (i) {
        case I2C_ID_1 :
            return _I2C1CON_ACKEN_MASK;
        case I2C_ID_2 :
            return _I2C2CON_ACKEN_MASK;
        case I2C_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _I2C_RCVD_BYTE_ACK_DATA_MASK(I2C_MODULE_ID i)
{
    switch (i) {
        case I2C_ID_1 :
            return _I2C1CON_ACKDT_MASK;
        case I2C_ID_2 :
            return _I2C2CON_ACKDT_MASK;
        case I2C_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _I2C_CLOCK_STRETCH_ENABLE_MASK(I2C_MODULE_ID i)
{
    switch (i) {
        case I2C_ID_1 :
            return _I2C1CON_STREN_MASK;
        case I2C_ID_2 :
            return _I2C2CON_STREN_MASK;
        case I2C_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _I2C_GENERAL_CALL_ENABLE_MASK(I2C_MODULE_ID i)
{
    switch (i) {
        case I2C_ID_1 :
            return _I2C1CON_GCEN_MASK;
        case I2C_ID_2 :
            return _I2C2CON_GCEN_MASK;
        case I2C_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _I2C_SMBUS_ENABLE_MASK(I2C_MODULE_ID i)
{
    switch (i) {
        case I2C_ID_1 :
            return _I2C1CON_SMEN_MASK;
        case I2C_ID_2 :
            return _I2C2CON_SMEN_MASK;
        case I2C_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _I2C_HIGH_FREQUENCY_MASK(I2C_MODULE_ID i)
{
    switch (i) {
        case I2C_ID_1 :
            return _I2C1CON_DISSLW_MASK;
        case I2C_ID_2 :
            return _I2C2CON_DISSLW_MASK;
        case I2C_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _I2C_SLAVE_ADDRESS_10BIT_ENABLE_MASK(I2C_MODULE_ID i)
{
    switch (i) {
        case I2C_ID_1 :
            return _I2C1CON_A10M_MASK;
        case I2C_ID_2 :
            return _I2C2CON_A10M_MASK;
        case I2C_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _I2C_RESERVED_ADDR_PROTECT_MASK(I2C_MODULE_ID i)
{
    switch (i) {
        case I2C_ID_1 :
            return _I2C1CON_STRICT_MASK;
        case I2C_ID_2 :
            return _I2C2CON_STRICT_MASK;
        case I2C_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _I2C_SLAVE_CLOCK_HOLD_MASK(I2C_MODULE_ID i)
{
    switch (i) {
        case I2C_ID_1 :
            return _I2C1CON_SCLREL_MASK;
        case I2C_ID_2 :
            return _I2C2CON_SCLREL_MASK;
        case I2C_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _I2C_STOP_IN_IDLE_MASK(I2C_MODULE_ID i)
{
    switch (i) {
        case I2C_ID_1 :
            return _I2C1CON_SIDL_MASK;
        case I2C_ID_2 :
            return _I2C2CON_SIDL_MASK;
        case I2C_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _I2C_MODULE_ENABLE_MASK(I2C_MODULE_ID i)
{
    switch (i) {
        case I2C_ID_1 :
            return _I2C1CON_ON_MASK;
        case I2C_ID_2 :
            return _I2C2CON_ON_MASK;
        case I2C_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _I2C_TRANSMITTER_READY_MASK(I2C_MODULE_ID i)
{
    switch (i) {
        case I2C_ID_1 :
            return _I2C1STAT_TBF_MASK;
        case I2C_ID_2 :
            return _I2C2STAT_TBF_MASK;
        case I2C_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _I2C_RCVD_BYTE_AVAILABLE_MASK(I2C_MODULE_ID i)
{
    switch (i) {
        case I2C_ID_1 :
            return _I2C1STAT_RBF_MASK;
        case I2C_ID_2 :
            return _I2C2STAT_RBF_MASK;
        case I2C_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _I2C_SLAVE_READ_REQUEST_MASK(I2C_MODULE_ID i)
{
    switch (i) {
        case I2C_ID_1 :
            return _I2C1STAT_R_W_MASK;
        case I2C_ID_2 :
            return _I2C2STAT_R_W_MASK;
        case I2C_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _I2C_START_DETECT_MASK(I2C_MODULE_ID i)
{
    switch (i) {
        case I2C_ID_1 :
            return _I2C1STAT_S_MASK;
        case I2C_ID_2 :
            return _I2C2STAT_S_MASK;
        case I2C_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _I2C_STOP_DETECT_MASK(I2C_MODULE_ID i)
{
    switch (i) {
        case I2C_ID_1 :
            return _I2C1STAT_P_MASK;
        case I2C_ID_2 :
            return _I2C2STAT_P_MASK;
        case I2C_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _I2C_SLAVE_DATA_DETECT_MASK(I2C_MODULE_ID i)
{
    switch (i) {
        case I2C_ID_1 :
            return _I2C1STAT_D_A_MASK;
        case I2C_ID_2 :
            return _I2C2STAT_D_A_MASK;
        case I2C_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _I2C_RCVR_OVERFLOW_MASK(I2C_MODULE_ID i)
{
    switch (i) {
        case I2C_ID_1 :
            return _I2C1STAT_I2COV_MASK;
        case I2C_ID_2 :
            return _I2C2STAT_I2COV_MASK;
        case I2C_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _I2C_TRANS_OVERFLOW_MASK(I2C_MODULE_ID i)
{
    switch (i) {
        case I2C_ID_1 :
            return _I2C1STAT_IWCOL_MASK;
        case I2C_ID_2 :
            return _I2C2STAT_IWCOL_MASK;
        case I2C_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _I2C_10BIT_ADDRESS_DETECT_MASK(I2C_MODULE_ID i)
{
    switch (i) {
        case I2C_ID_1 :
            return _I2C1STAT_ADD10_MASK;
        case I2C_ID_2 :
            return _I2C2STAT_ADD10_MASK;
        case I2C_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _I2C_GENERAL_CALL_ADDR_DETECT_MASK(I2C_MODULE_ID i)
{
    switch (i) {
        case I2C_ID_1 :
            return _I2C1STAT_GCSTAT_MASK;
        case I2C_ID_2 :
            return _I2C2STAT_GCSTAT_MASK;
        case I2C_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _I2C_ARBITRATION_LOSS_MASK(I2C_MODULE_ID i)
{
    switch (i) {
        case I2C_ID_1 :
            return _I2C1STAT_BCL_MASK;
        case I2C_ID_2 :
            return _I2C2STAT_BCL_MASK;
        case I2C_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _I2C_TRANS_BYTE_COMPLETE_MASK(I2C_MODULE_ID i)
{
    switch (i) {
        case I2C_ID_1 :
            return _I2C1STAT_TRSTAT_MASK;
        case I2C_ID_2 :
            return _I2C2STAT_TRSTAT_MASK;
        case I2C_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _I2C_TRANS_BYTE_ACK_MASK(I2C_MODULE_ID i)
{
    switch (i) {
        case I2C_ID_1 :
            return _I2C1STAT_ACKSTAT_MASK;
        case I2C_ID_2 :
            return _I2C2STAT_ACKSTAT_MASK;
        case I2C_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _I2C_SLAVE_ADDRESS_SET_MASK(I2C_MODULE_ID i)
{
    switch (i) {
        case I2C_ID_1 :
            return (SFR_DATA)-1;
        case I2C_ID_2 :
            return (SFR_DATA)-1;
        case I2C_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _I2C_SLAVE_MASK_MASK(I2C_MODULE_ID i)
{
    switch (i) {
        case I2C_ID_1 :
            return (SFR_DATA)-1;
        case I2C_ID_2 :
            return (SFR_DATA)-1;
        case I2C_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _I2C_BAUD_RATE_MASK(I2C_MODULE_ID i)
{
    switch (i) {
        case I2C_ID_1 :
            return (SFR_DATA)-1;
        case I2C_ID_2 :
            return (SFR_DATA)-1;
        case I2C_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _I2C_TRANS_BYTE_SEND_MASK(I2C_MODULE_ID i)
{
    switch (i) {
        case I2C_ID_1 :
            return (SFR_DATA)-1;
        case I2C_ID_2 :
            return (SFR_DATA)-1;
        case I2C_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _I2C_RCVD_BYTE_GET_MASK(I2C_MODULE_ID i)
{
    switch (i) {
        case I2C_ID_1 :
            return (SFR_DATA)-1;
        case I2C_ID_2 :
            return (SFR_DATA)-1;
        case I2C_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _I2C_MASTER_START_POS(I2C_MODULE_ID i)
{
    switch (i) {
        case I2C_ID_1 :
            return _I2C1CON_SEN_POSITION;
        case I2C_ID_2 :
            return _I2C2CON_SEN_POSITION;
        case I2C_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _I2C_MASTER_START_REPEAT_POS(I2C_MODULE_ID i)
{
    switch (i) {
        case I2C_ID_1 :
            return _I2C1CON_RSEN_POSITION;
        case I2C_ID_2 :
            return _I2C2CON_RSEN_POSITION;
        case I2C_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _I2C_MASTER_STOP_POS(I2C_MODULE_ID i)
{
    switch (i) {
        case I2C_ID_1 :
            return _I2C1CON_PEN_POSITION;
        case I2C_ID_2 :
            return _I2C2CON_PEN_POSITION;
        case I2C_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _I2C_RECEIVE_1BYTE_POS(I2C_MODULE_ID i)
{
    switch (i) {
        case I2C_ID_1 :
            return _I2C1CON_RCEN_POSITION;
        case I2C_ID_2 :
            return _I2C2CON_RCEN_POSITION;
        case I2C_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _I2C_RCVD_BYTE_ACK_ENABLE_POS(I2C_MODULE_ID i)
{
    switch (i) {
        case I2C_ID_1 :
            return _I2C1CON_ACKEN_POSITION;
        case I2C_ID_2 :
            return _I2C2CON_ACKEN_POSITION;
        case I2C_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _I2C_RCVD_BYTE_ACK_DATA_POS(I2C_MODULE_ID i)
{
    switch (i) {
        case I2C_ID_1 :
            return _I2C1CON_ACKDT_POSITION;
        case I2C_ID_2 :
            return _I2C2CON_ACKDT_POSITION;
        case I2C_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _I2C_CLOCK_STRETCH_ENABLE_POS(I2C_MODULE_ID i)
{
    switch (i) {
        case I2C_ID_1 :
            return _I2C1CON_STREN_POSITION;
        case I2C_ID_2 :
            return _I2C2CON_STREN_POSITION;
        case I2C_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _I2C_GENERAL_CALL_ENABLE_POS(I2C_MODULE_ID i)
{
    switch (i) {
        case I2C_ID_1 :
            return _I2C1CON_GCEN_POSITION;
        case I2C_ID_2 :
            return _I2C2CON_GCEN_POSITION;
        case I2C_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _I2C_SMBUS_ENABLE_POS(I2C_MODULE_ID i)
{
    switch (i) {
        case I2C_ID_1 :
            return _I2C1CON_SMEN_POSITION;
        case I2C_ID_2 :
            return _I2C2CON_SMEN_POSITION;
        case I2C_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _I2C_HIGH_FREQUENCY_POS(I2C_MODULE_ID i)
{
    switch (i) {
        case I2C_ID_1 :
            return _I2C1CON_DISSLW_POSITION;
        case I2C_ID_2 :
            return _I2C2CON_DISSLW_POSITION;
        case I2C_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _I2C_SLAVE_ADDRESS_10BIT_ENABLE_POS(I2C_MODULE_ID i)
{
    switch (i) {
        case I2C_ID_1 :
            return _I2C1CON_A10M_POSITION;
        case I2C_ID_2 :
            return _I2C2CON_A10M_POSITION;
        case I2C_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _I2C_RESERVED_ADDR_PROTECT_POS(I2C_MODULE_ID i)
{
    switch (i) {
        case I2C_ID_1 :
            return _I2C1CON_STRICT_POSITION;
        case I2C_ID_2 :
            return _I2C2CON_STRICT_POSITION;
        case I2C_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _I2C_SLAVE_CLOCK_HOLD_POS(I2C_MODULE_ID i)
{
    switch (i) {
        case I2C_ID_1 :
            return _I2C1CON_SCLREL_POSITION;
        case I2C_ID_2 :
            return _I2C2CON_SCLREL_POSITION;
        case I2C_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _I2C_STOP_IN_IDLE_POS(I2C_MODULE_ID i)
{
    switch (i) {
        case I2C_ID_1 :
            return _I2C1CON_SIDL_POSITION;
        case I2C_ID_2 :
            return _I2C2CON_SIDL_POSITION;
        case I2C_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _I2C_MODULE_ENABLE_POS(I2C_MODULE_ID i)
{
    switch (i) {
        case I2C_ID_1 :
            return _I2C1CON_ON_POSITION;
        case I2C_ID_2 :
            return _I2C2CON_ON_POSITION;
        case I2C_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _I2C_TRANSMITTER_READY_POS(I2C_MODULE_ID i)
{
    switch (i) {
        case I2C_ID_1 :
            return _I2C1STAT_TBF_POSITION;
        case I2C_ID_2 :
            return _I2C2STAT_TBF_POSITION;
        case I2C_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _I2C_RCVD_BYTE_AVAILABLE_POS(I2C_MODULE_ID i)
{
    switch (i) {
        case I2C_ID_1 :
            return _I2C1STAT_RBF_POSITION;
        case I2C_ID_2 :
            return _I2C2STAT_RBF_POSITION;
        case I2C_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _I2C_SLAVE_READ_REQUEST_POS(I2C_MODULE_ID i)
{
    switch (i) {
        case I2C_ID_1 :
            return _I2C1STAT_R_W_POSITION;
        case I2C_ID_2 :
            return _I2C2STAT_R_W_POSITION;
        case I2C_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _I2C_START_DETECT_POS(I2C_MODULE_ID i)
{
    switch (i) {
        case I2C_ID_1 :
            return _I2C1STAT_S_POSITION;
        case I2C_ID_2 :
            return _I2C2STAT_S_POSITION;
        case I2C_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _I2C_STOP_DETECT_POS(I2C_MODULE_ID i)
{
    switch (i) {
        case I2C_ID_1 :
            return _I2C1STAT_P_POSITION;
        case I2C_ID_2 :
            return _I2C2STAT_P_POSITION;
        case I2C_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _I2C_SLAVE_DATA_DETECT_POS(I2C_MODULE_ID i)
{
    switch (i) {
        case I2C_ID_1 :
            return _I2C1STAT_D_A_POSITION;
        case I2C_ID_2 :
            return _I2C2STAT_D_A_POSITION;
        case I2C_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _I2C_RCVR_OVERFLOW_POS(I2C_MODULE_ID i)
{
    switch (i) {
        case I2C_ID_1 :
            return _I2C1STAT_I2COV_POSITION;
        case I2C_ID_2 :
            return _I2C2STAT_I2COV_POSITION;
        case I2C_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _I2C_TRANS_OVERFLOW_POS(I2C_MODULE_ID i)
{
    switch (i) {
        case I2C_ID_1 :
            return _I2C1STAT_IWCOL_POSITION;
        case I2C_ID_2 :
            return _I2C2STAT_IWCOL_POSITION;
        case I2C_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _I2C_10BIT_ADDRESS_DETECT_POS(I2C_MODULE_ID i)
{
    switch (i) {
        case I2C_ID_1 :
            return _I2C1STAT_ADD10_POSITION;
        case I2C_ID_2 :
            return _I2C2STAT_ADD10_POSITION;
        case I2C_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _I2C_GENERAL_CALL_ADDR_DETECT_POS(I2C_MODULE_ID i)
{
    switch (i) {
        case I2C_ID_1 :
            return _I2C1STAT_GCSTAT_POSITION;
        case I2C_ID_2 :
            return _I2C2STAT_GCSTAT_POSITION;
        case I2C_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _I2C_ARBITRATION_LOSS_POS(I2C_MODULE_ID i)
{
    switch (i) {
        case I2C_ID_1 :
            return _I2C1STAT_BCL_POSITION;
        case I2C_ID_2 :
            return _I2C2STAT_BCL_POSITION;
        case I2C_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _I2C_TRANS_BYTE_COMPLETE_POS(I2C_MODULE_ID i)
{
    switch (i) {
        case I2C_ID_1 :
            return _I2C1STAT_TRSTAT_POSITION;
        case I2C_ID_2 :
            return _I2C2STAT_TRSTAT_POSITION;
        case I2C_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _I2C_TRANS_BYTE_ACK_POS(I2C_MODULE_ID i)
{
    switch (i) {
        case I2C_ID_1 :
            return _I2C1STAT_ACKSTAT_POSITION;
        case I2C_ID_2 :
            return _I2C2STAT_ACKSTAT_POSITION;
        case I2C_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _I2C_SLAVE_ADDRESS_SET_POS(I2C_MODULE_ID i)
{
    switch (i) {
        case I2C_ID_1 :
            return (SFR_DATA)0;
        case I2C_ID_2 :
            return (SFR_DATA)0;
        case I2C_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _I2C_SLAVE_MASK_POS(I2C_MODULE_ID i)
{
    switch (i) {
        case I2C_ID_1 :
            return (SFR_DATA)0;
        case I2C_ID_2 :
            return (SFR_DATA)0;
        case I2C_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _I2C_BAUD_RATE_POS(I2C_MODULE_ID i)
{
    switch (i) {
        case I2C_ID_1 :
            return (SFR_DATA)0;
        case I2C_ID_2 :
            return (SFR_DATA)0;
        case I2C_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _I2C_TRANS_BYTE_SEND_POS(I2C_MODULE_ID i)
{
    switch (i) {
        case I2C_ID_1 :
            return (SFR_DATA)0;
        case I2C_ID_2 :
            return (SFR_DATA)0;
        case I2C_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _I2C_RCVD_BYTE_GET_POS(I2C_MODULE_ID i)
{
    switch (i) {
        case I2C_ID_1 :
            return (SFR_DATA)0;
        case I2C_ID_2 :
            return (SFR_DATA)0;
        case I2C_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _I2C_MASTER_START_LEN(I2C_MODULE_ID i)
{
    switch (i) {
        case I2C_ID_1 :
            return _I2C1CON_SEN_LENGTH;
        case I2C_ID_2 :
            return _I2C2CON_SEN_LENGTH;
        case I2C_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _I2C_MASTER_START_REPEAT_LEN(I2C_MODULE_ID i)
{
    switch (i) {
        case I2C_ID_1 :
            return _I2C1CON_RSEN_LENGTH;
        case I2C_ID_2 :
            return _I2C2CON_RSEN_LENGTH;
        case I2C_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _I2C_MASTER_STOP_LEN(I2C_MODULE_ID i)
{
    switch (i) {
        case I2C_ID_1 :
            return _I2C1CON_PEN_LENGTH;
        case I2C_ID_2 :
            return _I2C2CON_PEN_LENGTH;
        case I2C_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _I2C_RECEIVE_1BYTE_LEN(I2C_MODULE_ID i)
{
    switch (i) {
        case I2C_ID_1 :
            return _I2C1CON_RCEN_LENGTH;
        case I2C_ID_2 :
            return _I2C2CON_RCEN_LENGTH;
        case I2C_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _I2C_RCVD_BYTE_ACK_ENABLE_LEN(I2C_MODULE_ID i)
{
    switch (i) {
        case I2C_ID_1 :
            return _I2C1CON_ACKEN_LENGTH;
        case I2C_ID_2 :
            return _I2C2CON_ACKEN_LENGTH;
        case I2C_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _I2C_RCVD_BYTE_ACK_DATA_LEN(I2C_MODULE_ID i)
{
    switch (i) {
        case I2C_ID_1 :
            return _I2C1CON_ACKDT_LENGTH;
        case I2C_ID_2 :
            return _I2C2CON_ACKDT_LENGTH;
        case I2C_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _I2C_CLOCK_STRETCH_ENABLE_LEN(I2C_MODULE_ID i)
{
    switch (i) {
        case I2C_ID_1 :
            return _I2C1CON_STREN_LENGTH;
        case I2C_ID_2 :
            return _I2C2CON_STREN_LENGTH;
        case I2C_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _I2C_GENERAL_CALL_ENABLE_LEN(I2C_MODULE_ID i)
{
    switch (i) {
        case I2C_ID_1 :
            return _I2C1CON_GCEN_LENGTH;
        case I2C_ID_2 :
            return _I2C2CON_GCEN_LENGTH;
        case I2C_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _I2C_SMBUS_ENABLE_LEN(I2C_MODULE_ID i)
{
    switch (i) {
        case I2C_ID_1 :
            return _I2C1CON_SMEN_LENGTH;
        case I2C_ID_2 :
            return _I2C2CON_SMEN_LENGTH;
        case I2C_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _I2C_HIGH_FREQUENCY_LEN(I2C_MODULE_ID i)
{
    switch (i) {
        case I2C_ID_1 :
            return _I2C1CON_DISSLW_LENGTH;
        case I2C_ID_2 :
            return _I2C2CON_DISSLW_LENGTH;
        case I2C_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _I2C_SLAVE_ADDRESS_10BIT_ENABLE_LEN(I2C_MODULE_ID i)
{
    switch (i) {
        case I2C_ID_1 :
            return _I2C1CON_A10M_LENGTH;
        case I2C_ID_2 :
            return _I2C2CON_A10M_LENGTH;
        case I2C_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _I2C_RESERVED_ADDR_PROTECT_LEN(I2C_MODULE_ID i)
{
    switch (i) {
        case I2C_ID_1 :
            return _I2C1CON_STRICT_LENGTH;
        case I2C_ID_2 :
            return _I2C2CON_STRICT_LENGTH;
        case I2C_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _I2C_SLAVE_CLOCK_HOLD_LEN(I2C_MODULE_ID i)
{
    switch (i) {
        case I2C_ID_1 :
            return _I2C1CON_SCLREL_LENGTH;
        case I2C_ID_2 :
            return _I2C2CON_SCLREL_LENGTH;
        case I2C_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _I2C_STOP_IN_IDLE_LEN(I2C_MODULE_ID i)
{
    switch (i) {
        case I2C_ID_1 :
            return _I2C1CON_SIDL_LENGTH;
        case I2C_ID_2 :
            return _I2C2CON_SIDL_LENGTH;
        case I2C_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _I2C_MODULE_ENABLE_LEN(I2C_MODULE_ID i)
{
    switch (i) {
        case I2C_ID_1 :
            return _I2C1CON_ON_LENGTH;
        case I2C_ID_2 :
            return _I2C2CON_ON_LENGTH;
        case I2C_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _I2C_TRANSMITTER_READY_LEN(I2C_MODULE_ID i)
{
    switch (i) {
        case I2C_ID_1 :
            return _I2C1STAT_TBF_LENGTH;
        case I2C_ID_2 :
            return _I2C2STAT_TBF_LENGTH;
        case I2C_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _I2C_RCVD_BYTE_AVAILABLE_LEN(I2C_MODULE_ID i)
{
    switch (i) {
        case I2C_ID_1 :
            return _I2C1STAT_RBF_LENGTH;
        case I2C_ID_2 :
            return _I2C2STAT_RBF_LENGTH;
        case I2C_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _I2C_SLAVE_READ_REQUEST_LEN(I2C_MODULE_ID i)
{
    switch (i) {
        case I2C_ID_1 :
            return _I2C1STAT_R_W_LENGTH;
        case I2C_ID_2 :
            return _I2C2STAT_R_W_LENGTH;
        case I2C_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _I2C_START_DETECT_LEN(I2C_MODULE_ID i)
{
    switch (i) {
        case I2C_ID_1 :
            return _I2C1STAT_S_LENGTH;
        case I2C_ID_2 :
            return _I2C2STAT_S_LENGTH;
        case I2C_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _I2C_STOP_DETECT_LEN(I2C_MODULE_ID i)
{
    switch (i) {
        case I2C_ID_1 :
            return _I2C1STAT_P_LENGTH;
        case I2C_ID_2 :
            return _I2C2STAT_P_LENGTH;
        case I2C_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _I2C_SLAVE_DATA_DETECT_LEN(I2C_MODULE_ID i)
{
    switch (i) {
        case I2C_ID_1 :
            return _I2C1STAT_D_A_LENGTH;
        case I2C_ID_2 :
            return _I2C2STAT_D_A_LENGTH;
        case I2C_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _I2C_RCVR_OVERFLOW_LEN(I2C_MODULE_ID i)
{
    switch (i) {
        case I2C_ID_1 :
            return _I2C1STAT_I2COV_LENGTH;
        case I2C_ID_2 :
            return _I2C2STAT_I2COV_LENGTH;
        case I2C_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _I2C_TRANS_OVERFLOW_LEN(I2C_MODULE_ID i)
{
    switch (i) {
        case I2C_ID_1 :
            return _I2C1STAT_IWCOL_LENGTH;
        case I2C_ID_2 :
            return _I2C2STAT_IWCOL_LENGTH;
        case I2C_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _I2C_10BIT_ADDRESS_DETECT_LEN(I2C_MODULE_ID i)
{
    switch (i) {
        case I2C_ID_1 :
            return _I2C1STAT_ADD10_LENGTH;
        case I2C_ID_2 :
            return _I2C2STAT_ADD10_LENGTH;
        case I2C_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _I2C_GENERAL_CALL_ADDR_DETECT_LEN(I2C_MODULE_ID i)
{
    switch (i) {
        case I2C_ID_1 :
            return _I2C1STAT_GCSTAT_LENGTH;
        case I2C_ID_2 :
            return _I2C2STAT_GCSTAT_LENGTH;
        case I2C_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _I2C_ARBITRATION_LOSS_LEN(I2C_MODULE_ID i)
{
    switch (i) {
        case I2C_ID_1 :
            return _I2C1STAT_BCL_LENGTH;
        case I2C_ID_2 :
            return _I2C2STAT_BCL_LENGTH;
        case I2C_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _I2C_TRANS_BYTE_COMPLETE_LEN(I2C_MODULE_ID i)
{
    switch (i) {
        case I2C_ID_1 :
            return _I2C1STAT_TRSTAT_LENGTH;
        case I2C_ID_2 :
            return _I2C2STAT_TRSTAT_LENGTH;
        case I2C_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _I2C_TRANS_BYTE_ACK_LEN(I2C_MODULE_ID i)
{
    switch (i) {
        case I2C_ID_1 :
            return _I2C1STAT_ACKSTAT_LENGTH;
        case I2C_ID_2 :
            return _I2C2STAT_ACKSTAT_LENGTH;
        case I2C_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _I2C_SLAVE_ADDRESS_SET_LEN(I2C_MODULE_ID i)
{
    switch (i) {
        case I2C_ID_1 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case I2C_ID_2 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case I2C_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _I2C_SLAVE_MASK_LEN(I2C_MODULE_ID i)
{
    switch (i) {
        case I2C_ID_1 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case I2C_ID_2 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case I2C_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _I2C_BAUD_RATE_LEN(I2C_MODULE_ID i)
{
    switch (i) {
        case I2C_ID_1 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case I2C_ID_2 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case I2C_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _I2C_TRANS_BYTE_SEND_LEN(I2C_MODULE_ID i)
{
    switch (i) {
        case I2C_ID_1 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case I2C_ID_2 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case I2C_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _I2C_RCVD_BYTE_GET_LEN(I2C_MODULE_ID i)
{
    switch (i) {
        case I2C_ID_1 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case I2C_ID_2 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case I2C_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

/* Section 2 - Feature variant inclusion */

#define PLIB_TEMPLATE PLIB_INLINE
#include "../templates/i2c_ClockStretching_Default.h"
#include "../templates/i2c_GeneralCall_Default.h"
#include "../templates/i2c_SMBus_Default.h"
#include "../templates/i2c_HighFrequency_Default.h"
#include "../templates/i2c_ReservedAddressProtect_Default.h"
#include "../templates/i2c_StopInIdle_Default.h"
#include "../templates/i2c_IPMI_Unsupported.h"
#include "../templates/i2c_ModuleEnable_Default.h"
#include "../templates/i2c_StartDetect_Default.h"
#include "../templates/i2c_StopDetect_Default.h"
#include "../templates/i2c_ArbitrationLoss_Default.h"
#include "../templates/i2c_BusIdle_Default.h"
#include "../templates/i2c_BaudRate_Default.h"
#include "../templates/i2c_SlaveAddress7Bit_Default.h"
#include "../templates/i2c_SlaveAddress10Bit_Default.h"
#include "../templates/i2c_SlaveAddressDetect_Default.h"
#include "../templates/i2c_GeneralCallAddressDetect_Default.h"
#include "../templates/i2c_SlaveMask_Default.h"
#include "../templates/i2c_SlaveReadRequest_Default.h"
#include "../templates/i2c_SlaveDataDetect_Default.h"
#include "../templates/i2c_SlaveClockHold_Default.h"
#include "../templates/i2c_MasterStart_Default.h"
#include "../templates/i2c_MasterStartRepeat_Default.h"
#include "../templates/i2c_MasterReceiverClock1Byte_Default.h"
#include "../templates/i2c_MasterStop_Default.h"
#include "../templates/i2c_TransmitterBusy_Default.h"
#include "../templates/i2c_TransmitterByteSend_Default.h"
#include "../templates/i2c_TransmitterByteComplete_Default.h"
#include "../templates/i2c_TransmitterByteAcknowledge_Default.h"
#include "../templates/i2c_TransmitterOverflow_Default.h"
#include "../templates/i2c_ReceivedByteAvailable_Default.h"
#include "../templates/i2c_ReceivedByteGet_Default.h"
#include "../templates/i2c_ReceivedByteAcknowledge_Default.h"
#include "../templates/i2c_ReceiverOverflow_Default.h"
#include "../templates/i2c_SlaveInterruptOnStop_Unsupported.h"
#include "../templates/i2c_SlaveInterruptOnStart_Unsupported.h"
#include "../templates/i2c_SlaveBufferOverwrite_Unsupported.h"
#include "../templates/i2c_DataLineHoldTime_Unsupported.h"
#include "../templates/i2c_SlaveBusCollisionDetect_Unsupported.h"
#include "../templates/i2c_SlaveAddressHoldEnable_Unsupported.h"
#include "../templates/i2c_SlaveDataHoldEnable_Unsupported.h"
#include "../templates/i2c_AcksequenceIsInProgress_Unsupported.h"

/* Section 3 - PLIB dispatch function definitions */

PLIB_INLINE_API void PLIB_I2C_SlaveClockStretchingEnable(I2C_MODULE_ID index)
{
    switch (index) {
        case I2C_ID_1 :
            I2C_SlaveClockStretchingEnable_Default(index);
            break;
        case I2C_ID_2 :
            I2C_SlaveClockStretchingEnable_Default(index);
            break;
        case I2C_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_I2C_SlaveClockStretchingDisable(I2C_MODULE_ID index)
{
    switch (index) {
        case I2C_ID_1 :
            I2C_SlaveClockStretchingDisable_Default(index);
            break;
        case I2C_ID_2 :
            I2C_SlaveClockStretchingDisable_Default(index);
            break;
        case I2C_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API bool PLIB_I2C_ExistsClockStretching(I2C_MODULE_ID index)
{
    switch (index) {
        case I2C_ID_1 :
            return I2C_ExistsClockStretching_Default(index);
        case I2C_ID_2 :
            return I2C_ExistsClockStretching_Default(index);
        case I2C_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API void PLIB_I2C_GeneralCallEnable(I2C_MODULE_ID index)
{
    switch (index) {
        case I2C_ID_1 :
            I2C_GeneralCallEnable_Default(index);
            break;
        case I2C_ID_2 :
            I2C_GeneralCallEnable_Default(index);
            break;
        case I2C_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_I2C_GeneralCallDisable(I2C_MODULE_ID index)
{
    switch (index) {
        case I2C_ID_1 :
            I2C_GeneralCallDisable_Default(index);
            break;
        case I2C_ID_2 :
            I2C_GeneralCallDisable_Default(index);
            break;
        case I2C_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API bool PLIB_I2C_ExistsGeneralCall(I2C_MODULE_ID index)
{
    switch (index) {
        case I2C_ID_1 :
            return I2C_ExistsGeneralCall_Default(index);
        case I2C_ID_2 :
            return I2C_ExistsGeneralCall_Default(index);
        case I2C_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API void PLIB_I2C_SMBEnable(I2C_MODULE_ID index)
{
    switch (index) {
        case I2C_ID_1 :
            I2C_SMBEnable_Default(index);
            break;
        case I2C_ID_2 :
            I2C_SMBEnable_Default(index);
            break;
        case I2C_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_I2C_SMBDisable(I2C_MODULE_ID index)
{
    switch (index) {
        case I2C_ID_1 :
            I2C_SMBDisable_Default(index);
            break;
        case I2C_ID_2 :
            I2C_SMBDisable_Default(index);
            break;
        case I2C_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API bool PLIB_I2C_ExistsSMBus(I2C_MODULE_ID index)
{
    switch (index) {
        case I2C_ID_1 :
            return I2C_ExistsSMBus_Default(index);
        case I2C_ID_2 :
            return I2C_ExistsSMBus_Default(index);
        case I2C_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API void PLIB_I2C_HighFrequencyEnable(I2C_MODULE_ID index)
{
    switch (index) {
        case I2C_ID_1 :
            I2C_HighFrequencyEnable_Default(index);
            break;
        case I2C_ID_2 :
            I2C_HighFrequencyEnable_Default(index);
            break;
        case I2C_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_I2C_HighFrequencyDisable(I2C_MODULE_ID index)
{
    switch (index) {
        case I2C_ID_1 :
            I2C_HighFrequencyDisable_Default(index);
            break;
        case I2C_ID_2 :
            I2C_HighFrequencyDisable_Default(index);
            break;
        case I2C_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API bool PLIB_I2C_ExistsHighFrequency(I2C_MODULE_ID index)
{
    switch (index) {
        case I2C_ID_1 :
            return I2C_ExistsHighFrequency_Default(index);
        case I2C_ID_2 :
            return I2C_ExistsHighFrequency_Default(index);
        case I2C_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API void PLIB_I2C_ReservedAddressProtectEnable(I2C_MODULE_ID index)
{
    switch (index) {
        case I2C_ID_1 :
            I2C_ReservedAddressProtectEnable_Default(index);
            break;
        case I2C_ID_2 :
            I2C_ReservedAddressProtectEnable_Default(index);
            break;
        case I2C_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_I2C_ReservedAddressProtectDisable(I2C_MODULE_ID index)
{
    switch (index) {
        case I2C_ID_1 :
            I2C_ReservedAddressProtectDisable_Default(index);
            break;
        case I2C_ID_2 :
            I2C_ReservedAddressProtectDisable_Default(index);
            break;
        case I2C_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API bool PLIB_I2C_ExistsReservedAddressProtect(I2C_MODULE_ID index)
{
    switch (index) {
        case I2C_ID_1 :
            return I2C_ExistsReservedAddressProtect_Default(index);
        case I2C_ID_2 :
            return I2C_ExistsReservedAddressProtect_Default(index);
        case I2C_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API void PLIB_I2C_StopInIdleEnable(I2C_MODULE_ID index)
{
    switch (index) {
        case I2C_ID_1 :
            I2C_StopInIdleEnable_Default(index);
            break;
        case I2C_ID_2 :
            I2C_StopInIdleEnable_Default(index);
            break;
        case I2C_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_I2C_StopInIdleDisable(I2C_MODULE_ID index)
{
    switch (index) {
        case I2C_ID_1 :
            I2C_StopInIdleDisable_Default(index);
            break;
        case I2C_ID_2 :
            I2C_StopInIdleDisable_Default(index);
            break;
        case I2C_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API bool PLIB_I2C_ExistsStopInIdle(I2C_MODULE_ID index)
{
    switch (index) {
        case I2C_ID_1 :
            return I2C_ExistsStopInIdle_Default(index);
        case I2C_ID_2 :
            return I2C_ExistsStopInIdle_Default(index);
        case I2C_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_I2C_IPMIEnable(I2C_MODULE_ID index)
{
    switch (index) {
        case I2C_ID_1 :
            I2C_IPMIEnable_Unsupported(index);
            break;
        case I2C_ID_2 :
            I2C_IPMIEnable_Unsupported(index);
            break;
        case I2C_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_I2C_IPMIDisable(I2C_MODULE_ID index)
{
    switch (index) {
        case I2C_ID_1 :
            I2C_IPMIDisable_Unsupported(index);
            break;
        case I2C_ID_2 :
            I2C_IPMIDisable_Unsupported(index);
            break;
        case I2C_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API bool PLIB_I2C_ExistsIPMI(I2C_MODULE_ID index)
{
    switch (index) {
        case I2C_ID_1 :
            return I2C_ExistsIPMI_Unsupported(index);
        case I2C_ID_2 :
            return I2C_ExistsIPMI_Unsupported(index);
        case I2C_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API void PLIB_I2C_Enable(I2C_MODULE_ID index)
{
    switch (index) {
        case I2C_ID_1 :
            I2C_Enable_Default(index);
            break;
        case I2C_ID_2 :
            I2C_Enable_Default(index);
            break;
        case I2C_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_I2C_Disable(I2C_MODULE_ID index)
{
    switch (index) {
        case I2C_ID_1 :
            I2C_Disable_Default(index);
            break;
        case I2C_ID_2 :
            I2C_Disable_Default(index);
            break;
        case I2C_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API bool PLIB_I2C_ExistsModuleEnable(I2C_MODULE_ID index)
{
    switch (index) {
        case I2C_ID_1 :
            return I2C_ExistsModuleEnable_Default(index);
        case I2C_ID_2 :
            return I2C_ExistsModuleEnable_Default(index);
        case I2C_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API bool PLIB_I2C_StartWasDetected(I2C_MODULE_ID index)
{
    switch (index) {
        case I2C_ID_1 :
            return I2C_StartWasDetected_Default(index);
        case I2C_ID_2 :
            return I2C_StartWasDetected_Default(index);
        case I2C_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API void PLIB_I2C_StartClear(I2C_MODULE_ID index)
{
    switch (index) {
        case I2C_ID_1 :
            I2C_StartClear_Default(index);
            break;
        case I2C_ID_2 :
            I2C_StartClear_Default(index);
            break;
        case I2C_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API bool PLIB_I2C_ExistsStartDetect(I2C_MODULE_ID index)
{
    switch (index) {
        case I2C_ID_1 :
            return I2C_ExistsStartDetect_Default(index);
        case I2C_ID_2 :
            return I2C_ExistsStartDetect_Default(index);
        case I2C_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API bool PLIB_I2C_StopWasDetected(I2C_MODULE_ID index)
{
    switch (index) {
        case I2C_ID_1 :
            return I2C_StopWasDetected_Default(index);
        case I2C_ID_2 :
            return I2C_StopWasDetected_Default(index);
        case I2C_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API void PLIB_I2C_StopClear(I2C_MODULE_ID index)
{
    switch (index) {
        case I2C_ID_1 :
            I2C_StopClear_Default(index);
            break;
        case I2C_ID_2 :
            I2C_StopClear_Default(index);
            break;
        case I2C_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API bool PLIB_I2C_ExistsStopDetect(I2C_MODULE_ID index)
{
    switch (index) {
        case I2C_ID_1 :
            return I2C_ExistsStopDetect_Default(index);
        case I2C_ID_2 :
            return I2C_ExistsStopDetect_Default(index);
        case I2C_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API bool PLIB_I2C_ArbitrationLossHasOccurred(I2C_MODULE_ID index)
{
    switch (index) {
        case I2C_ID_1 :
            return I2C_ArbitrationLossHasOccurred_Default(index);
        case I2C_ID_2 :
            return I2C_ArbitrationLossHasOccurred_Default(index);
        case I2C_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API void PLIB_I2C_ArbitrationLossClear(I2C_MODULE_ID index)
{
    switch (index) {
        case I2C_ID_1 :
            I2C_ArbitrationLossClear_Default(index);
            break;
        case I2C_ID_2 :
            I2C_ArbitrationLossClear_Default(index);
            break;
        case I2C_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API bool PLIB_I2C_ExistsArbitrationLoss(I2C_MODULE_ID index)
{
    switch (index) {
        case I2C_ID_1 :
            return I2C_ExistsArbitrationLoss_Default(index);
        case I2C_ID_2 :
            return I2C_ExistsArbitrationLoss_Default(index);
        case I2C_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API bool PLIB_I2C_BusIsIdle(I2C_MODULE_ID index)
{
    switch (index) {
        case I2C_ID_1 :
            return I2C_BusIsIdle_Default(index);
        case I2C_ID_2 :
            return I2C_BusIsIdle_Default(index);
        case I2C_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API bool PLIB_I2C_ExistsBusIsIdle(I2C_MODULE_ID index)
{
    switch (index) {
        case I2C_ID_1 :
            return I2C_ExistsBusIsIdle_Default(index);
        case I2C_ID_2 :
            return I2C_ExistsBusIsIdle_Default(index);
        case I2C_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API void PLIB_I2C_BaudRateSet(I2C_MODULE_ID index, uint32_t clockFrequencyHz, I2C_BAUD_RATE baudRate)
{
    switch (index) {
        case I2C_ID_1 :
            I2C_BaudRateSet_Default(index, clockFrequencyHz, baudRate);
            break;
        case I2C_ID_2 :
            I2C_BaudRateSet_Default(index, clockFrequencyHz, baudRate);
            break;
        case I2C_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API I2C_BAUD_RATE PLIB_I2C_BaudRateGet(I2C_MODULE_ID index, uint32_t clockFrequencyHz)
{
    switch (index) {
        case I2C_ID_1 :
            return I2C_BaudRateGet_Default(index, clockFrequencyHz);
        case I2C_ID_2 :
            return I2C_BaudRateGet_Default(index, clockFrequencyHz);
        case I2C_NUMBER_OF_MODULES :
        default :
            return (I2C_BAUD_RATE)0;
    }
}

PLIB_INLINE_API bool PLIB_I2C_ExistsBaudRate(I2C_MODULE_ID index)
{
    switch (index) {
        case I2C_ID_1 :
            return I2C_ExistsBaudRate_Default(index);
        case I2C_ID_2 :
            return I2C_ExistsBaudRate_Default(index);
        case I2C_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API void PLIB_I2C_SlaveAddress7BitSet(I2C_MODULE_ID index, uint8_t address)
{
    switch (index) {
        case I2C_ID_1 :
            I2C_SlaveAddress7BitSet_Default(index, address);
            break;
        case I2C_ID_2 :
            I2C_SlaveAddress7BitSet_Default(index, address);
            break;
        case I2C_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API uint8_t PLIB_I2C_SlaveAddress7BitGet(I2C_MODULE_ID index)
{
    switch (index) {
        case I2C_ID_1 :
            return I2C_SlaveAddress7BitGet_Default(index);
        case I2C_ID_2 :
            return I2C_SlaveAddress7BitGet_Default(index);
        case I2C_NUMBER_OF_MODULES :
        default :
            return (uint8_t)0;
    }
}

PLIB_INLINE_API bool PLIB_I2C_ExistsSlaveAddress7Bit(I2C_MODULE_ID index)
{
    switch (index) {
        case I2C_ID_1 :
            return I2C_ExistsSlaveAddress7Bit_Default(index);
        case I2C_ID_2 :
            return I2C_ExistsSlaveAddress7Bit_Default(index);
        case I2C_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API void PLIB_I2C_SlaveAddress10BitSet(I2C_MODULE_ID index, uint16_t address)
{
    switch (index) {
        case I2C_ID_1 :
            I2C_SlaveAddress10BitSet_Default(index, address);
            break;
        case I2C_ID_2 :
            I2C_SlaveAddress10BitSet_Default(index, address);
            break;
        case I2C_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API uint16_t PLIB_I2C_SlaveAddress10BitGet(I2C_MODULE_ID index)
{
    switch (index) {
        case I2C_ID_1 :
            return I2C_SlaveAddress10BitGet_Default(index);
        case I2C_ID_2 :
            return I2C_SlaveAddress10BitGet_Default(index);
        case I2C_NUMBER_OF_MODULES :
        default :
            return (uint16_t)0;
    }
}

PLIB_INLINE_API bool PLIB_I2C_SlaveAddressModeIs10Bits(I2C_MODULE_ID index)
{
    switch (index) {
        case I2C_ID_1 :
            return I2C_SlaveAddressModeIs10Bits_Default(index);
        case I2C_ID_2 :
            return I2C_SlaveAddressModeIs10Bits_Default(index);
        case I2C_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API bool PLIB_I2C_ExistsSlaveAddress10Bit(I2C_MODULE_ID index)
{
    switch (index) {
        case I2C_ID_1 :
            return I2C_ExistsSlaveAddress10Bit_Default(index);
        case I2C_ID_2 :
            return I2C_ExistsSlaveAddress10Bit_Default(index);
        case I2C_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API bool PLIB_I2C_SlaveAddress10BitWasDetected(I2C_MODULE_ID index)
{
    switch (index) {
        case I2C_ID_1 :
            return I2C_SlaveAddress10BitWasDetected_Default(index);
        case I2C_ID_2 :
            return I2C_SlaveAddress10BitWasDetected_Default(index);
        case I2C_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API bool PLIB_I2C_ExistsSlaveAddressDetect(I2C_MODULE_ID index)
{
    switch (index) {
        case I2C_ID_1 :
            return I2C_ExistsSlaveAddressDetect_Default(index);
        case I2C_ID_2 :
            return I2C_ExistsSlaveAddressDetect_Default(index);
        case I2C_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API bool PLIB_I2C_SlaveAddressIsGeneralCall(I2C_MODULE_ID index)
{
    switch (index) {
        case I2C_ID_1 :
            return I2C_SlaveAddressIsGeneralCall_Default(index);
        case I2C_ID_2 :
            return I2C_SlaveAddressIsGeneralCall_Default(index);
        case I2C_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API bool PLIB_I2C_ExistsGeneralCallAddressDetect(I2C_MODULE_ID index)
{
    switch (index) {
        case I2C_ID_1 :
            return I2C_ExistsGeneralCallAddressDetect_Default(index);
        case I2C_ID_2 :
            return I2C_ExistsGeneralCallAddressDetect_Default(index);
        case I2C_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API void PLIB_I2C_SlaveMask7BitSet(I2C_MODULE_ID index, uint8_t mask)
{
    switch (index) {
        case I2C_ID_1 :
            I2C_SlaveMask7BitSet_Default(index, mask);
            break;
        case I2C_ID_2 :
            I2C_SlaveMask7BitSet_Default(index, mask);
            break;
        case I2C_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API uint8_t PLIB_I2C_SlaveMask7BitGet(I2C_MODULE_ID index)
{
    switch (index) {
        case I2C_ID_1 :
            return I2C_SlaveMask7BitGet_Default(index);
        case I2C_ID_2 :
            return I2C_SlaveMask7BitGet_Default(index);
        case I2C_NUMBER_OF_MODULES :
        default :
            return (uint8_t)0;
    }
}

PLIB_INLINE_API void PLIB_I2C_SlaveMask10BitSet(I2C_MODULE_ID index, uint16_t mask)
{
    switch (index) {
        case I2C_ID_1 :
            I2C_SlaveMask10BitSet_Default(index, mask);
            break;
        case I2C_ID_2 :
            I2C_SlaveMask10BitSet_Default(index, mask);
            break;
        case I2C_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API uint16_t PLIB_I2C_SlaveMask10BitGet(I2C_MODULE_ID index)
{
    switch (index) {
        case I2C_ID_1 :
            return I2C_SlaveMask10BitGet_Default(index);
        case I2C_ID_2 :
            return I2C_SlaveMask10BitGet_Default(index);
        case I2C_NUMBER_OF_MODULES :
        default :
            return (uint16_t)0;
    }
}

PLIB_INLINE_API bool PLIB_I2C_ExistsSlaveMask(I2C_MODULE_ID index)
{
    switch (index) {
        case I2C_ID_1 :
            return I2C_ExistsSlaveMask_Default(index);
        case I2C_ID_2 :
            return I2C_ExistsSlaveMask_Default(index);
        case I2C_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API bool PLIB_I2C_SlaveReadIsRequested(I2C_MODULE_ID index)
{
    switch (index) {
        case I2C_ID_1 :
            return I2C_SlaveReadIsRequested_Default(index);
        case I2C_ID_2 :
            return I2C_SlaveReadIsRequested_Default(index);
        case I2C_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API bool PLIB_I2C_ExistsSlaveReadRequest(I2C_MODULE_ID index)
{
    switch (index) {
        case I2C_ID_1 :
            return I2C_ExistsSlaveReadRequest_Default(index);
        case I2C_ID_2 :
            return I2C_ExistsSlaveReadRequest_Default(index);
        case I2C_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API bool PLIB_I2C_SlaveDataIsDetected(I2C_MODULE_ID index)
{
    switch (index) {
        case I2C_ID_1 :
            return I2C_SlaveDataIsDetected_Default(index);
        case I2C_ID_2 :
            return I2C_SlaveDataIsDetected_Default(index);
        case I2C_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API bool PLIB_I2C_SlaveAddressIsDetected(I2C_MODULE_ID index)
{
    switch (index) {
        case I2C_ID_1 :
            return I2C_SlaveAddressIsDetected_Default(index);
        case I2C_ID_2 :
            return I2C_SlaveAddressIsDetected_Default(index);
        case I2C_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API bool PLIB_I2C_ExistsSlaveDataDetect(I2C_MODULE_ID index)
{
    switch (index) {
        case I2C_ID_1 :
            return I2C_ExistsSlaveDataDetect_Default(index);
        case I2C_ID_2 :
            return I2C_ExistsSlaveDataDetect_Default(index);
        case I2C_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API void PLIB_I2C_SlaveClockHold(I2C_MODULE_ID index)
{
    switch (index) {
        case I2C_ID_1 :
            I2C_SlaveClockHold_Default(index);
            break;
        case I2C_ID_2 :
            I2C_SlaveClockHold_Default(index);
            break;
        case I2C_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_I2C_SlaveClockRelease(I2C_MODULE_ID index)
{
    switch (index) {
        case I2C_ID_1 :
            I2C_SlaveClockRelease_Default(index);
            break;
        case I2C_ID_2 :
            I2C_SlaveClockRelease_Default(index);
            break;
        case I2C_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API bool PLIB_I2C_ExistsSlaveClockHold(I2C_MODULE_ID index)
{
    switch (index) {
        case I2C_ID_1 :
            return I2C_ExistsSlaveClockHold_Default(index);
        case I2C_ID_2 :
            return I2C_ExistsSlaveClockHold_Default(index);
        case I2C_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API void PLIB_I2C_MasterStart(I2C_MODULE_ID index)
{
    switch (index) {
        case I2C_ID_1 :
            I2C_MasterStart_Default(index);
            break;
        case I2C_ID_2 :
            I2C_MasterStart_Default(index);
            break;
        case I2C_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API bool PLIB_I2C_ExistsMasterStart(I2C_MODULE_ID index)
{
    switch (index) {
        case I2C_ID_1 :
            return I2C_ExistsMasterStart_Default(index);
        case I2C_ID_2 :
            return I2C_ExistsMasterStart_Default(index);
        case I2C_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API void PLIB_I2C_MasterStartRepeat(I2C_MODULE_ID index)
{
    switch (index) {
        case I2C_ID_1 :
            I2C_MasterStartRepeat_Default(index);
            break;
        case I2C_ID_2 :
            I2C_MasterStartRepeat_Default(index);
            break;
        case I2C_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API bool PLIB_I2C_ExistsMasterStartRepeat(I2C_MODULE_ID index)
{
    switch (index) {
        case I2C_ID_1 :
            return I2C_ExistsMasterStartRepeat_Default(index);
        case I2C_ID_2 :
            return I2C_ExistsMasterStartRepeat_Default(index);
        case I2C_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API void PLIB_I2C_MasterReceiverClock1Byte(I2C_MODULE_ID index)
{
    switch (index) {
        case I2C_ID_1 :
            I2C_MasterReceiverClock1Byte_Default(index);
            break;
        case I2C_ID_2 :
            I2C_MasterReceiverClock1Byte_Default(index);
            break;
        case I2C_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API bool PLIB_I2C_ExistsMasterReceiverClock1Byte(I2C_MODULE_ID index)
{
    switch (index) {
        case I2C_ID_1 :
            return I2C_ExistsMasterReceiverClock1Byte_Default(index);
        case I2C_ID_2 :
            return I2C_ExistsMasterReceiverClock1Byte_Default(index);
        case I2C_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API void PLIB_I2C_MasterStop(I2C_MODULE_ID index)
{
    switch (index) {
        case I2C_ID_1 :
            I2C_MasterStop_Default(index);
            break;
        case I2C_ID_2 :
            I2C_MasterStop_Default(index);
            break;
        case I2C_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API bool PLIB_I2C_ExistsMasterStop(I2C_MODULE_ID index)
{
    switch (index) {
        case I2C_ID_1 :
            return I2C_ExistsMasterStop_Default(index);
        case I2C_ID_2 :
            return I2C_ExistsMasterStop_Default(index);
        case I2C_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API bool PLIB_I2C_TransmitterIsBusy(I2C_MODULE_ID index)
{
    switch (index) {
        case I2C_ID_1 :
            return I2C_TransmitterIsBusy_Default(index);
        case I2C_ID_2 :
            return I2C_TransmitterIsBusy_Default(index);
        case I2C_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API bool PLIB_I2C_TransmitterIsReady(I2C_MODULE_ID index)
{
    switch (index) {
        case I2C_ID_1 :
            return I2C_TransmitterIsReady_Default(index);
        case I2C_ID_2 :
            return I2C_TransmitterIsReady_Default(index);
        case I2C_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API bool PLIB_I2C_ExistsTransmitterIsBusy(I2C_MODULE_ID index)
{
    switch (index) {
        case I2C_ID_1 :
            return I2C_ExistsTransmitterIsBusy_Default(index);
        case I2C_ID_2 :
            return I2C_ExistsTransmitterIsBusy_Default(index);
        case I2C_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API void PLIB_I2C_TransmitterByteSend(I2C_MODULE_ID index, uint8_t data)
{
    switch (index) {
        case I2C_ID_1 :
            I2C_TransmitterByteSend_Default(index, data);
            break;
        case I2C_ID_2 :
            I2C_TransmitterByteSend_Default(index, data);
            break;
        case I2C_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API bool PLIB_I2C_ExistsTransmitterByteSend(I2C_MODULE_ID index)
{
    switch (index) {
        case I2C_ID_1 :
            return I2C_ExistsTransmitterByteSend_Default(index);
        case I2C_ID_2 :
            return I2C_ExistsTransmitterByteSend_Default(index);
        case I2C_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API bool PLIB_I2C_TransmitterByteHasCompleted(I2C_MODULE_ID index)
{
    switch (index) {
        case I2C_ID_1 :
            return I2C_TransmitterByteHasCompleted_Default(index);
        case I2C_ID_2 :
            return I2C_TransmitterByteHasCompleted_Default(index);
        case I2C_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API bool PLIB_I2C_ExistsTransmitterByteComplete(I2C_MODULE_ID index)
{
    switch (index) {
        case I2C_ID_1 :
            return I2C_ExistsTransmitterByteComplete_Default(index);
        case I2C_ID_2 :
            return I2C_ExistsTransmitterByteComplete_Default(index);
        case I2C_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API bool PLIB_I2C_TransmitterByteWasAcknowledged(I2C_MODULE_ID index)
{
    switch (index) {
        case I2C_ID_1 :
            return I2C_TransmitterByteWasAcknowledged_Default(index);
        case I2C_ID_2 :
            return I2C_TransmitterByteWasAcknowledged_Default(index);
        case I2C_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API bool PLIB_I2C_ExistsTransmitterByteAcknowledge(I2C_MODULE_ID index)
{
    switch (index) {
        case I2C_ID_1 :
            return I2C_ExistsTransmitterByteAcknowledge_Default(index);
        case I2C_ID_2 :
            return I2C_ExistsTransmitterByteAcknowledge_Default(index);
        case I2C_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API bool PLIB_I2C_TransmitterOverflowHasOccurred(I2C_MODULE_ID index)
{
    switch (index) {
        case I2C_ID_1 :
            return I2C_TransmitterOverflowHasOccurred_Default(index);
        case I2C_ID_2 :
            return I2C_TransmitterOverflowHasOccurred_Default(index);
        case I2C_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API void PLIB_I2C_TransmitterOverflowClear(I2C_MODULE_ID index)
{
    switch (index) {
        case I2C_ID_1 :
            I2C_TransmitterOverflowClear_Default(index);
            break;
        case I2C_ID_2 :
            I2C_TransmitterOverflowClear_Default(index);
            break;
        case I2C_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API bool PLIB_I2C_ExistsTransmitterOverflow(I2C_MODULE_ID index)
{
    switch (index) {
        case I2C_ID_1 :
            return I2C_ExistsTransmitterOverflow_Default(index);
        case I2C_ID_2 :
            return I2C_ExistsTransmitterOverflow_Default(index);
        case I2C_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API bool PLIB_I2C_ReceivedByteIsAvailable(I2C_MODULE_ID index)
{
    switch (index) {
        case I2C_ID_1 :
            return I2C_ReceivedByteIsAvailable_Default(index);
        case I2C_ID_2 :
            return I2C_ReceivedByteIsAvailable_Default(index);
        case I2C_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API bool PLIB_I2C_ExistsReceivedByteAvailable(I2C_MODULE_ID index)
{
    switch (index) {
        case I2C_ID_1 :
            return I2C_ExistsReceivedByteAvailable_Default(index);
        case I2C_ID_2 :
            return I2C_ExistsReceivedByteAvailable_Default(index);
        case I2C_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API uint8_t PLIB_I2C_ReceivedByteGet(I2C_MODULE_ID index)
{
    switch (index) {
        case I2C_ID_1 :
            return I2C_ReceivedByteGet_Default(index);
        case I2C_ID_2 :
            return I2C_ReceivedByteGet_Default(index);
        case I2C_NUMBER_OF_MODULES :
        default :
            return (uint8_t)0;
    }
}

PLIB_INLINE_API bool PLIB_I2C_ExistsReceivedByteGet(I2C_MODULE_ID index)
{
    switch (index) {
        case I2C_ID_1 :
            return I2C_ExistsReceivedByteGet_Default(index);
        case I2C_ID_2 :
            return I2C_ExistsReceivedByteGet_Default(index);
        case I2C_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API void PLIB_I2C_ReceivedByteAcknowledge(I2C_MODULE_ID index, bool ack)
{
    switch (index) {
        case I2C_ID_1 :
            I2C_ReceivedByteAcknowledge_Default(index, ack);
            break;
        case I2C_ID_2 :
            I2C_ReceivedByteAcknowledge_Default(index, ack);
            break;
        case I2C_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API bool PLIB_I2C_ReceiverByteAcknowledgeHasCompleted(I2C_MODULE_ID index)
{
    switch (index) {
        case I2C_ID_1 :
            return I2C_ReceiverByteAcknowledgeHasCompleted_Default(index);
        case I2C_ID_2 :
            return I2C_ReceiverByteAcknowledgeHasCompleted_Default(index);
        case I2C_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API bool PLIB_I2C_MasterReceiverReadyToAcknowledge(I2C_MODULE_ID index)
{
    switch (index) {
        case I2C_ID_1 :
            return I2C_MasterReceiverReadyToAcknowledge_Default(index);
        case I2C_ID_2 :
            return I2C_MasterReceiverReadyToAcknowledge_Default(index);
        case I2C_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API bool PLIB_I2C_ExistsReceivedByteAcknowledge(I2C_MODULE_ID index)
{
    switch (index) {
        case I2C_ID_1 :
            return I2C_ExistsReceivedByteAcknowledge_Default(index);
        case I2C_ID_2 :
            return I2C_ExistsReceivedByteAcknowledge_Default(index);
        case I2C_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API bool PLIB_I2C_ReceiverOverflowHasOccurred(I2C_MODULE_ID index)
{
    switch (index) {
        case I2C_ID_1 :
            return I2C_ReceiverOverflowHasOccurred_Default(index);
        case I2C_ID_2 :
            return I2C_ReceiverOverflowHasOccurred_Default(index);
        case I2C_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API void PLIB_I2C_ReceiverOverflowClear(I2C_MODULE_ID index)
{
    switch (index) {
        case I2C_ID_1 :
            I2C_ReceiverOverflowClear_Default(index);
            break;
        case I2C_ID_2 :
            I2C_ReceiverOverflowClear_Default(index);
            break;
        case I2C_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API bool PLIB_I2C_ExistsReceiverOverflow(I2C_MODULE_ID index)
{
    switch (index) {
        case I2C_ID_1 :
            return I2C_ExistsReceiverOverflow_Default(index);
        case I2C_ID_2 :
            return I2C_ExistsReceiverOverflow_Default(index);
        case I2C_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_I2C_SlaveInterruptOnStopEnable(I2C_MODULE_ID index)
{
    switch (index) {
        case I2C_ID_1 :
            I2C_SlaveInterruptOnStopEnable_Unsupported(index);
            break;
        case I2C_ID_2 :
            I2C_SlaveInterruptOnStopEnable_Unsupported(index);
            break;
        case I2C_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_I2C_SlaveInterruptOnStopDisable(I2C_MODULE_ID index)
{
    switch (index) {
        case I2C_ID_1 :
            I2C_SlaveInterruptOnStopDisable_Unsupported(index);
            break;
        case I2C_ID_2 :
            I2C_SlaveInterruptOnStopDisable_Unsupported(index);
            break;
        case I2C_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API bool PLIB_I2C_ExistsSlaveInterruptOnStop(I2C_MODULE_ID index)
{
    switch (index) {
        case I2C_ID_1 :
            return I2C_ExistsSlaveInterruptOnStop_Unsupported(index);
        case I2C_ID_2 :
            return I2C_ExistsSlaveInterruptOnStop_Unsupported(index);
        case I2C_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_I2C_SlaveInterruptOnStartEnable(I2C_MODULE_ID index)
{
    switch (index) {
        case I2C_ID_1 :
            I2C_SlaveInterruptOnStartEnable_Unsupported(index);
            break;
        case I2C_ID_2 :
            I2C_SlaveInterruptOnStartEnable_Unsupported(index);
            break;
        case I2C_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_I2C_SlaveInterruptOnStartDisable(I2C_MODULE_ID index)
{
    switch (index) {
        case I2C_ID_1 :
            I2C_SlaveInterruptOnStartDisable_Unsupported(index);
            break;
        case I2C_ID_2 :
            I2C_SlaveInterruptOnStartDisable_Unsupported(index);
            break;
        case I2C_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API bool PLIB_I2C_ExistsSlaveInterruptOnStart(I2C_MODULE_ID index)
{
    switch (index) {
        case I2C_ID_1 :
            return I2C_ExistsSlaveInterruptOnStart_Unsupported(index);
        case I2C_ID_2 :
            return I2C_ExistsSlaveInterruptOnStart_Unsupported(index);
        case I2C_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_I2C_SlaveBufferOverwriteEnable(I2C_MODULE_ID index)
{
    switch (index) {
        case I2C_ID_1 :
            I2C_SlaveBufferOverwriteEnable_Unsupported(index);
            break;
        case I2C_ID_2 :
            I2C_SlaveBufferOverwriteEnable_Unsupported(index);
            break;
        case I2C_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_I2C_SlaveBufferOverwriteDisable(I2C_MODULE_ID index)
{
    switch (index) {
        case I2C_ID_1 :
            I2C_SlaveBufferOverwriteDisable_Unsupported(index);
            break;
        case I2C_ID_2 :
            I2C_SlaveBufferOverwriteDisable_Unsupported(index);
            break;
        case I2C_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API bool PLIB_I2C_ExistsSlaveBufferOverwrite(I2C_MODULE_ID index)
{
    switch (index) {
        case I2C_ID_1 :
            return I2C_ExistsSlaveBufferOverwrite_Unsupported(index);
        case I2C_ID_2 :
            return I2C_ExistsSlaveBufferOverwrite_Unsupported(index);
        case I2C_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_I2C_DataLineHoldTimeSet(I2C_MODULE_ID index, I2C_SDA_MIN_HOLD_TIME sdaHoldTimeNs)
{
    switch (index) {
        case I2C_ID_1 :
            I2C_DataLineHoldTimeSet_Unsupported(index, sdaHoldTimeNs);
            break;
        case I2C_ID_2 :
            I2C_DataLineHoldTimeSet_Unsupported(index, sdaHoldTimeNs);
            break;
        case I2C_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API bool PLIB_I2C_ExistsDataLineHoldTime(I2C_MODULE_ID index)
{
    switch (index) {
        case I2C_ID_1 :
            return I2C_ExistsDataLineHoldTime_Unsupported(index);
        case I2C_ID_2 :
            return I2C_ExistsDataLineHoldTime_Unsupported(index);
        case I2C_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_I2C_SlaveBusCollisionDetectEnable(I2C_MODULE_ID index)
{
    switch (index) {
        case I2C_ID_1 :
            I2C_SlaveBusCollisionDetectEnable_Unsupported(index);
            break;
        case I2C_ID_2 :
            I2C_SlaveBusCollisionDetectEnable_Unsupported(index);
            break;
        case I2C_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_I2C_SlaveBusCollisionDetectDisable(I2C_MODULE_ID index)
{
    switch (index) {
        case I2C_ID_1 :
            I2C_SlaveBusCollisionDetectDisable_Unsupported(index);
            break;
        case I2C_ID_2 :
            I2C_SlaveBusCollisionDetectDisable_Unsupported(index);
            break;
        case I2C_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API bool PLIB_I2C_ExistsSlaveBusCollisionDetect(I2C_MODULE_ID index)
{
    switch (index) {
        case I2C_ID_1 :
            return I2C_ExistsSlaveBusCollisionDetect_Unsupported(index);
        case I2C_ID_2 :
            return I2C_ExistsSlaveBusCollisionDetect_Unsupported(index);
        case I2C_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_I2C_SlaveAddressHoldEnable(I2C_MODULE_ID index)
{
    switch (index) {
        case I2C_ID_1 :
            I2C_SlaveAddressHoldEnable_Unsupported(index);
            break;
        case I2C_ID_2 :
            I2C_SlaveAddressHoldEnable_Unsupported(index);
            break;
        case I2C_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_I2C_SlaveAddressHoldDisable(I2C_MODULE_ID index)
{
    switch (index) {
        case I2C_ID_1 :
            I2C_SlaveAddressHoldDisable_Unsupported(index);
            break;
        case I2C_ID_2 :
            I2C_SlaveAddressHoldDisable_Unsupported(index);
            break;
        case I2C_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API bool PLIB_I2C_ExistsSlaveAddressHoldEnable(I2C_MODULE_ID index)
{
    switch (index) {
        case I2C_ID_1 :
            return I2C_ExistsSlaveAddressHoldEnable_Unsupported(index);
        case I2C_ID_2 :
            return I2C_ExistsSlaveAddressHoldEnable_Unsupported(index);
        case I2C_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_I2C_SlaveDataHoldEnable(I2C_MODULE_ID index)
{
    switch (index) {
        case I2C_ID_1 :
            I2C_SlaveDataHoldEnable_Unsupported(index);
            break;
        case I2C_ID_2 :
            I2C_SlaveDataHoldEnable_Unsupported(index);
            break;
        case I2C_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_I2C_SlaveDataHoldDisable(I2C_MODULE_ID index)
{
    switch (index) {
        case I2C_ID_1 :
            I2C_SlaveDataHoldDisable_Unsupported(index);
            break;
        case I2C_ID_2 :
            I2C_SlaveDataHoldDisable_Unsupported(index);
            break;
        case I2C_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API bool PLIB_I2C_ExistsSlaveDataHoldEnable(I2C_MODULE_ID index)
{
    switch (index) {
        case I2C_ID_1 :
            return I2C_ExistsSlaveDataHoldEnable_Unsupported(index);
        case I2C_ID_2 :
            return I2C_ExistsSlaveDataHoldEnable_Unsupported(index);
        case I2C_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API bool _PLIB_UNSUPPORTED PLIB_I2C_AcksequenceIsInProgress(I2C_MODULE_ID index)
{
    switch (index) {
        case I2C_ID_1 :
            return I2C_AcksequenceIsInProgress_Unsupported(index);
        case I2C_ID_2 :
            return I2C_AcksequenceIsInProgress_Unsupported(index);
        case I2C_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API bool PLIB_I2C_ExistsAcksequenceProgress(I2C_MODULE_ID index)
{
    switch (index) {
        case I2C_ID_1 :
            return I2C_ExistsAcksequenceProgress_Unsupported(index);
        case I2C_ID_2 :
            return I2C_ExistsAcksequenceProgress_Unsupported(index);
        case I2C_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

#endif

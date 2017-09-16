/*******************************************************************************
  I2C Peripheral Library Template Implementation

  File Name:
    i2c_SlaveAddress7Bit_Default.h

  Summary:
    I2C PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : SlaveAddress7Bit
    and its Variant : Default
    For following APIs :
        PLIB_I2C_SlaveAddress7BitSet
        PLIB_I2C_SlaveAddress7BitGet
        PLIB_I2C_ExistsSlaveAddress7Bit

*******************************************************************************/

//DOM-IGNORE-BEGIN
/*******************************************************************************
Copyright (c) 2012 released Microchip Technology Inc.  All rights reserved.

Microchip licenses to you the right to use, modify, copy and distribute
Software only when embedded on a Microchip microcontroller or digital signal
controller that is integrated into your product or third party product
(pursuant to the sublicense terms in the accompanying license agreement).

You should refer to the license agreement accompanying this Software for
additional information regarding your rights and obligations.

SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF
MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER
CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR
OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR
CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF
SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
(INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.
*******************************************************************************/

//DOM-IGNORE-END

#ifndef _I2C_SLAVEADDRESS7BIT_DEFAULT_H
#define _I2C_SLAVEADDRESS7BIT_DEFAULT_H

//******************************************************************************
/* Routines available for accessing VREGS, MASKS, POS, LEN are 

  VREGs: 
    _I2C_SLAVE_ADDRESS_SET_VREG(index)
    _I2C_SLAVE_ADDRESS_10BIT_ENABLE_VREG(index)

  MASKs: 
    _I2C_SLAVE_ADDRESS_SET_MASK(index)
    _I2C_SLAVE_ADDRESS_10BIT_ENABLE_MASK(index)

  POSs: 
    _I2C_SLAVE_ADDRESS_SET_POS(index)
    _I2C_SLAVE_ADDRESS_10BIT_ENABLE_POS(index)

  LENs: 
    _I2C_SLAVE_ADDRESS_SET_LEN(index)
    _I2C_SLAVE_ADDRESS_10BIT_ENABLE_LEN(index)

*/


//******************************************************************************
/* Function :  I2C_SlaveAddress7BitSet_Default

  Summary:
    Implements Default variant of PLIB_I2C_SlaveAddress7BitSet 

  Description:
    This template implements the Default variant of the PLIB_I2C_SlaveAddress7BitSet function.
*/

PLIB_TEMPLATE void I2C_SlaveAddress7BitSet_Default( I2C_MODULE_ID index , uint8_t address )
{
    _SFR_WRITE(_I2C_SLAVE_ADDRESS_SET_VREG(index), address);
    /* Configure for 7-bit address */
    _SFR_BIT_CLEAR(_I2C_SLAVE_ADDRESS_10BIT_ENABLE_VREG(index),
                     _I2C_SLAVE_ADDRESS_10BIT_ENABLE_POS(index) );
}


//******************************************************************************
/* Function :  I2C_SlaveAddress7BitGet_Default

  Summary:
    Implements Default variant of PLIB_I2C_SlaveAddress7BitGet 

  Description:
    This template implements the Default variant of the PLIB_I2C_SlaveAddress7BitGet function.
*/

PLIB_TEMPLATE uint8_t I2C_SlaveAddress7BitGet_Default( I2C_MODULE_ID index )
{
    return _SFR_READ(_I2C_SLAVE_ADDRESS_SET_VREG(index));
}


//******************************************************************************
/* Function :  I2C_ExistsSlaveAddress7Bit_Default

  Summary:
    Implements Default variant of PLIB_I2C_ExistsSlaveAddress7Bit

  Description:
    This template implements the Default variant of the PLIB_I2C_ExistsSlaveAddress7Bit function.
*/

#define PLIB_I2C_ExistsSlaveAddress7Bit PLIB_I2C_ExistsSlaveAddress7Bit
PLIB_TEMPLATE bool I2C_ExistsSlaveAddress7Bit_Default( I2C_MODULE_ID index )
{
    return true;
}


#endif /*_I2C_SLAVEADDRESS7BIT_DEFAULT_H*/

/******************************************************************************
 End of File
*/


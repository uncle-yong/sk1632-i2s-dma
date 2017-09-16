/*******************************************************************************
  I2C Peripheral Library Template Implementation

  File Name:
    i2c_SlaveDataDetect_Default.h

  Summary:
    I2C PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : SlaveDataDetect
    and its Variant : Default
    For following APIs :
        PLIB_I2C_SlaveDataIsDetected
        PLIB_I2C_SlaveAddressIsDetected
        PLIB_I2C_ExistsSlaveDataDetect

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

#ifndef _I2C_SLAVEDATADETECT_DEFAULT_H
#define _I2C_SLAVEDATADETECT_DEFAULT_H

//******************************************************************************
/* Routines available for accessing VREGS, MASKS, POS, LEN are 

  VREGs: 
    _I2C_SLAVE_DATA_DETECT_VREG(index)

  MASKs: 
    _I2C_SLAVE_DATA_DETECT_MASK(index)

  POSs: 
    _I2C_SLAVE_DATA_DETECT_POS(index)

  LENs: 
    _I2C_SLAVE_DATA_DETECT_LEN(index)

*/


//******************************************************************************
/* Function :  I2C_SlaveDataIsDetected_Default

  Summary:
    Implements Default variant of PLIB_I2C_SlaveDataIsDetected 

  Description:
    This template implements the Default variant of the PLIB_I2C_SlaveDataIsDetected function.
*/

PLIB_TEMPLATE bool I2C_SlaveDataIsDetected_Default( I2C_MODULE_ID index )
{
    return _SFR_BIT_READ(_I2C_SLAVE_DATA_DETECT_VREG(index),
                             _I2C_SLAVE_DATA_DETECT_POS(index) );
}


//******************************************************************************
/* Function :  I2C_SlaveAddressIsDetected_Default

  Summary:
    Implements Default variant of PLIB_I2C_SlaveAddressIsDetected 

  Description:
    This template implements the Default variant of the PLIB_I2C_SlaveAddressIsDetected function.
*/

PLIB_TEMPLATE bool I2C_SlaveAddressIsDetected_Default( I2C_MODULE_ID index )
{
     return !(_SFR_BIT_READ(_I2C_SLAVE_DATA_DETECT_VREG(index),
                             _I2C_SLAVE_DATA_DETECT_POS(index)) );
}


//******************************************************************************
/* Function :  I2C_ExistsSlaveDataDetect_Default

  Summary:
    Implements Default variant of PLIB_I2C_ExistsSlaveDataDetect

  Description:
    This template implements the Default variant of the PLIB_I2C_ExistsSlaveDataDetect function.
*/

#define PLIB_I2C_ExistsSlaveDataDetect PLIB_I2C_ExistsSlaveDataDetect
PLIB_TEMPLATE bool I2C_ExistsSlaveDataDetect_Default( I2C_MODULE_ID index )
{
    return true;
}


#endif /*_I2C_SLAVEDATADETECT_DEFAULT_H*/

/******************************************************************************
 End of File
*/


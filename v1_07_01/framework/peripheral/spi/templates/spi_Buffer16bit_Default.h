/*******************************************************************************
  SPI Peripheral Library Template Implementation

  File Name:
    spi_Buffer16bit_Default.h

  Summary:
    SPI PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : Buffer16bit
    and its Variant : Default
    For following APIs :
        PLIB_SPI_BufferRead16bit
        PLIB_SPI_BufferWrite16bit
        PLIB_SPI_Exists16bitBuffer

*******************************************************************************/

//DOM-IGNORE-BEGIN
/*******************************************************************************
Copyright (c) 2013 released Microchip Technology Inc.  All rights reserved.

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

#ifndef _SPI_BUFFER16BIT_DEFAULT_H
#define _SPI_BUFFER16BIT_DEFAULT_H

//******************************************************************************
/* Routines available for accessing VREGS, MASKS, POS, LEN are 

  VREGs: 
    _SPI_BUFFER_VREG(index)

  MASKs: 
    _SPI_BUFFER_MASK(index)

  POSs: 
    _SPI_BUFFER_POS(index)

  LENs: 
    _SPI_BUFFER_LEN(index)

*/


//******************************************************************************
/* Function :  SPI_BufferRead16bit_Default

  Summary:
    Implements Default variant of PLIB_SPI_BufferRead16bit 

  Description:
    This template implements the Default variant of the PLIB_SPI_BufferRead16bit function.
*/

PLIB_TEMPLATE uint16_t SPI_BufferRead16bit_Default( SPI_MODULE_ID index )
{
    return( ( uint16_t )_SFR_READ( _SPI_BUFFER_VREG(index) ) );
}


//******************************************************************************
/* Function :  SPI_BufferWrite16bit_Default

  Summary:
    Implements Default variant of PLIB_SPI_BufferWrite16bit 

  Description:
    This template implements the Default variant of the PLIB_SPI_BufferWrite16bit function.
*/

PLIB_TEMPLATE void SPI_BufferWrite16bit_Default( SPI_MODULE_ID index , uint16_t data )
{
    _SFR_WRITE( _SPI_BUFFER_VREG(index),
                (uint16_t)(data) );
}


//******************************************************************************
/* Function :  SPI_Exists16bitBuffer_Default

  Summary:
    Implements Default variant of PLIB_SPI_Exists16bitBuffer

  Description:
    This template implements the Default variant of the PLIB_SPI_Exists16bitBuffer function.
*/

#define PLIB_SPI_Exists16bitBuffer PLIB_SPI_Exists16bitBuffer
PLIB_TEMPLATE bool SPI_Exists16bitBuffer_Default( SPI_MODULE_ID index )
{
    return true;
}


#endif /*_SPI_BUFFER16BIT_DEFAULT_H*/

/******************************************************************************
 End of File
*/

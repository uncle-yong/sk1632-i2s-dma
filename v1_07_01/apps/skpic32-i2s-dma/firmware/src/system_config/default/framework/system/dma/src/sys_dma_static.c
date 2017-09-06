/*******************************************************************************
  DMA System Service Functions for Static Single Instance System Service

  Company:
    Microchip Technology Inc.

  File Name:
    drv_dma_static.c

  Summary:
    DMA System Service implementation for the static single instance System Service.

  Description:
    The DMA device System Service provides a simple interface to manage the DMA
    modules on Microchip microcontrollers.
    
  Remarks:
    Static interfaces incorporate the System Service instance number within the names
    of the routines, eliminating the need for an object ID or object handle.
    Static single-open interfaces also eliminate the need for the open handle.
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

SOFTWARE AND DOCUMENTATION ARE PROVIDED AS IS WITHOUT WARRANTY OF ANY KIND,
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


// *****************************************************************************
// *****************************************************************************
// Header Includes
// *****************************************************************************
// *****************************************************************************
#include "framework/system/dma/sys_dma_static.h"

// *****************************************************************************
// *****************************************************************************
// Section: static functions
// *****************************************************************************
// *****************************************************************************
SYS_MODULE_OBJ SYS_DMA_Initialize(const SYS_MODULE_INIT * const init)
{
   /* Disable the DMA module */
   PLIB_DMA_Disable(DMA_ID_0);

   /* Set the priority levels for the DMA Channels */
   PLIB_DMA_ChannelXPrioritySelect(DMA_ID_0, DMA_CHANNEL_0, 0);
   /* Enable the DMA module */
   PLIB_DMA_Enable(DMA_ID_0);
   
   return (SYS_MODULE_OBJ)0;
}

// *****************************************************************************
// *****************************************************************************
// Section: DMA Channel 0 functions
// *****************************************************************************
// *****************************************************************************	

void SYS_DMA_Channel0TransferAdd(void)
{
   
   /* Set the source and destinaton addresses (addresses are converted from virtual to physical) */
   PLIB_DMA_ChannelXSourceStartAddressSet(DMA_ID_0, DMA_CHANNEL_0, 0);
   PLIB_DMA_ChannelXDestinationStartAddressSet(DMA_ID_0, DMA_CHANNEL_0, 0);

   /* Set the source and destination sizes */
   PLIB_DMA_ChannelXSourceSizeSet(DMA_ID_0, DMA_CHANNEL_0, 2);
   PLIB_DMA_ChannelXDestinationSizeSet(DMA_ID_0, DMA_CHANNEL_0, 2);

   /* Set the number of bytes per transfer */
   PLIB_DMA_ChannelXCellSizeSet(DMA_ID_0, DMA_CHANNEL_0, 2);
}

void SYS_DMA_Channel0Enable(void)
{
   /* Enable DMA channel 0 */
   PLIB_DMA_ChannelXEnable(DMA_ID_0, DMA_CHANNEL_0);
}

void SYS_DMA_Channel0Setup(SYS_DMA_CHANNEL_OP_MODE modeEnable)
{

    /* Pattern match Abort */
    if(SYS_DMA_CHANNEL_OP_MODE_MATCH_ABORT & modeEnable)
    {
        PLIB_DMA_ChannelXTriggerEnable( DMA_ID_0,DMA_CHANNEL_0,DMA_CHANNEL_TRIGGER_PATTERN_MATCH_ABORT);
    }

    /* Channel chaining mode */
    if(SYS_DMA_CHANNEL_OP_MODE_CHAIN_LOW & modeEnable)
    {
        PLIB_DMA_ChannelXChainEnable( DMA_ID_0, DMA_CHANNEL_0);
    }

    /* Auto Enable mode */
    if(SYS_DMA_CHANNEL_OP_MODE_AUTO & modeEnable)
    {
        PLIB_DMA_ChannelXAutoEnable( DMA_ID_0, DMA_CHANNEL_0);
    }

    /* CRC Enable */
    if(SYS_DMA_CHANNEL_OP_MODE_CRC & modeEnable)
    {
        PLIB_DMA_CRCEnable(DMA_ID_0);
    }

   /* DMA transfer to start */
   PLIB_DMA_ChannelXTriggerEnable(DMA_ID_0, DMA_CHANNEL_0, DMA_CHANNEL_TRIGGER_TRANSFER_START);
   PLIB_DMA_ChannelXStartIRQSet(DMA_ID_0, DMA_CHANNEL_0, DMA_TRIGGER_SOURCE_NONE);
}

bool SYS_DMA_Channel0IsBusy(void)
{
    bool isBusy;

    isBusy = false;
#if defined(PLIB_DMA_ExistsChannelXBusy)
    if(true == PLIB_DMA_ExistsChannelXBusy(DMA_ID_0))
    {
        if(true == PLIB_DMA_ChannelXBusyIsBusy( DMA_ID_0,DMA_CHANNEL_0))
        {
            isBusy = true;
        }
    }
#endif
    return isBusy;
}

void SYS_DMA_Channel0ForceAbort(void)
{
   PLIB_DMA_AbortTransferSet(DMA_ID_0, DMA_CHANNEL_0);
}

void SYS_DMA_Channel0ForceStart(void)
{
   PLIB_DMA_StartTransferSet(DMA_ID_0, DMA_CHANNEL_0);
}

void SYS_DMA_Channel0Disable(void)
{
   PLIB_DMA_ChannelXDisable(DMA_ID_0, DMA_CHANNEL_0);
}

uint32_t SYS_DMA_Channel0GetCRC(void)
{
    uint32_t crcData;
#if defined (PLIB_DMA_ExistsCRCData)
    if(true == PLIB_DMA_ExistsCRCData(DMA_ID_0))
    {
        crcData = PLIB_DMA_CRCDataRead(DMA_ID_0);
    }
#endif
    return crcData;
}

void SYS_DMA_Channel0SetCRC(SYS_DMA_CHANNEL_OPERATION_MODE_CRC crc)
{
    /* Enable CRC for the Channel and the type */
#if defined (PLIB_DMA_ExistsCRCChannel)
    if(true == PLIB_DMA_ExistsCRCChannel(DMA_ID_0))
    {
        PLIB_DMA_CRCChannelSelect(DMA_ID_0, DMA_CHANNEL_0);  
    }
#endif

#if defined (PLIB_DMA_ExistsCRCType)
    if(true == PLIB_DMA_ExistsCRCType(DMA_ID_0))
    {
        PLIB_DMA_CRCTypeSet(DMA_ID_0, crc.type);
    }
#endif

    /* Setup the polynomial length */
    PLIB_DMA_CRCPolynomialLengthSet(DMA_ID_0, crc.polyLength);
    
    /* Setup the bit order and byte order */
#if defined (PLIB_DMA_ExistsCRCBitOrder)
    if(true == PLIB_DMA_ExistsCRCBitOrder(DMA_ID_0))
    {
        PLIB_DMA_CRCBitOrderSelect(DMA_ID_0, crc.bitOrder);
    }
#endif    

#if defined (PLIB_DMA_ExistsCRCByteOrder)
    if(true == PLIB_DMA_ExistsCRCByteOrder(DMA_ID_0))
    {
        PLIB_DMA_CRCByteOrderSelect(DMA_ID_0, crc.byteOrder);
    }
#endif

    /* BYTE/WORD order reallignment */
#if defined (PLIB_DMA_ExistsCRCWriteByteOrder)
    if(true == PLIB_DMA_ExistsCRCWriteByteOrder(DMA_ID_0))
    {
        if(SYS_DMA_CRC_WRITE_ORDER_MAINTAIN == crc.writeOrder)
        {
            PLIB_DMA_CRCWriteByteOrderMaintain(DMA_ID_0);
        }
        else if(SYS_DMA_CRC_WRITE_ORDER_CHANGE == crc.writeOrder)
        {
            PLIB_DMA_CRCWriteByteOrderAlter(DMA_ID_0);
        }
        else
        {
        }
    }
#endif

    /* CRC Data */
#if defined (PLIB_DMA_ExistsCRCData)
    if(true == PLIB_DMA_ExistsCRCData(DMA_ID_0))
    {
        PLIB_DMA_CRCDataWrite(DMA_ID_0, crc.data);
    }
#endif


    /* Enable CRC XOR */
#if defined (PLIB_DMA_ExistsCRCXOREnable)
    if(true == PLIB_DMA_ExistsCRCXOREnable(DMA_ID_0))
    {
        PLIB_DMA_CRCXOREnableSet(DMA_ID_0, crc.xorBitMask);
    }
#endif

}

void SYS_DMA_Channel0SetupMatchAbortMode( uint16_t pattern,
                                         DMA_PATTERN_LENGTH length,
                                         SYS_DMA_CHANNEL_IGNORE_MATCH ignore,
                                         uint8_t ignorePattern )
{

    /* Set the length for the pattern match */
#if defined(PLIB_DMA_ExistsChannelXPatternLength)
    if(true == PLIB_DMA_ExistsChannelXPatternLength(DMA_ID_0))
    {
        PLIB_DMA_ChannelXPatternLengthSet(DMA_ID_0,DMA_CHANNEL_0,length);
    }
#endif
    /* Set the pattern for the pattern match */  
    PLIB_DMA_ChannelXPatternDataSet(DMA_ID_0,DMA_CHANNEL_0,pattern);

if(SYS_DMA_CHANNEL_IGNORE_MATCH_ENABLE == ignore)
{
    #if defined(PLIB_DMA_ExistsChannelXPatternIgnoreByte)    
        if(true == PLIB_DMA_ExistsChannelXPatternIgnoreByte(DMA_ID_0))
        {
            /* Enable the ignore byte and the pattern */    
            PLIB_DMA_ChannelXPatternIgnoreByteEnable(DMA_ID_0,DMA_CHANNEL_0); 
        }
    #endif  
    #if defined(PLIB_DMA_ExistsChannelXPatternIgnore)    
        if(true == PLIB_DMA_ExistsChannelXPatternIgnore(DMA_ID_0))
        {  
            PLIB_DMA_ChannelXPatternIgnoreSet(DMA_ID_0,DMA_CHANNEL_0,ignorePattern);
        }
    #endif
}
}

 
/*******************************************************************************
 End of File
*/

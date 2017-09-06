/*******************************************************************************
  DMA System Service Interface Declarations for Static Single Instance System Service

  Company:
    Microchip Technology Inc.

  File Name:
    drv_dma_static.h

  Summary:
    DMA driver interface declarations for the static single instance System Service.

  Description:
    The DMA System Service provides a simple interface to manage the DMA
    modules on Microchip microcontrollers. This file defines the interface
    Declarations for the DMA.
    
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


#ifndef _DRV_DMA_STATIC_H
#define _DRV_DMA_STATIC_H

#include "system/dma/sys_dma.h"
#include "peripheral/int/plib_int.h"


// *****************************************************************************
// *****************************************************************************
// Section: Interface Headers for Instance for the static System Service
// *****************************************************************************
// *****************************************************************************

void SYS_DMA_Channel0TransferAdd(void);

void SYS_DMA_Channel0Enable(void);

void SYS_DMA_Channel0Setup(SYS_DMA_CHANNEL_OP_MODE modeEnable);

void SYS_DMA_Channel0ForceStart(void);


bool SYS_DMA_Channel0IsBusy(void);
void SYS_DMA_Channel0ForceAbort(void);
void SYS_DMA_Channel0ForceStart(void);
void SYS_DMA_Channel0Disable(void);
void SYS_DMA_Suspend(void);
void SYS_DMA_Resume(void);
bool SYS_DMA_IsBusy(void);
uint32_t SYS_DMA_Channel0GetCRC(void);
void SYS_DMA_Channel0SetCRC(SYS_DMA_CHANNEL_OPERATION_MODE_CRC crc);
void SYS_DMA_Channel0SetupMatchAbortMode( uint16_t pattern,
                                         DMA_PATTERN_LENGTH length,
                                         SYS_DMA_CHANNEL_IGNORE_MATCH ignore,
                                         uint8_t ignorePattern );

#endif // #ifndef _DRV_DMA_STATIC_H

/*******************************************************************************
 End of File
*/

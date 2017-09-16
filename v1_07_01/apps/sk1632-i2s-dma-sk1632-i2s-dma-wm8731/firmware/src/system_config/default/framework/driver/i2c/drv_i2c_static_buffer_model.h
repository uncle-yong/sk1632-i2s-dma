/*******************************************************************************
  I2C Driver Interface Declarations for Static Single Instance Driver

  Company:
    Microchip Technology Inc.

  File Name:
    drv_i2c_static_buffer_model.h

  Summary:
    I2C driver interface declarations for the static single instance driver.

  Description:
    The I2C device driver provides a simple interface to manage the I2C
    modules on Microchip microcontrollers. This file defines the interface
    Declarations for the I2C driver.
    
  Remarks:
    Static interfaces incorporate the driver instance number within the names
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

#ifndef _DRV_I2C_STATIC_BUFFER_MODEL_H
#define _DRV_I2C_STATIC_BUFFER_MODEL_H

//DOM-IGNORE-END

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  

    extern "C" {

#endif
// DOM-IGNORE-END 

#include "peripheral/i2c/plib_i2c.h"
#include "driver/i2c/src/drv_i2c_local.h"



// *****************************************************************************
// *****************************************************************************
// Section: Interface Headers for Instance 0 for the static driver
// *****************************************************************************
// *****************************************************************************

void DRV_I2C0_Initialize(void);

void DRV_I2C0_DeInitialize(void);

void DRV_I2C0_Tasks(void);


// *****************************************************************************
// Section: Instance 0 Buffer Transfer function (Master/Slave)
// *****************************************************************************

DRV_I2C_BUFFER_HANDLE DRV_I2C0_Transmit ( uint16_t deviceaddress,
                                                        void *txBuffer,
                                                        size_t size,
                                                        void * context);


DRV_I2C_BUFFER_HANDLE DRV_I2C0_Receive (  uint16_t deviceaddress,
                                                        void *rxBuffer,
                                                        size_t size,
                                                        void * context); 
                                    
DRV_I2C_BUFFER_HANDLE DRV_I2C0_TransmitThenReceive (  uint16_t deviceaddress,
                                                                    void *txBuffer,
                                                                    size_t wsize,
                                                                    void *rxBuffer,
                                                                    size_t size,
                                                                    void * context); 
                                                                   
DRV_I2C_BUFFER_HANDLE DRV_I2C0_TransmitForced (   uint16_t deviceaddress,
                                                                void *txBuffer,
                                                                size_t size,
                                                                DRV_I2C_BUS_ERROR_EVENT eventFlag,
                                                                void * context);

// *****************************************************************************
// Section: Instance 0 Buffer status function
// *****************************************************************************

DRV_I2C_BUFFER_EVENT DRV_I2C0_TransferStatusGet ( DRV_I2C_BUFFER_HANDLE bufferHandle );


// *****************************************************************************
// Section: Instance 0 Number of Bytes transferred
// *****************************************************************************

uint32_t DRV_I2C0_BytesTransferred ( DRV_I2C_BUFFER_HANDLE bufferHandle );


// *****************************************************************************
// Section: Buffer Event Callback function 
// *****************************************************************************

void DRV_I2C0_BufferEventHandlerSet (const DRV_I2C_BUFFER_EVENT_HANDLER eventHandler,
                    const uintptr_t context );


// DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
// DOM-IGNORE-END

#endif // #ifndef _DRV_I2C_STATIC_BUFFER_MODEL_H

/*******************************************************************************
 End of File
*/

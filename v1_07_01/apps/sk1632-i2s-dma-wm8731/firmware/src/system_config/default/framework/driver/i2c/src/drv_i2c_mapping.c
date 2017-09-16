/*******************************************************************************
  I2C Driver Interface Mapping Dynamic APIs to Static APIs           

  Company:
    Microchip Technology Inc.

  File Name:
    drv_i2c_mapping.h

  Summary:
    This file allows maintaining a single set of APIs for all I2C transactions  
    by making the type of implementation transparent to the application. In case
    where static implementation of I2C driver is selected, this file maps the 
    API functions to a particular driver instance-specific static implementation
    function, eliminating unnecessary dynamic parameters. 
*******************************************************************************/

//DOM-IGNORE-BEGIN
/*******************************************************************************
Copyright (c) 2015 released Microchip Technology Inc.  All rights reserved.

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

#include "driver/i2c/drv_i2c.h"
#include "driver/i2c/drv_i2c_static_buffer_model.h"


DRV_HANDLE DRV_I2C_Open ( const SYS_MODULE_INDEX index, const DRV_IO_INTENT ioIntent )
{
    switch (index)
    {
              case DRV_I2C_INDEX_0:
        {
            return (DRV_HANDLE)DRV_I2C_INDEX_0;
            break;
        }
        default:
        {
            break;
        }
    }
    
    return (DRV_HANDLE)NULL;
}

void DRV_I2C_Close ( DRV_HANDLE drvhandle )
{
    switch (drvhandle)
    {
        case DRV_I2C_INDEX_0:
        {
            DRV_I2C0_DeInitialize();
            break;
        }
        default:
        {
            break;
        }
    }
}


DRV_I2C_BUFFER_HANDLE DRV_I2C_Transmit( DRV_HANDLE drvhandle, uint16_t deviceaddress,
                                        void *txBuffer, size_t size, void * context)
{
    
    switch (drvhandle)
    {
        case DRV_I2C_INDEX_0:
        {
            return ( DRV_I2C0_Transmit (deviceaddress, txBuffer, size, context) );
            break;
        }
        default:
        {
            return (DRV_I2C_BUFFER_HANDLE) NULL;
        }
    }
    
    return (DRV_I2C_BUFFER_HANDLE) NULL;
}

DRV_I2C_BUFFER_HANDLE DRV_I2C_TransmitForced( DRV_HANDLE drvhandle, uint16_t deviceaddress,
                                              void *txBuffer, size_t size, DRV_I2C_BUS_ERROR_EVENT eventFlag, void * context)
{
    
    switch (drvhandle)
    {
        case DRV_I2C_INDEX_0:
        {
            return ( DRV_I2C0_TransmitForced (deviceaddress, txBuffer, size, eventFlag, context) );
            break;
        }
        default:
        {
            return (DRV_I2C_BUFFER_HANDLE) NULL;
        }
    }
    
    return (DRV_I2C_BUFFER_HANDLE) NULL;
}


DRV_I2C_BUFFER_HANDLE DRV_I2C_Receive ( DRV_HANDLE drvhandle, uint16_t deviceaddress, 
                                        void *rxBuffer, size_t size, void * context)
{
    switch (drvhandle)
    {
        case DRV_I2C_INDEX_0:
        {
            return ( DRV_I2C0_Receive(deviceaddress, rxBuffer, size, context) );
            break;
        }
        default:
        {
            return (DRV_I2C_BUFFER_HANDLE) NULL;
        }
    }
    
    return (DRV_I2C_BUFFER_HANDLE) NULL;
}

DRV_I2C_BUFFER_HANDLE DRV_I2C_TransmitThenReceive ( DRV_HANDLE drvhandle, uint16_t deviceaddress,
                                                    void *txBuffer, size_t wsize, 
                                                    void *rxBuffer, size_t rsize, void * context)
{
    switch (drvhandle)
    {
        case DRV_I2C_INDEX_0:
        {
            return ( DRV_I2C0_TransmitThenReceive(deviceaddress, txBuffer, wsize, rxBuffer, rsize, context) );
            break;
        }
        default:
        {
            return (DRV_I2C_BUFFER_HANDLE) NULL;
        }
    }
    
    return (DRV_I2C_BUFFER_HANDLE) NULL;
}

DRV_I2C_BUFFER_EVENT DRV_I2C_TransferStatusGet (  DRV_HANDLE drvhandle, DRV_I2C_BUFFER_HANDLE bufferHandle )
{
    switch (drvhandle)
    {
        case DRV_I2C_INDEX_0:
        {
            return ( DRV_I2C0_TransferStatusGet(bufferHandle) );
            break;
        }
        default:
        {
            return (DRV_I2C_BUFFER_EVENT) NULL;
        }
    }
    
    return (DRV_I2C_BUFFER_EVENT) NULL;
}


uint32_t DRV_I2C_BytesTransferred (  DRV_HANDLE drvhandle,  DRV_I2C_BUFFER_HANDLE bufferHandle )
{
    switch (drvhandle)
    {
        case DRV_I2C_INDEX_0:
        {
            return ( DRV_I2C0_BytesTransferred(bufferHandle) );
            break;
        }
        default:
        {
            return 0;
        }
    }
    
    return 0;
}

void DRV_I2C_BufferEventHandlerSet ( const DRV_HANDLE drvhandle,
                                     const DRV_I2C_BUFFER_EVENT_HANDLER eventHandler,
                                     const uintptr_t context )
{
    switch (drvhandle)
    {
        case DRV_I2C_INDEX_0:
        {
            DRV_I2C0_BufferEventHandlerSet (eventHandler,context);
            break;
        }
        default:
        {
            break;
        }
    }
}


/*******************************************************************************
 End of File
*/


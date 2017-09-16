/*******************************************************************************
  I2C Driver Functions for Static Single Instance Driver

  Company:
    Microchip Technology Inc.

  File Name:
    drv_i2c_static_buffer_model.c

  Summary:
    I2C driver implementation for the static single instance driver.

  Description:
    The I2C device driver provides a simple interface to manage the I2C
    modules on Microchip microcontrollers. This file contains interface
    functions for the I2C driver.
    
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
#include "driver/i2c/src/drv_i2c_local.h"

/* prototype of callback when an I2C module is configured as slave      */
/* uncomment this line if using this function                           */
/* refer to DRV_I2Cx_Initialize where the function pointer is assigned  */ 

//void slaveRxorTXNotification(DRV_I2C_BUFFER_EVENT event, void * context);


// *****************************************************************************
/*
 Upper address limit for a 7-bit address 
 */

#define ADDRESS_7BIT_UPPER_LIMIT                    0xFF

typedef struct _DRV_STATIC_I2C_OBJ
{
    
    DRV_I2C_MODE            i2cMode;
    
    uint8_t                 slaveaddresshighbyte;
    
    uint8_t                 slaveaddresslowbyte;
    
    uint8_t *               txBuffer;
    
    uint8_t *               rxBuffer;
    
    DRV_I2C_OPERATIONS      i2coperation;
    
    uint8_t                 transfersize;
    
    uint8_t                 readtransfersize;
    
    uint32_t                actualtransfersize;
    
    bool                    transmitForced;
    
    DRV_I2C_BUS_ERROR_EVENT errorEvent;
    
    DRV_I2C_BUFFER_EVENT    bufferstatus;
    
    DRV_I2C_CallBack        operationStarting;
    
}DRV_STATIC_I2C_OBJECT;


typedef struct _DRV_STATIC_I2C_CLIENT_OBJ
{
    
    /* Save the context, will be passed back with the call back */
    uintptr_t                             context;

    /* I2C callback */
    DRV_I2C_BUFFER_EVENT_HANDLER          callback;
    
}DRV_STATIC_I2C_CLIENT_OBJ;



/* Master Object variables*/
DRV_I2C_DATA_OBJECT_TASK                    i2c0State;
DRV_STATIC_I2C_OBJECT                       i2c0Obj;
DRV_STATIC_I2C_CLIENT_OBJ                   i2c0ClientObj;

/* Variables to maintain Queue State */
volatile uint16_t QueueIn_0     = 0;
volatile uint16_t QueueOut_0    = 0;
volatile uint16_t QueueDelta_0  = 0;

static DRV_STATIC_I2C_OBJECT sDrvI2CBufferObj_0[DRV_I2C_NUM_OF_BUFFER_OBJECTS];

DRV_STATIC_I2C_OBJECT* lBufferObj0;

// *****************************************************************************
// Section: Queue 0 Initialize Queue index variables
// *****************************************************************************
void QueueInitialize_0(void)
{
    QueueIn_0 =  0;
    QueueOut_0 = 0;
}

// *****************************************************************************
// Section: Queue 0 Find a slot in queue
// *****************************************************************************

DRV_STATIC_I2C_OBJECT*  _DRV_I2C_QueueSlotGet_0(void)
{
    
    uint8_t numberOfSlotsAvailable;
    
    DRV_STATIC_I2C_OBJECT*   lQueueObj;
    
    
    if (QueueIn_0 >= QueueOut_0)
    {
        numberOfSlotsAvailable = (DRV_I2C_NUM_OF_BUFFER_OBJECTS-(QueueIn_0 - QueueOut_0) -1);
    }
    else 
    {
        numberOfSlotsAvailable = ((QueueOut_0 - QueueIn_0) -1);      
    }
    
    if (numberOfSlotsAvailable > 0)
    {
        lQueueObj = &sDrvI2CBufferObj_0[QueueIn_0];
        
        QueueIn_0++;
        
        if (QueueIn_0 >= (DRV_I2C_NUM_OF_BUFFER_OBJECTS))
        {
            QueueIn_0 = 0;
        }

        return lQueueObj;
    }
    
    return (DRV_STATIC_I2C_OBJECT*)NULL;
    
}

// *****************************************************************************
/* Checks if Queue is empty, returns true if Queue is empty else returns false*/
// *****************************************************************************

bool IsQueueEmpty_0(void)
{
    if ( (QueueOut_0 == QueueIn_0) )
        return true;
    
    return false;
}

// **************************************************
/* returns the next item from the queue             */
// **************************************************

DRV_STATIC_I2C_OBJECT* _DRV_I2C_QueuePop_0(void)
{
    uint8_t temp;
    
    DRV_STATIC_I2C_OBJECT* lQueuePop;
    
    lQueuePop = NULL;
    
    /* if queue is empty then return NULL */
    if (IsQueueEmpty_0())
    {
        Nop();
        return (DRV_STATIC_I2C_OBJECT*)NULL;
    }
    
    temp = QueueOut_0;
    
    lQueuePop = &sDrvI2CBufferObj_0[temp]; 
    
    
    return lQueuePop;
    
}

void _DRV_I2C_Advance_Queue_0(void)
{
    
    if ( QueueOut_0 >= (DRV_I2C_NUM_OF_BUFFER_OBJECTS-1) )
        QueueOut_0 = 0;
    else
        QueueOut_0++;  
    
}

// *****************************************************************************
// *****************************************************************************
// Section: Instance 0 static driver functions
// *****************************************************************************
// *****************************************************************************
void DRV_I2C0_Initialize(void)
{
    /* Initialize I2C0 */
    PLIB_I2C_BaudRateSet(I2C_ID_1, SYS_CLK_PeripheralFrequencyGet(CLK_BUS_PERIPHERAL_1), 50000);
    PLIB_I2C_StopInIdleDisable(I2C_ID_1);

    /* Low frequency is enabled (**NOTE** PLIB function logic reverted) */
    PLIB_I2C_HighFrequencyEnable(I2C_ID_1);
    i2c0Obj.i2cMode         = DRV_I2C_MODE_MASTER;
    i2c0Obj.transfersize    = 0;
    i2c0State               = DRV_I2C_TASK_SEND_DEVICE_ADDRESS;

    QueueInitialize_0();


    /* Enable I2C0 */
    PLIB_I2C_Enable(I2C_ID_1);
    

}

void DRV_I2C0_DeInitialize(void)
{
    /* Disable I2C0 */
    PLIB_I2C_Disable(I2C_ID_1);
}

// *****************************************************************************
// Section: I2C Instance 0 Function to read a buffer (Master/Slave)
// *****************************************************************************

DRV_I2C_BUFFER_HANDLE DRV_I2C0_Receive (uint16_t deviceaddress,
                                    void *rxBuffer,
                                    size_t size,
                                    void * context)
{ 
       DRV_STATIC_I2C_OBJECT* i2cBufferData;
       
    i2cBufferData = _DRV_I2C_QueueSlotGet_0();


    if (i2cBufferData != NULL)
    {
        i2cBufferData->i2cMode          = DRV_I2C_MODE_MASTER;
        if (deviceaddress > ADDRESS_7BIT_UPPER_LIMIT )
        {
            i2cBufferData->slaveaddresshighbyte = (uint8_t)((deviceaddress & 0xFF00)>>8);
            i2cBufferData->slaveaddresslowbyte  = (uint8_t)(deviceaddress & 0x00FF);
        }
        else
        {
            i2cBufferData->slaveaddresshighbyte = (uint8_t)(deviceaddress & 0x00FF);
            i2cBufferData->slaveaddresslowbyte  = 0;
        }
        i2cBufferData->transfersize     = size;
        i2cBufferData->i2coperation     = DRV_I2C_OP_READ;
        i2cBufferData->rxBuffer         = rxBuffer;
        i2cBufferData->bufferstatus     = DRV_I2C_BUFFER_EVENT_PENDING;
        i2cBufferData->transmitForced   = false;
        i2c0State         = DRV_I2C_TASK_SEND_DEVICE_ADDRESS;
        if (i2cBufferData->i2cMode == DRV_I2C_MODE_MASTER)
        {
            /*  if either START and STOP were not detected which is true the 
            first time OR if STOP was detected, then it assumed the 
            transaction on the bus is complete */

            if ( ((!(PLIB_I2C_StartWasDetected(I2C_ID_1))) && (!(PLIB_I2C_StopWasDetected(I2C_ID_1)))) || (PLIB_I2C_StopWasDetected(I2C_ID_1)) )
            {
                if ( (PLIB_I2C_BusIsIdle(I2C_ID_1)) && (!(PLIB_INT_SourceFlagGet(INT_ID_0, INT_SOURCE_I2C_1_MASTER))) )
                {
                        i2c0State = DRV_I2C_TASK_SEND_DEVICE_ADDRESS;
                        PLIB_I2C_MasterStart(I2C_ID_1);
                }
            }
        }
    }

    return (DRV_I2C_BUFFER_HANDLE)i2cBufferData;
}

// *****************************************************************************
// Section: I2C Instance 0 Function to write a buffer (Master/Slave)
// *****************************************************************************

DRV_I2C_BUFFER_HANDLE DRV_I2C0_Transmit (uint16_t deviceaddress,
                                    void *txBuffer,
                                    size_t size,
                                    void * context)
{
    DRV_STATIC_I2C_OBJECT* i2cBufferData;
       
    i2cBufferData = _DRV_I2C_QueueSlotGet_0();

    if (i2cBufferData != NULL)
    {
        i2cBufferData->i2cMode          = DRV_I2C_MODE_MASTER;
        if (deviceaddress > ADDRESS_7BIT_UPPER_LIMIT )
        {
            i2cBufferData->slaveaddresshighbyte = (uint8_t)((deviceaddress & 0xFF00)>>8);
            i2cBufferData->slaveaddresslowbyte  = (uint8_t)(deviceaddress & 0x00FF);
        }
        else
        {
            i2cBufferData->slaveaddresshighbyte = (uint8_t)(deviceaddress & 0x00FF);
            i2cBufferData->slaveaddresslowbyte  = 0;
        }
        i2cBufferData->i2coperation     = DRV_I2C_OP_WRITE;
        i2cBufferData->transfersize     = size;
        i2cBufferData->txBuffer         = txBuffer;
        i2cBufferData->bufferstatus     = DRV_I2C_BUFFER_EVENT_PENDING;
        i2cBufferData->transmitForced   = false;
        i2c0State         = DRV_I2C_TASK_SEND_DEVICE_ADDRESS;
        if (i2cBufferData->i2cMode == DRV_I2C_MODE_MASTER)
        {
            /*  if either START and STOP were not detected which is true the 
            first time OR if STOP was detected, then it assumed the 
            transaction on the bus is complete */

            if ( ((!(PLIB_I2C_StartWasDetected(I2C_ID_1))) && (!(PLIB_I2C_StopWasDetected(I2C_ID_1)))) || (PLIB_I2C_StopWasDetected(I2C_ID_1)) )
            {
                if ( (PLIB_I2C_BusIsIdle(I2C_ID_1)) && (!(PLIB_INT_SourceFlagGet(INT_ID_0, INT_SOURCE_I2C_1_MASTER))) )                        
                {
                        i2c0State = DRV_I2C_TASK_SEND_DEVICE_ADDRESS;
                        PLIB_I2C_MasterStart(I2C_ID_1);
                }
            }
        }
    }
    return (DRV_I2C_BUFFER_HANDLE)i2cBufferData;
}


DRV_I2C_BUFFER_HANDLE DRV_I2C0_TransmitForced (uint16_t deviceaddress,
                                                             void *txBuffer,
                                                             size_t size,
                                                             void * context)
{
    DRV_STATIC_I2C_OBJECT* i2cBufferData;
       
    i2cBufferData = _DRV_I2C_QueueSlotGet_0();

    if (i2cBufferData != NULL)
    {
        i2cBufferData->i2cMode          = DRV_I2C_MODE_MASTER;
        if (deviceaddress > ADDRESS_7BIT_UPPER_LIMIT )
        {
            i2cBufferData->slaveaddresshighbyte = (uint8_t)((deviceaddress & 0xFF00)>>8);
            i2cBufferData->slaveaddresslowbyte  = (uint8_t)(deviceaddress & 0x00FF);
        }
        else
        {
            i2cBufferData->slaveaddresshighbyte = (uint8_t)(deviceaddress & 0x00FF);
            i2cBufferData->slaveaddresslowbyte  = 0;
        }
        i2cBufferData->i2coperation     = DRV_I2C_OP_WRITE;
        i2cBufferData->transfersize     = size;
        i2cBufferData->txBuffer         = txBuffer;
        i2cBufferData->bufferstatus     = DRV_I2C_BUFFER_EVENT_PENDING;
        i2cBufferData->errorEvent       = DRV_I2C_HALT_ON_ERROR;
        i2cBufferData->transmitForced   = true;
        i2c0State         = DRV_I2C_TASK_SEND_DEVICE_ADDRESS;
        if (i2cBufferData->i2cMode == DRV_I2C_MODE_MASTER)
        {
            /*  if either START and STOP were not detected which is true the 
            first time OR if STOP was detected, then it assumed the 
            transaction on the bus is complete */

            if ( ((!(PLIB_I2C_StartWasDetected(I2C_ID_1))) && (!(PLIB_I2C_StopWasDetected(I2C_ID_1)))) || (PLIB_I2C_StopWasDetected(I2C_ID_1)) )
            {
                if ( (PLIB_I2C_BusIsIdle(I2C_ID_1)) && (!(PLIB_INT_SourceFlagGet(INT_ID_0, INT_SOURCE_I2C_1_MASTER))) )                        
                {
                        i2c0State = DRV_I2C_TASK_SEND_DEVICE_ADDRESS;
                        PLIB_I2C_MasterStart(I2C_ID_1);
                }
            }
        }
    }
    return (DRV_I2C_BUFFER_HANDLE)i2cBufferData;
}

DRV_I2C_BUFFER_HANDLE DRV_I2C0_TransmitThenReceive ( uint16_t deviceaddress,
                                    void *txBuffer,
                                    size_t wsize,
                                    void *rxBuffer,
                                    size_t rsize,
                                    void * context)
{
    DRV_STATIC_I2C_OBJECT* i2cBufferData;

    i2cBufferData = _DRV_I2C_QueueSlotGet_0();

    if (i2cBufferData != NULL)
    {
        i2cBufferData->i2cMode             = DRV_I2C_MODE_MASTER;
        if (deviceaddress > ADDRESS_7BIT_UPPER_LIMIT )
        {
            i2cBufferData->slaveaddresshighbyte = (uint8_t)((deviceaddress & 0xFF00)>>8);
            i2cBufferData->slaveaddresslowbyte  = (uint8_t)(deviceaddress & 0x00FF);
        }
        else
        {
            i2cBufferData->slaveaddresshighbyte = (uint8_t)(deviceaddress & 0x00FF);
            i2cBufferData->slaveaddresslowbyte  = 0;
        }
        i2cBufferData->i2coperation        = DRV_I2C_OP_WRITE_READ;
        i2cBufferData->txBuffer            = txBuffer;
        i2cBufferData->transfersize        = wsize;
        i2cBufferData->rxBuffer            = rxBuffer;
        i2cBufferData->readtransfersize    = rsize;
        i2cBufferData->actualtransfersize  = 0;
        i2cBufferData->transmitForced      = false;
        i2cBufferData->bufferstatus        = DRV_I2C_BUFFER_EVENT_PENDING;
        i2c0State                   = DRV_I2C_TASK_SEND_DEVICE_ADDRESS;


        if (i2c0Obj.i2cMode == DRV_I2C_MODE_MASTER)
        {
            /*  if either START and STOP were not detected which is true the 
            first time OR if STOP was detected, then it assumed the 
            transaction on the bus is complete */

            if ( ((!(PLIB_I2C_StartWasDetected(I2C_ID_1))) && (!(PLIB_I2C_StopWasDetected(I2C_ID_1)))) || (PLIB_I2C_StopWasDetected(I2C_ID_1)) )
            {
                if ( (PLIB_I2C_BusIsIdle(I2C_ID_1)) && (!(PLIB_INT_SourceFlagGet(INT_ID_0, INT_SOURCE_I2C_1_MASTER))) )
                {
                    i2c0State = DRV_I2C_TASK_SEND_DEVICE_ADDRESS;
                    PLIB_I2C_MasterStart(I2C_ID_1);
                }
            }
        }
    }

    return (DRV_I2C_BUFFER_HANDLE)i2cBufferData;

} /* DRV_I2C_BufferAddWriteRead */

void DRV_I2C0_Tasks(void)
{
    uint8_t tempDeviceAddress;

    switch (i2c0State)
    {
        case DRV_I2C_TASK_SEND_DEVICE_ADDRESS:
        {
            if (i2c0Obj.i2cMode == DRV_I2C_MODE_MASTER)
            {
                lBufferObj0 = _DRV_I2C_QueuePop_0();

                if (PLIB_I2C_StartWasDetected(I2C_ID_1))
                {
                    if ( (lBufferObj0->i2coperation == DRV_I2C_OP_WRITE) || (lBufferObj0->i2coperation == DRV_I2C_OP_WRITE_READ) )
                    {
                        if (lBufferObj0->slaveaddresslowbyte)
                        {
                            i2c0State = DRV_I2C_SEND_DEVICE_ADDRESS_BYTE_2;
                        }
                        else
                        {
                            lBufferObj0->bufferstatus    = DRV_I2C_BUFFER_SLAVE_WRITE_REQUESTED;
                            i2c0State = DRV_I2C_TASK_PROCESS_WRITE_ONLY;
                        }

                        PLIB_I2C_TransmitterByteSend( I2C_ID_1, lBufferObj0->slaveaddresshighbyte );
                    }
                    else
                    {
                        lBufferObj0->bufferstatus    = DRV_I2C_BUFFER_SLAVE_READ_REQUESTED;
                        i2c0State = DRV_I2C_TASK_SET_RCEN_ONLY;
                        PLIB_I2C_TransmitterByteSend(I2C_ID_1, lBufferObj0->slaveaddresshighbyte | DRV_I2C_OP_READ );
                    }
                }
            }
            else if (i2c0Obj.i2cMode == DRV_I2C_MODE_SLAVE)
            {
                i2c0State = DRV_I2C_TASK_SEND_DEVICE_ADDRESS;
                /* Slave is accepting data from Master */
                if ( (!PLIB_I2C_SlaveReadIsRequested(I2C_ID_1)) && (PLIB_I2C_SlaveAddressIsDetected(I2C_ID_1)) )
                {
                    i2c0Obj.operationStarting(DRV_I2C_BUFFER_SLAVE_READ_REQUESTED,0x00);

                    lBufferObj0 = _DRV_I2C_QueuePop_0();

                    /* do a dummy read so that I2CxRCV is cleared and not clobbered with data */
                    PLIB_I2C_ReceivedByteGet (I2C_ID_1);
                    PLIB_I2C_SlaveClockRelease (I2C_ID_1);
                }
                /*  Slave is sending data back to the Master    */
                else if ( (PLIB_I2C_SlaveReadIsRequested(I2C_ID_1)) && (PLIB_I2C_SlaveAddressIsDetected(I2C_ID_1)) )
                {

                    PLIB_I2C_ReceivedByteGet (I2C_ID_1);
                    PLIB_I2C_SlaveClockHold (I2C_ID_1);
                    
                    i2c0Obj.operationStarting(DRV_I2C_BUFFER_SLAVE_WRITE_REQUESTED,0x00);

                    lBufferObj0 = _DRV_I2C_QueuePop_0();

                    lBufferObj0->transfersize = 0;

                    // transmit first byte
                    PLIB_I2C_TransmitterByteSend(I2C_ID_1, *lBufferObj0->txBuffer++);
                    lBufferObj0->transfersize++;
                    PLIB_I2C_SlaveClockRelease (I2C_ID_1);
                }
                else if ( (!PLIB_I2C_SlaveReadIsRequested(I2C_ID_1)) && PLIB_I2C_SlaveDataIsDetected(I2C_ID_1))
                {
                    /*        Master sends data to the slave        */ 
                    PLIB_I2C_SlaveClockRelease (I2C_ID_1);

                    if (lBufferObj0->transfersize < 255)
                    {
                        *lBufferObj0->rxBuffer++ = PLIB_I2C_ReceivedByteGet(I2C_ID_1);
                        lBufferObj0->transfersize++;
                        lBufferObj0->bufferstatus = DRV_I2C_BUFFER_SLAVE_READ_BYTE;
                        if ( i2c0ClientObj.callback != NULL )
                        {
                            /* Give an indication to the higher layer upon successful operation */
                            i2c0ClientObj.callback(DRV_I2C_BUFFER_SLAVE_READ_BYTE, 
                                        (DRV_I2C_BUFFER_HANDLE) lBufferObj0, 0x00);
                        }                       
                    }
                    else
                    {
                        lBufferObj0->bufferstatus = DRV_I2C_BUFFER_EVENT_ERROR;                                 
                        PLIB_I2C_ReceivedByteGet(I2C_ID_1);
                        if ( i2c0ClientObj.callback != NULL )
                        {
                            /* Give an indication to the higher layer upon when error happens */
                            i2c0ClientObj.callback(DRV_I2C_BUFFER_EVENT_ERROR, 
                                        (DRV_I2C_BUFFER_HANDLE) lBufferObj0, 0x00);
                        }  
                    }
                }
                else if (PLIB_I2C_SlaveReadIsRequested(I2C_ID_1) && PLIB_I2C_SlaveDataIsDetected(I2C_ID_1))
                {
                    PLIB_I2C_SlaveClockHold (I2C_ID_1);

                    if ( PLIB_I2C_TransmitterByteWasAcknowledged(I2C_ID_1) )
                    {
                        if ( lBufferObj0->transfersize < 255 )
                        {
                            PLIB_I2C_SlaveClockRelease(I2C_ID_1);
                            PLIB_I2C_TransmitterByteSend (I2C_ID_1, *lBufferObj0->txBuffer++ );
                            lBufferObj0->transfersize++;
                            lBufferObj0->bufferstatus = DRV_I2C_BUFFER_SLAVE_WRITE_BYTE;
                            if ( i2c0ClientObj.callback != NULL )
                            {
                                /* Give an indication to the higher layer upon successful transmission */
                                i2c0ClientObj.callback(DRV_I2C_BUFFER_SLAVE_WRITE_BYTE, 
                                            (DRV_I2C_BUFFER_HANDLE) lBufferObj0, 0x00);
                    }
                        }
                        else
                        {
                            lBufferObj0->bufferstatus = DRV_I2C_BUFFER_EVENT_ERROR;
                            PLIB_I2C_TransmitterByteSend(I2C_ID_1, 0);
                            if ( i2c0ClientObj.callback != NULL )
                            {
                                /* Give an indication to the higher layer upon when error happens */
                                i2c0ClientObj.callback(DRV_I2C_BUFFER_EVENT_ERROR, 
                                        (DRV_I2C_BUFFER_HANDLE) lBufferObj0, 0x00);
                            }  
                        }
                    }
                    else if ( !PLIB_I2C_TransmitterByteWasAcknowledged(I2C_ID_1) )
                    {
                        PLIB_I2C_SlaveClockRelease (I2C_ID_1);
                        //TODO callback implementation
                        lBufferObj0->bufferstatus = DRV_I2C_BUFFER_EVENT_COMPLETE; 
                    }
                }
            }
            break;
        }

        case DRV_I2C_SEND_DEVICE_ADDRESS_BYTE_2:
        {
            if ( lBufferObj0->i2coperation == DRV_I2C_OP_READ )
            {
                PLIB_I2C_TransmitterByteSend(I2C_ID_1,lBufferObj0->slaveaddresslowbyte>>1) ;
                i2c0State = DRV_I2C_TASK_SET_RCEN_ONLY;
            }
            else
            {                         
                PLIB_I2C_TransmitterByteSend (I2C_ID_1, lBufferObj0->slaveaddresslowbyte>>1) ;
                i2c0State = DRV_I2C_TASK_PROCESS_WRITE_ONLY;
            }
            break;
        }

        case DRV_I2C_SEND_RANDOM_READ_DEVICE_ADDRESS:
        {
            tempDeviceAddress = (lBufferObj0->slaveaddresshighbyte);
            tempDeviceAddress |= 0x01;
            PLIB_I2C_TransmitterByteSend( I2C_ID_1,tempDeviceAddress );
            i2c0State = DRV_I2C_TASK_SET_RCEN_ONLY;
            break;
        }

        case DRV_I2C_TASK_PROCESS_READ_ONLY:
        {
            /* Read I2CxRCV register for received data */
            if (lBufferObj0->transfersize)
            {
                if ( PLIB_I2C_ReceivedByteIsAvailable (I2C_ID_1) )
                {
                    /* If all but one reception is complete */
                    if ( lBufferObj0->transfersize > 1 )
                    {
                        *lBufferObj0->rxBuffer++ = PLIB_I2C_ReceivedByteGet (I2C_ID_1);
                        lBufferObj0->transfersize--;
                        lBufferObj0->actualtransfersize++;
                        i2c0State  = DRV_I2C_TASK_SET_RCEN_ONLY;
                        if (PLIB_I2C_MasterReceiverReadyToAcknowledge(I2C_ID_1))
                        {
                            PLIB_I2C_ReceivedByteAcknowledge (I2C_ID_1, true);
                        }
                    }
                    else
                    {
                        lBufferObj0->transfersize--;
                        lBufferObj0->actualtransfersize++;

                        *lBufferObj0->rxBuffer++ = PLIB_I2C_ReceivedByteGet (I2C_ID_1);
                        if (PLIB_I2C_MasterReceiverReadyToAcknowledge(I2C_ID_1))
                        {
                            PLIB_I2C_ReceivedByteAcknowledge ( I2C_ID_1, false  );
                        }

                        i2c0State = DRV_I2C_BUS_SILENT;
                    }
                }
                else
                {
                    // Do not block in any case
                    break;
                }
            }
            break;
        }

        case    DRV_I2C_TASK_PROCESS_WRITE_ONLY:
        {
            if (lBufferObj0->transfersize)
            {
                if ( PLIB_I2C_TransmitterByteHasCompleted (I2C_ID_1) )
                {
                    if ( PLIB_I2C_TransmitterByteWasAcknowledged (I2C_ID_1) ||
                        (lBufferObj0->transmitForced)  )
                    {
                        if (lBufferObj0->transfersize > 1)
                            i2c0State = DRV_I2C_TASK_PROCESS_WRITE_ONLY;
                        else
                            i2c0State = DRV_I2C_BUS_SILENT;
                        PLIB_I2C_TransmitterByteSend ( I2C_ID_1, *lBufferObj0->txBuffer++ );
                        lBufferObj0->transfersize--;
                        lBufferObj0->actualtransfersize++;
                    }
                    else
                    {
                        i2c0State = DRV_I2C_TASK_PROCESS_STOP;
                        PLIB_I2C_MasterStop (I2C_ID_1);
                    }
                }
                else
                {
                    /* do not block but exit*/
                    break;
                }
            }
            else
            {
                i2c0State = DRV_I2C_TASK_PROCESS_STOP;
                PLIB_I2C_MasterStop (I2C_ID_1);
            }
            break;
        }

        case    DRV_I2C_BUS_SILENT:
        {
            /* The bus is silent/idle when when the last byte is either ACKed  OR
            in the event of slave unexpectedly aborting operation, check
            if transmission is complete and NACK is received
            ACK received OR (transmit complete & NACKed)
            */

            if ( (PLIB_I2C_TransmitterByteWasAcknowledged (I2C_ID_1)) ||
                    ( PLIB_I2C_TransmitterByteHasCompleted (I2C_ID_1)  &&
                        (!PLIB_I2C_TransmitterByteWasAcknowledged (I2C_ID_1)) ) )
            {
                if (lBufferObj0->i2coperation == DRV_I2C_OP_WRITE_READ)
                {
                    lBufferObj0->transfersize   = lBufferObj0->readtransfersize;
                    i2c0State                   = DRV_I2C_SEND_RANDOM_READ_DEVICE_ADDRESS;
                    lBufferObj0->i2coperation   = DRV_I2C_OP_READ;
                    PLIB_I2C_MasterStartRepeat (I2C_ID_1);
                }
                else
                {
                    i2c0State = DRV_I2C_TASK_PROCESS_STOP;
                    PLIB_I2C_MasterStop (I2C_ID_1);
                }
            }
            break;
        }

        case DRV_I2C_TASK_SET_RCEN_ONLY:
		{
            if ( PLIB_I2C_TransmitterByteHasCompleted(I2C_ID_1) )
            {
                if ( PLIB_I2C_TransmitterByteWasAcknowledged(I2C_ID_1) )
                {
                    /* if I2CxSTAT.ACKEN bit is 0, the Acknowledge sequence has been completed */
                    if (PLIB_I2C_ReceiverByteAcknowledgeHasCompleted(I2C_ID_1))
                    {
                        PLIB_I2C_MasterReceiverClock1Byte (I2C_ID_1);
                        i2c0State = DRV_I2C_TASK_PROCESS_READ_ONLY;
                    }
                }
                else
                {
                    i2c0State = DRV_I2C_TASK_PROCESS_STOP;
                    PLIB_I2C_MasterStop (I2C_ID_1);
                }
            }
            break;
        }

        case    DRV_I2C_TASK_PROCESS_STOP:
        {
            if (PLIB_I2C_StopWasDetected(I2C_ID_1))
            {
                i2c0State = DRV_I2C_TASK_SEND_DEVICE_ADDRESS;
                if (lBufferObj0->transfersize)
                {
                    lBufferObj0->bufferstatus    = DRV_I2C_BUFFER_EVENT_ERROR;
                }
                else
                {
                    lBufferObj0->bufferstatus    = DRV_I2C_BUFFER_EVENT_COMPLETE;
                }
                /* Have a check here because DRV_I2C_BufferEvent_Handler function call is optional */
                if ( i2c0ClientObj.callback != NULL )
                {
                    /* Give an indication to the higher layer upon successful transmission */
                    i2c0ClientObj.callback(lBufferObj0->bufferstatus, 
                                                        (DRV_I2C_BUFFER_HANDLE) lBufferObj0, 0x00);
                }
            }
            else
            {
                i2c0State = DRV_I2C_TASK_PROCESS_STOP;
            }
            break;
        }

        default:
            break;
    }

    /* Clear pending interrupt */
    PLIB_INT_SourceFlagClear(INT_ID_0, INT_SOURCE_I2C_1_MASTER);    
    PLIB_INT_SourceFlagClear(INT_ID_0, INT_SOURCE_I2C_1_ERROR);

    if (i2c0Obj.i2cMode == DRV_I2C_MODE_MASTER)
    {
        if ( (lBufferObj0->bufferstatus == DRV_I2C_BUFFER_EVENT_COMPLETE) || (lBufferObj0->bufferstatus == DRV_I2C_BUFFER_EVENT_ERROR) )
        {
            _DRV_I2C_Advance_Queue_0();
            if (IsQueueEmpty_0() == false)
            {
                i2c0State = DRV_I2C_TASK_SEND_DEVICE_ADDRESS;
                PLIB_I2C_MasterStart(I2C_ID_2);
                Nop();
            }
        }
    }
}


// *****************************************************************************
// Section: Instance 0 Byte Transfer Functions (Master/Slave)
// *****************************************************************************

uint32_t DRV_I2C0_BytesTransferred ( DRV_I2C_BUFFER_HANDLE bufferHandle )
{
    /* returns the number of bytes transferred in an I2C transaction */
    return ((DRV_STATIC_I2C_OBJECT*)bufferHandle)->actualtransfersize;
}

// *****************************************************************************
// Section: Function that will initiate a callback to the main
//          application on status of buffer operation
// *****************************************************************************

void DRV_I2C0_BufferEventHandlerSet (const DRV_I2C_BUFFER_EVENT_HANDLER eventHandler,
                                                   const uintptr_t context )
{
    i2c0ClientObj.callback = eventHandler;

    i2c0ClientObj.context = context;
}   /* DRV_I2C_BufferEventHandlerSet */


// *****************************************************************************
// Section: Instance 0 Function to check status of a buffer 
//          transfer operation
// *****************************************************************************

DRV_I2C_BUFFER_EVENT DRV_I2C0_TransferStatusGet ( DRV_I2C_BUFFER_HANDLE bufferHandle )
{
    /* return status of Buffer Transfer */    
    return ((DRV_STATIC_I2C_OBJECT*)bufferHandle)->bufferstatus;
} /* DRV_I2C_TransferStatus */



/*******************************************************************************
 End of File
*/
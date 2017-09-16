/*******************************************************************************
 I2C Device Driver Interface Header File

  Company:
    Microchip Technology Inc.

  File Name:
    drv_i2c.h

  Summary:
    I2C module driver interface header.

  Description:
    This header file contains the function prototypes and definitions of the
    data types and constants that make up the interface to the I2C module
    driver.
*******************************************************************************/

//DOM-IGNORE-BEGIN
/*******************************************************************************
Copyright (c) 2014-2015 released Microchip Technology Inc.  All rights
reserved.

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

#ifndef _DRV_I2C_H_
#define _DRV_I2C_H_


// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include "system_config.h"
#include "driver/driver_common.h"           // Common Driver Definitions
#include "peripheral/i2c/plib_i2c.h"        // I2C PLIB Header
#include "system/common/sys_common.h"       // Common System Service Definitions
#include "system/common/sys_module.h"       // Module/Driver Definitions
#include "system/int/sys_int.h"             // System Interrupt Definitions
#include "system/clk/sys_clk.h"
#include "system/ports/sys_ports.h"


// DOM-IGNORE-BEGIN
#ifdef __cplusplus  

    extern "C" {

#endif
// DOM-IGNORE-END  


// *****************************************************************************
// *****************************************************************************
// Section: I2C Driver Data Types
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Driver Instance Index 0

  Summary:
    Identifies the instance of the I2C driver.

  Description:
    This value identifies the instance of the I2C driver.  It is a zero-based
    index.

  Remarks:
    This number is not directly related to the peripheral hardware instance.  
    The peripehral hardware instances is associated with the driver instance
    by the DRV_I2C_Initialize function.
 */

#define DRV_I2C_INDEX_0         0


// *****************************************************************************
/* Driver Instance Index 1

  Summary:
    Identifies the instance of the I2C driver.

  Description:
    This value identifies the instance of the I2C driver.  It is a zero-based
    index.

  Remarks:
    This number is not directly related to the peripheral hardware instance.  
    The peripheral hardware instances is associated with the driver instance
    by the DRV_I2C_Initialize function.
 */

#define DRV_I2C_INDEX_1         1


// *****************************************************************************
/* Driver Instance Index 2

  Summary:
    Identifies the instance of the I2C driver.

  Description:
    This value identifies the instance of the I2C driver.  It is a zero-based
    index.

  Remarks:
    This number is not directly related to the peripheral hardware instance.  
    The peripheral hardware instances is associated with the driver instance
    by the DRV_I2C_Initialize function.
 */

#define DRV_I2C_INDEX_2         2


// *****************************************************************************
/* Driver Instance Index 3

  Summary:
    Identifies the instance of the I2C driver.

  Description:
    This value identifies the instance of the I2C driver.  It is a zero-based
    index.

  Remarks:
    This number is not directly related to the peripheral hardware instance.  
    The peripheral hardware instances is associated with the driver instance
    by the DRV_I2C_Initialize function.
 */

#define DRV_I2C_INDEX_3         3


// *****************************************************************************
/* Driver Instance Index 4

  Summary:
    Identifies the instance of the I2C driver.

  Description:
    This value identifies the instance of the I2C driver.  It is a zero-based
    index.

  Remarks:
    This number is not directly related to the peripheral hardware instance.  
    The peripheral hardware instances is associated with the driver instance
    by the DRV_I2C_Initialize function.
 */

#define DRV_I2C_INDEX_4         4


// *****************************************************************************
/* Driver Instance Index 5

  Summary:
    Identifies the instance of the I2C driver.

  Description:
    This value identifies the instance of the I2C driver.  It is a zero-based
    index.

  Remarks:
    This number is not directly related to the peripheral hardware instance.  
    The peripehral hardware instances is associated with the driver instance
    by the DRV_I2C_Initialize function.
 */

#define DRV_I2C_INDEX_5         5


// *****************************************************************************
/* I2C Buffer Handle

  Summary:
    Handle to an I2C data buffer.

  Description:
    This data type provides a handle to an I2C buffer that has been passed to 
    the driver for processing.

  Remarks:
    This handle is provided by one of the data transfer functions 
    (DRV_I2C_Receive, DRV_I2C_Transmit, DRV_I2C_TransmitThenReceive) and is used
    by the buffer event-handler (DRV_I2C_BUFFER_EVENT_HANDLER) call-back
    function and buffer status functions (DRV_I2C_TransferStatusGet, 
    DRV_I2C_BytesTransferred).
*/

typedef uintptr_t DRV_I2C_BUFFER_HANDLE;

typedef unsigned char I2C_DATA_TYPE;


typedef uint8_t	 I2C_SLAVE_ADDRESS_7bit;        // need to type cast 10-bit slave address into 8 bit mode
// *****************************************************************************
/* I2C Slave Device Address

  Summary:
    Data type for a slave device address.

  Description:
    This is the data type for an I2C slave device address.  It can hold both
    7-bit and 10-bit slave addresses.

  Remarks:
    None.
*/

typedef uint16_t I2C_SLAVE_ADDRESS_VALUE;


// *****************************************************************************
/* I2C Slave Device Address Mask

  Summary:
    Data type for a slave device address bit-mask.

  Description:
    This is the data type for an I2C slave device address bit-mask.  It can hold
    both 7-bit and 10-bit slave addresses masks.

  Remarks:
    A slave address mask is used in slave mode to identify "don't care" bits 
    in the base slave address to which the I2C interface will respond..
*/

typedef uint8_t DRV_I2C_SLAVE_ADDRESS_MASK;


// *****************************************************************************
/* I2C Buffer Events

  Summary:
    Lists the different conditions that happens during a buffer transfer.

  Description:
    This enumeration identifies the different conditions that can happen during
    a buffer transaction. Callbacks can be made with the appropriate buffer
    condition passed as a parameter to execute the desired action.
    The application can also poll the BufferStatus flag to check the status of
    transfer.

    The values act like flags and multiple flags can be set.

  Remarks:
    None.
*/

typedef enum
{
    /* Buffer is pending to get processed */
    DRV_I2C_BUFFER_EVENT_PENDING,

    /* All data from or to the buffer was transferred successfully. */
    DRV_I2C_BUFFER_EVENT_COMPLETE,

    /* There was an error while processing the buffer transfer request. */
    DRV_I2C_BUFFER_EVENT_ERROR,

    /*  Send Stop by Master */
    DRV_I2C_SEND_STOP_EVENT,

    /* Send Restart Event by Master */
    DRV_I2C_SEND_RESTART_EVENT,

    /* Master sends data to slave */
    DRV_I2C_BUFFER_SLAVE_READ_REQUESTED,

    /* Master requests data from slave */
    DRV_I2C_BUFFER_SLAVE_WRITE_REQUESTED,

    /* Slave read byte send by Master */
    DRV_I2C_BUFFER_SLAVE_READ_BYTE,
            
    /* sending ACK to Slave for more bytes */
    DRV_I2C_BUFFER_MASTER_ACK_SEND,
            
    /* sending ACK to Slave for more bytes */
    DRV_I2C_BUFFER_MASTER_NACK_SEND,

   /* Slave send byte to Master */
    DRV_I2C_BUFFER_SLAVE_WRITE_BYTE

} DRV_I2C_BUFFER_EVENT;


// *****************************************************************************
/* I2C Buffer Event Callback

  Function:
    typedef void (*DRV_I2C_CallBack) ( DRV_I2C_BUFFER_EVENT event, 
                       void  * context )

  Summary:
    Points to a callback to initiate a particular function.

  Description:
    This type identifies the I2C Buffer Event.  It allows the client driver
    to register a callback using DRV_I2C_BUFFER_EVENT. By using this
    mechanism, the driver client will can initiate an operation. This is
    intended to be used for SLAVE mode because the Master drives the I2C bus
    and through this the Slave can issue a READ or WRITE based on the status of
    R/W bit received from the Master

  Parameters:
   DRV_I2C_BUFFER_EVENT - Status of I2C transfer

   context     - This is left for future implementation

  Remarks:
    A transfer can be composed of various transfer segments.  Once a transfer
    is completed the driver will call the client registered transfer
    callback.

    The callback could be called from ISR context and should be kept as short
    as possible.  It is meant for signaling and it should not be blocking.

*/


typedef void (*DRV_I2C_CallBack) ( DRV_I2C_BUFFER_EVENT event, void * context );


// *****************************************************************************
/* I2C Buffer Event Callback

  Function:
    void ( *DRV_I2C_BUFFER_EVENT_HANDLER ) (DRV_I2C_BUFFER_EVENT event, 
                DRV_I2C_BUFFER_HANDLE bufferHandle, uintptr_t context )

  Summary:
    Points to a callback after completion of an I2C  transfer.

  Description:
    This type identifies the I2C Buffer Event.  It allows the client driver
    to register a callback using DRV_I2C_BUFFER_EVENT_HANDLER. By using this
    mechanism, the driver client will be notified at the completion of the
    corresponding transfer.

  Parameters:
    DRV_I2C_BUFFER_EVENT - Status of I2C transfer

    bufferHandle - Handle that identifies that identifies the particular Buffer
                   Object

    context     - For future implementation

  Remarks:
    A transfer can be composed of various transfer segments.  Once a transfer
    is completed the driver will call the client registered transfer
    callback.

    The callback could be called from ISR context and should be kept as short
    as possible.  It is meant for signaling and it should not be blocking.

*/

typedef void ( *DRV_I2C_BUFFER_EVENT_HANDLER ) (DRV_I2C_BUFFER_EVENT event,
                    DRV_I2C_BUFFER_HANDLE bufferHandle, uintptr_t context );


// *****************************************************************************
/* I2C Operation Mode

  Summary
    Lists the operation mode of I2C module.

  Description
    This enumeration lists if the I2C module is configured as a Master or
    a Slave.

  Remarks:
    None.
*/

typedef enum
{
    /* I2C Mode Master */
    DRV_I2C_MODE_MASTER     /*DOM-IGNORE-BEGIN*/  = 0 /*DOM-IGNORE-END*/,

    /* I2C Mode Slave */
    DRV_I2C_MODE_SLAVE      /*DOM-IGNORE-BEGIN*/  = 1 /*DOM-IGNORE-END*/

} DRV_I2C_MODE;

// *****************************************************************************
/* I2C Configuration Choice

  Summary
    Lists the operation mode of I2C module.

  Description
    This enumeration lists if the I2C module is configured to use I2C
    peripheral or use Bit-Bang implementation.

  Remarks:
    None.
*/

typedef enum
{
    /* Make use of the I2C Peripheral. */
    DRV_I2C_PERIPHERAL
        /*DOM-IGNORE-BEGIN*/  = 0 /*DOM-IGNORE-END*/,

    /* Make use of the I2C Bit Bang Algorithm */
    DRV_I2C_BIT_BANG
        /*DOM-IGNORE-BEGIN*/  = 1 /*DOM-IGNORE-END*/

} DRV_I2C_PERPH;


// *****************************************************************************
/* I2C Slave Address Width

  Summary:
    Lists the Address Width of the Slave.

  Description:
    This enumeration lists if the I2C module is configured as a 7-bit Slave or
    a 10-bit Slave.

  Remarks:
    None.
*/

typedef enum
{

   /* I2C Slave 7 bit  */
    DRV_I2C_7BIT_SLAVE      /*DOM-IGNORE-BEGIN*/  = 1 /*DOM-IGNORE-END*/,

    /* I2C Slave 10 bit  */
    DRV_I2C_10BIT_SLAVE     /*DOM-IGNORE-BEGIN*/  = 2 /*DOM-IGNORE-END*/

} DRV_I2C_ADDRESS_WIDTH;


// *****************************************************************************
/* I2C Bus Levels

  Summary:
    Lists the Operational Voltage level of I2C.

  Description:
    This enumeration lists if the I2C is configured to operate in the traditional
    I2C mode or the SMBus mode.

  Remarks:
    None.
*/

typedef enum
{

    /* I2C BUS LEVEL */
    DRV_I2C_OPEN_COLLECTOR_LEVEL    /*DOM-IGNORE-BEGIN*/  = 0 /*DOM-IGNORE-END*/,

    /* SMBus level */
    DRV_I2C_SMBus_LEVEL             /*DOM-IGNORE-BEGIN*/  = 1 /*DOM-IGNORE-END*/

} DRV_I2C_BUS_LEVEL;


// *****************************************************************************
/* I2C Bus Speed

  Summary
    Lists the I2C Bus speed mode.

  Description
    This enumeration lists if the I2C is configured to operate at High-Speed or
    Normal Speed.

  Remarks:
    None.
*/

typedef enum
{
    DRV_I2C_NORMAL_SPEED    /*DOM-IGNORE-BEGIN*/  = 0 /*DOM-IGNORE-END*/,

    DRV_I2C_HIGH_SPEED      /*DOM-IGNORE-BEGIN*/  = 1 /*DOM-IGNORE-END*/

}DRV_I2C_BUS_SPEED;



typedef enum
{
    /* normal I2C with not ignoring any error */
    DRV_I2C_HALT_ON_ERROR = 0x00,
            
    /* ignore bus collision error */
    DRV_I2C_BUS_IGNORE_COLLISION_ERROR = 0x01,
            
    /* ignore overflow error */
    DRV_I2C_BUS_IGNORE_OVERFLOW_ERROR = 0x02,
    
}DRV_I2C_BUS_ERROR_EVENT;


/*******************************************************************************
 I2C Initialization Values

   Summary:
    Identifies the initialization values that are passed as parameters to the
    initialize and reinitialize routines of the I2C module.

   Description:
    This enumeration identifies the values that are passed as parameters to the
    initialize and reinitialize routines of the I2C module.

    These values specify different I2C module initialization parameters.
*/

typedef  struct _DRV_I2C_INIT
{
    /* System module initialization */
    SYS_MODULE_INIT                         moduleInit;

    /* Identifies peripheral (PLIB-level) ID */
    I2C_MODULE_ID                           i2cId;

    /* I2C Usage Mode Type */
    DRV_I2C_MODE                            i2cMode;
    
    /* I2C Peripheral or not usage */
    DRV_I2C_PERPH                    		i2cPerph;
        
    /* PORT which SCL belongs */
    PORTS_CHANNEL                           portSCL;

    /* Bit position in the port for SCL */
    PORTS_BIT_POS                           pinSCL;
    
    /* PORT which SDA belongs */
    PORTS_CHANNEL                           portSDA;

    /* Bit position in the port for SDA */
    PORTS_BIT_POS                           pinSDA;

    /* Communication Width */
    DRV_I2C_ADDRESS_WIDTH                   addWidth;

    /* Reserved Address rule enable */
    bool                                    reservedaddenable;

    /* General Call address enable */
    bool                                    generalcalladdress;

    /* Slave address value*/
    I2C_SLAVE_ADDRESS_VALUE                 slaveaddvalue;

    /* Baud Rate Value */
    uint32_t                                baudRate;

    /* I2C Clock mode */
    DRV_I2C_BUS_LEVEL                       buslevel;

    /*I2C Bus Speed */
    DRV_I2C_BUS_SPEED                       busspeed;

    /* Master Interrupt Source for I2C module */
    INT_SOURCE                              mstrInterruptSource;

    /* Slave Interrupt Source for I2C module */
    INT_SOURCE                              slaveInterruptSource;

    /* Error Interrupt Source for I2C module */
    INT_SOURCE                              errInterruptSource;

    /*  This is the buffer queue size. This is the maximum
        number of  transfer requests that driver will queue. For a
        static build of the driver, this is overridden by the
        DRV_I2C_QUEUE_SIZE macro in system_config.h             */
    unsigned int                            queueSize;

    /*  This callback is fired when an operation needs to be initiated on the
    I2C bus.  This callback is mainly intended when the driver is used in
    SLAVE mode and is required to send data to the Master. The callback
    signals the application to prepare data for transfer to Master.
    This callback may be called from an ISR so should not include OSAL
    calls.  The context parameter is the same one passed into the
    BufferAddRead, BufferAddWrite, BufferAddWriteRead function.     */

    DRV_I2C_CallBack                        operationStarting;

    /*  Slave address Mask value, the I2C slave address match ignored for the
        bit fields that the mask is set
    */

    DRV_I2C_SLAVE_ADDRESS_MASK              maskslaveaddress;

} DRV_I2C_INIT;


// *****************************************************************************
// *****************************************************************************
// Section: System Interface Functions
// *****************************************************************************
// *****************************************************************************

/*******************************************************************************
  Function:
    void DRV_I2C_Initialize ( const I2C_MODULE_ID    index,
                              const SYS_MODULE_INIT *const data )

  Summary:
    Initializes hardware and data for the index instance of the I2C module.
    <p><b>Implementation:</b> Static/Dynamic</p>

  Description:
    This function initializes hardware for the index instance of the I2C module,
    using the hardware initialization given data.  It also initializes any
    internal driver data structures making the driver ready to be opened.

  Precondition:
    None.

  Parameters:
    index       - Index, identifying the instance of the I2C module to be
                  initialized

    data        - Pointer to the data structure containing any data necessary to
                  initialize the hardware.  This pointer may be null if no data
                  is required and the default initialization is to be used.

  Returns:
    None.

 Remarks:
    This function must be called before any other I2C function is called.

    This function should only be called once during system initialization unless
    DRV_I2C_Deinitialize is first called to deinitialize the device instance
    before reinitializing it.

    This function may block if the driver is running in an OS environment that
    supports blocking operations and the driver requires system resources
    access.  However, the routine will NEVER block for hardware I2C access.
    If the operation requires time to allow the hardware to complete, this will
    be reported by the DRV_I2C_Status operation.  The driver client must always
    use DRV_I2C_Status to find out when the module is in the ready state.

    Whenever a call to DRV_I2C_Initialize is made with a SYS_MODULE_INIT* data == 0
    the following default configuration will be used.
    Adjust this configuration at build time as needed.

 Example:
    <code>
    DRV_I2C_INIT        i2c_init_data;
    SYS_MODULE_OBJ      objectHandle;

    i2c_init_data.i2cId = DRV_I2C_PERIPHERAL_ID_IDX0,
    i2c_init_data.i2cMode = DRV_I2C_MODE_MASTER,

    OR

    i2c_init_data.i2cMode = DRV_I2C_MODE_SLAVE,
    //Master mode parameters
    i2c_init_data.baudRate = 100000,
    i2c_init_data.busspeed = DRV_I2C_SLEW_RATE_CONTROL_IDX0,
    i2c_init_data.buslevel = DRV_I2C_SMBus_SPECIFICATION_IDX0,

    //Slave mode parameters
    i2c_init_data.addWidth = DRV_I2C_7BIT_SLAVE,
    i2c_init_data.reservedaddenable  = false,
    i2c_init_data.generalcalladdress = false,
    i2c_init_data.slaveaddvalue = 0x0060,

    //interrupt sources
    i2c_init_data.mstrInterruptSource = INT_SOURCE_I2C_2_MASTER,
    i2c_init_data.slaveInterruptSource = INT_SOURCE_I2C_2_ERROR,
    i2c_init_data.errInterruptSource = INT_SOURCE_I2C_2_ERROR,
    i2c_init_data.queueSize = 1,

    //callback for Master (Master mode can use callbacks if needed)
    i2c_init_data.operationStarting = NULL,
    // Slave mode callbacks needed
    i2c_init_data.operationStarting = APP_I2CSlaveFunction(),
    i2c_init_data.operationEnded = NULL

    objectHandle = DRV_I2C_Initialize(DRV_I2C_INDEX_0, (SYS_MODULE_INIT *)&drvI2C0InitData)
    if (SYS_MODULE_OBJ_INVALID == objectHandle)
    {
        // Handle error
    }
   </code>
*/

SYS_MODULE_OBJ DRV_I2C_Initialize ( const SYS_MODULE_INDEX        index,
                                    const SYS_MODULE_INIT * const init );


/*******************************************************************************
  Function:
    void DRV_I2C_Deinitialize ( SYS_MODULE_OBJ object )

  Summary:
    Deinitializes the index instance of the I2C module.
    <p><b>Implementation:</b> Static/Dynamic</p>

  Description:
    This function deinitializes the index instance of the I2C module, disabling
    its operation (and any hardware for driver modules).  It deinitializes only
    the specified module instance.  It also resets all the internal data
    structures and fields for the specified instance to the default settings.

  Precondition:
    The DRV_I2C_Initialize function should have been called before calling this
    function.

  Parameters:
    index       - Index, identifying the instance of the I2C module to be
                  deinitialized

  Returns:
    None.

  Example:
    <code>
    SYS_STATUS   i2c_status;

    DRV_I2C_Deinitialize(I2C_ID_1);

    i2c_status = DRV_I2C_Status(I2C_ID_1);
    if (SYS_STATUS_BUSY == i2c_status)
    {
        // Do something else and check back later
    }
    else if (SYS_STATUS_ERROR >= i2c_status)
    {
        // Handle error
    }
    </code>

  Remarks:
    If the module instance has to be used again, DRV_I2C_Initialize should be
    called again to initialize the module instance structures.

    This function may block if the driver is running in an OS environment that
    supports blocking operations and the driver requires system resources
    access.  However, the routine will NEVER block for hardware I2C access.  If
    the operation requires time to allow the hardware to complete, this will be
    reported by the DRV_I2C_Status operation.  The driver client must always
    use DRV_I2C_Status to find out when the module is in the ready state.
*/

void DRV_I2C_Deinitialize (SYS_MODULE_OBJ object);


/*******************************************************************************
  Function:
    SYS_STATUS DRV_I2C_Status ( SYS_MODULE_OBJ object )

  Summary:
    Provides the current status of the index instance of the I2C module.
    <p><b>Implementation:</b> Dynamic</p>

  Description:
    This function provides the current status of the index instance of the I2C
    module.

  Precondition:
    The DRV_I2C_Initialize function should have been called before calling this
    function.

  Parameters:
    index               - Index, identifying the instance of the I2C module to
                          get status for.

  Returns:
    - SYS_STATUS_READY    - Indicates that any previous module operation for the
                            specified I2Cmodule has completed.

    - SYS_STATUS_BUSY     - Indicates that a previous module operation for the
                            specified I2C module has not yet completed

    - SYS_STATUS_ERROR    - Indicates that the specified I2C module is in an error
                            state

  Example:
    <code>
    SYS_MODULE_OBJ      object;
    SYS_STATUS          i2c_status;

    i2c_status = DRV_I2C_Status(object);
    if (SYS_STATUS_BUSY == i2c_status)
    {
        // Do something else and check back later
    }
    else if (SYS_STATUS_ERROR >= status)
    {
        // Handle error
    }
    </code>

  Remarks:
    The DRV_I2C_Status operation can be used to determine when any of the I2C
    module level operations has completed.  The value returned by the
    DRV_I2C_Status routine hast to be checked after calling any of the I2C
    module operations to find out when they have completed.

    If the DRV_I2C_Status operation returns SYS_STATUS_BUSY, the previous
    operation has not yet completed.  Once the DRV_I2C_Status operation return
    SYS_STATUS_READY, any previous operations have completed.

    The DRV_I2C_Status function will NEVER block.

    If the DRV_I2C_Status operation returns an error value, the error may be
    cleared by calling the DRV_I2C_Initialize operation.  If that fails, the
    DRV_I2C_Deinitialize operation will need to be called, followed by the
    DRV_I2C_Initialize operation to return to normal operations.
*/

SYS_STATUS DRV_I2C_Status (SYS_MODULE_OBJ object);


// *****************************************************************************
/* Function: void DRV_I2C_Tasks (SYS_MODULE_OBJ object)

    Summary:
        Maintains the State Machine of the I2C driver and performs all the
        protocol level actions.
        <p><b>Implementation:</b> Dynamic</p>

    Description:
        This functions maintains the internal state machine of the I2C driver.
        This function acts as the I2C Master or Slave ISR. When used
        in polling mode, this function needs to be called repeatedly to achieve
        I2C data transfer. This function implements all the protocol level
        details like setting the START condition, sending the address with with
        R/W request, writing data to the SFR, checking for acknowledge and
        setting the STOP condition.

    Precondition:
        The DRV_I2C_Initialize routine must have been called for the specified
        I2C device instance. 

    Example:
         SYS_MODULE_OBJ         object;

         while (true)
         {
             DRV_I2C_Tasks ( object );

         }
*/


void DRV_I2C_Tasks (SYS_MODULE_OBJ object);


// *****************************************************************************
// *****************************************************************************
// Section: I2C Driver Client Interface Functions
// *****************************************************************************
// *****************************************************************************

/*******************************************************************************
  Function:
    DRV_HANDLE DRV_I2C_Open ( const I2C_MODULE_ID index,
                              const DRV_IO_INTENT intent )

  Summary:
    Opens the specified instance of the I2C driver for use and provides an
    "open-instance" handle.
    <p><b>Implementation:</b> Dynamic</p>

  Description:
    This function opens the specified instance of the I2C module for use and
    provides a handle that is required to use the remaining driver routines.

    This function opens a specified instance of the I2C module driver for use by
    any client module and provides an "open-instance" handle that must be
    provided to any of the other I2C driver operations to identify the caller
    and the instance of the I2C driver/hardware module.

  Precondition:
    The DRV_I2C_Initialize routine must have been called for the specified I2C
    device instance and the DRV_I2C_Status must have returned SYS_STATUS_READY.

  Parameters:
    index       - Index, identifying the instance of the I2C module to be
                  opened.

    intent      - Flags parameter identifying the intended usage and behavior
                  of the driver.  Multiple flags may be ORed together to
                  specify the intended usage of the device.
                  See the DRV_IO_INTENT definition.


  Returns:
    If successful, the routine returns a valid open-instance handle (a value
    identifying both the caller and the module instance).  If an error occurs,
    the returned value is DRV_HANDLE_INVALID.

    If an error occurs, the return value is DRV_HANDLE_INVALID.
    An error can occur when the following is true:
    - if the number of client objects allocated via DRV_I2C_INSTANCES_NUMBER is insufficient
    - if the client is trying to open the driver but driver has been opened exclusively by another client
    - if the driver hardware instance being opened is not initialized or is invalid


  Example:
    <code>
    DRV_HANDLE              i2c_handle;

    i2c_handle = DRV_I2C_Open(I2C_ID_1, DRV_IO_INTENT_NONBLOCKING|DRV_IO_INTENT_READWRITE);
    if (DRV_HANDLE_INVALID == i2c_handle)
    {
        // Handle open error
    }

    // Close the device when it is no longer needed.
    DRV_I2C_Close(i2c_handle);
    </code>

  Remarks:
    The handle returned is valid until the DRV_I2C_Close routine is called.

    This function may block if the driver is running in an OS environment
    that supports blocking operations and the driver requires system
    resources access.
    Regarding the hardware I2C access the operation will behave
    as instructed by the DRV_IO_INTENT parameter.

*/

DRV_HANDLE DRV_I2C_Open ( const SYS_MODULE_INDEX index, const DRV_IO_INTENT intent );


/*******************************************************************************
  Function:
    void DRV_I2C_Close ( const DRV_HANDLE drvHandle )

  Summary:
    Closes an opened instance of an I2C module driver.
    <p><b>Implementation:</b> Dynamic</p>

  Description:
    This function closes an opened instance of an I2C module driver, making the
    specified handle invalid.

  Precondition:
    The DRV_I2C_Initialize routine must have been called for the specified I2C
    device instance and the DRV_I2C_Status must have returned SYS_STATUS_READY.

    DRV_I2C_Open must have been called to obtain a valid opened device handle.

  Parameters:
    drvHandle   - A valid open-instance handle, returned from the driver's open
                  routine

  Returns:
    None.

  Example:
    <code>
    myI2CHandle = DRV_I2C_Open(I2C_ID_1, DRV_IO_INTENT_NONBLOCKING|DRV_IO_INTENT_READWRITE);

    // Perform data transfer operations

    DRV_I2C_Close(myI2CHandle);
    </code>

  Remarks:
    After calling This function, the handle passed into drvHandle must not be
    used with any of the remaining driver routines.  A new handle must be
    obtained by calling DRV_I2C_Open before the caller may use the driver again.

*/

void DRV_I2C_Close ( DRV_HANDLE handle );


// *****************************************************************************
// *****************************************************************************
// Section: I2C Driver Buffer-Model Data Transfer Functions
// *****************************************************************************
// *****************************************************************************

/*******************************************************************************
  Function:
    DRV_I2C_BUFFER_HANDLE DRV_I2C_Receive   (   DRV_HANDLE handle,
                                                uint16_t slaveaddress,
                                                void *rxBuffer,
                                                size_t size,
                                                void * callbackContext )

  Summary:
    This function reads data written from either Master or Slave.
    <p><b>Implementation:</b> Dynamic</p>

  Description:
    Master calls this function to read data send by Slave. The Slave calls this
    function to read data send by Master.
    In case of Master, a START condition is initiated on the I2C bus.

  Precondition:
    The DRV_I2C_Initialize routine must have been called for the specified I2C
    device instance and the DRV_I2C_Status must have returned SYS_STATUS_READY.

    DRV_I2C_Open must have been called to obtain a valid opened device handle.

  Parameters:
    handle      - A valid open-instance handle, returned from the driver's open
                  routine
    address     - Device address of slave. If this API is used in Slave mode,
                  then a dummy value can be used
    buffer      - This buffer holds data is received
    size        - The number of bytes that the Master expects to read from Slave.
                  This value can be kept as the MAX BUFFER SIZE for slave.
                  This is because the Master controls when the READ operation
                  is terminated.
    callbackContext     - Not implemented, future expansion

  Returns:
    A valid BUFFER HANDLE, NULL if the handle is not obtained.

  Example:
    <code>
    drvI2CRDBUFHandle = DRV_I2C_Receive( drvI2CHandle, 
                                         deviceaddress, 
                                         &rxbuffer[0], 
                                         num_of_bytes, 
                                         NULL );
    </code>

  Remarks:
    The handle that is passed into the function, drvI2CHandle is obtained by 
    calling the DRV_I2C_OPEN function.  If the function could not return a 
    valid buffer handle, then a NULL value is returned.
    If the slave NACKs the address byte, then further read is not attempted. 
    Master asserts STOP condition and DRV_I2C_BUFFER_EVENT_ERROR is set as
    the buffer-status. If all the requisite number of bytes have been read then
    DRV_I2C_BUFFER_EVENT_COMPLETE is set as the buffer status.    
*/

DRV_I2C_BUFFER_HANDLE DRV_I2C_Receive ( DRV_HANDLE handle, 
                                        uint16_t address,
                                        void *buffer,
                                        size_t size,
                                        void * callbackContext );


/*******************************************************************************
  Function:
    DRV_I2C_BUFFER_HANDLE DRV_I2C_Transmit( DRV_HANDLE  handle, 
                                            uint16_t    slaveaddress,
                                            void       *txBuffer,
                                            size_t      size,
                                            void       *context);

  Summary:
    This function writes data to Master or Slave.
    <p><b>Implementation:</b> Dynamic</p>

  Description:
    Master calls this function to write data to Slave. The Slave calls this 
    function to write data to Master.

  Precondition:
    The DRV_I2C_Initialize routine must have been called for the specified I2C
    device instance and the DRV_I2C_Status must have returned SYS_STATUS_READY.

    DRV_I2C_Open must have been called to obtain a valid opened device handle.

  Parameters:
    handle      - A valid open-instance handle, returned from the driver's open
                  routine
    address     - Device address of slave. If this API is used in Slave mode,
                  then a dummy value can be used
    buffer      - Contains data to be transferred
    size        - The number of bytes that the Master expects to write to Slave.
                  This value can be kept as the MAX BUFFER SIZE for slave.
                  This is because the Master controls when the WRITE operation
                  is terminated.
    callbackContext     - Not implemented, future expansion

  Returns:
    A valid BUFFER HANDLE, NULL if the handle is not obtained.

  Example:
    <code>
       drvI2CWRBUFHandle = DRV_I2C_Transmit( drvI2CHandle,
                                             deviceaddress,
                                             &txBuffer[0],    
                                             num_of_bytes, 
                                             NULL);
    </code>

  Remarks:
    The handle that is passed into the function, drvI2CHandle is obtained by 
    calling the DRV_I2C_OPEN function.  If the function could not return a 
    valid buffer handle, then a NULL value is returned.
    If the slave NACKs the address byte or any data bytes, then further write  
    is not attempted. Master asserts STOP condition and 
    DRV_I2C_BUFFER_EVENT_ERROR is set as the buffer-status. 
    If all the requisite number of bytes have been transmitted to the Slave, 
    then DRV_I2C_BUFFER_EVENT_COMPLETE is set as the buffer status.  
*/

DRV_I2C_BUFFER_HANDLE DRV_I2C_Transmit ( DRV_HANDLE handle,
                                         uint16_t   slaveaddress,
                                         void      *buffer,
                                         size_t     size, 
                                         void      *context);


/*******************************************************************************
  Function:
    DRV_I2C_BUFFER_HANDLE DRV_I2C_TransmiThenReceive ( DRV_HANDLE handle,
                                                       uint16_t   deviceaddress,
                                                       void       *txBuffer,
                                                       size_t     writeSize,
                                                       void       *rxBuffer,
                                                       size_t     readSize,
                                                       void       *context)

  Summary:
    This function writes data to Slave, inserts restart and requests read from
    slave.
    <p><b>Implementation:</b> Dynamic</p>

  Description:
    Master calls this function to send a register address value to the slave and
    then queries the slave with a read request to read the contents indexed by
    the register location. The Master sends a restart condition after the
    initial write before sending the device address with R/W = 1. The restart
    condition prevents the Master from relinquishing the control of the bus. The
    slave should not use this function.

  Precondition:
    The DRV_I2C_Initialize routine must have been called for the specified I2C
    device instance and the DRV_I2C_Status must have returned SYS_STATUS_READY.

    DRV_I2C_Open must have been called to obtain a valid opened device handle.

  Parameters:
    handle      - A valid open-instance handle, returned from the driver's open
                  routine
    address     - Device address of slave. If this API is used in Slave mode,
                  then a dummy value can be used
    writeBuffer - Contains data to be transferred
    writeSize   - The number of bytes that the Master expects to write to Slave.
                  This value can be kept as the MAX BUFFER SIZE for slave.
                  This is because the Master controls when the WRITE operation
                  is terminated.
    readBuffer  - This buffer holds data that is send back from slave after
                  read operation.
    readSize       - The number of bytes the Master expects to be read from the
                  slave
    callbackContext     - Not implemented, future expansion

  Returns:
    A valid BUFFER HANDLE, NULL if the handle is not obtained.

  Example:
    <code>
        drvI2CRDBUFHandle = DRV_I2C_TransmiThenReceive( appData.drvI2CHandle,
                                                        deviceaddress,
                                                        &drvI2CTXbuffer[0], 
                                                        registerbytesize,
                                                        rxbuffer, 
                                                        num_of_bytes, 
                                                        NULL );
    </code>

  Remarks:
    The handle that is passed into the function, drvI2CHandle is obtained by 
    calling the DRV_I2C_OPEN function.  If the function could not return a 
    valid buffer handle, then a NULL value is returned. 
    If there is any error condition during transmission then further
    transmission or reception is not attempted and STOP condition is asserted
    on the bus. In case of error condition, DRV_I2C_BUFFER_EVENT_ERROR is
    set as the buffer-status. 
    If the I2C bus transaction is completed as requested then the buffer status, 
    is set as DRV_I2C_BUFFER_EVENT_COMPLETE. 
*/

DRV_I2C_BUFFER_HANDLE DRV_I2C_TransmitThenReceive ( DRV_HANDLE  handle, 
                                                    uint16_t    address,
                                                    void       *writeBuffer,
                                                    size_t      writeSize,
                                                    void       *readBuffer,
                                                    size_t      readSize,
                                                    void       *callbackContext );

/*******************************************************************************
  Function:
DRV_I2C_BUFFER_HANDLE DRV_I2C_TransmitForced ( DRV_HANDLE handle, 
                                               uint16_t deviceaddress, 
                                               uint8_t* txBuffer,   
                                               uint16_t txbuflen, 
                                               DRV_I2C_BUS_ERROR_EVENT eventFlag, 
                                               void * calbackContext)

  Summary:
    This function writes data to Master or Slave.
    <p><b>Implementation:</b> Dynamic</p>

  Description:
    Master calls this function to transmit the entire buffer to the slave even
    if the slave ACKs or NACKs the address or any of the data bytes. This is 
    typically used for slaves that have to initiate a reset sequence by sending
    a dummy I2C transaction. Since the slave is still in reset, any or all the 
    bytes can be NACKed. In the normal operation of the driver if the address 
    or data byte is NACKed, then the transmission is aborted and a STOP condition
    is asserted on the bus.

  Precondition:
    The DRV_I2C_Initialize routine must have been called for the specified I2C
    device instance and the DRV_I2C_Status must have returned SYS_STATUS_READY.

    DRV_I2C_Open must have been called to obtain a valid opened device handle.

  Parameters:
    handle      - A valid open-instance handle, returned from the driver's open
                  routine
    address     - Device address of slave. If this API is used in Slave mode,
                  then a dummy value can be used
    buffer      - Contains data to be transferred
    size        - The number of bytes that the Master expects to write to Slave.
                  This value can be kept as the MAX BUFFER SIZE for slave.
                  This is because the Master controls when the WRITE operation
                  is terminated.
    eventFlag   - This field is left for future implementation
    callbackContext     - Not implemented, future expansion

  Returns:
    A valid BUFFER HANDLE, NULL if the handle is not obtained.

  Example:
    <code>
       drvI2CWRBUFHandle = DRV_I2C_TransmitForced ( handle, 
                                                    deviceaddress, 
                                                    &txBuffer[0],   
                                                    txbuflen, 
                                                    NULL, 
                                                    NULL)
    </code>

  Remarks:
    The handle that is passed into the function, drvI2CHandle is obtained by 
    calling the DRV_I2C_OPEN function.  If the function could not return a 
    valid buffer handle, then a NULl value is returned.
    Once all the bytes are transferred the buffer status is set as             
    then DRV_I2C_BUFFER_EVENT_COMPLETE .  
*/

DRV_I2C_BUFFER_HANDLE DRV_I2C_TransmitForced ( DRV_HANDLE handle, 
                                               uint16_t deviceaddress, 
                                               void* txBuffer,   
                                               size_t txbuflen, 
                                               DRV_I2C_BUS_ERROR_EVENT eventFlag, 
                                               void * calbackContext);


/*****************************************************************************
  Function:
    DRV_I2C_BUFFER_EVENT DRV_I2C_TransferStatusGet ( DRV_HANDLE handle,
                             DRV_I2C_BUFFER_HANDLE bufferHandle )

  Summary:
    Returns status of data transfer when Master or Slave acts either as a
    transmitter or a receiver.
    <p><b>Implementation:</b> Dynamic</p>

  Description:
    The bufferHandle parameter contains the buffer handle of the buffer that
    associated with the event.
    If the event is DRV_I2C_BUFFER_EVENT_COMPLETE, it means that the data was
    transferred successfully.
    If the event is DRV_I2C_BUFFER_EVENT_ERROR, it means that the data was not
    transferred successfully.

  Parameters:
    handle          -  A valid open-instance handle, returned from the driver's 
                       open routine 
    bufferHandle    -  A valid buffer handle obtained when calling   
                       Transmit/Receive/TransmitThenReceive/TransmitForced or
                       BufferAddRead/BufferAddWrite/BufferAddReadWrite function
  
  Returns:
    A DRV_I2C_TRANSFER_STATUS value describing the current status of the
    transfer.

    Example:
    <code>
    if(DRV_I2C_BUFFER_EVENT_COMPLETE == DRV_I2C_TransferStatusGet ( handle,
                                                                    bufferHandle ))
    {
            //perform action
            return true;
    }
    else
    {
            //perform action
            return false;
    }
    </code>
   
   Remarks:
    The handle that is passed into the function, drvI2CBUFHandle is obtained by 
    calling one of the data transfer functions. The drvI2CBUFHandle should be 
    a valid handle and not a NULL value. The DRV_I2C_BufferStatus can be
    called to check the progress of the data transfer operation. If the buffer 
    is transferred without any error, then DRV_I2C_BUFFER_EVENT_COMPLETE is 
    returned. If an error condition is present, then DRV_I2C_BUFFER_EVENT_ERROR 
    is returned.
*/

DRV_I2C_BUFFER_EVENT DRV_I2C_TransferStatusGet ( DRV_HANDLE handle,
                         DRV_I2C_BUFFER_HANDLE bufferHandle );


// *****************************************************************************
/* Function:
    uint32_t DRV_I2C_BytesTransferred ( DRV_I2C_BUFFER_HANDLE bufferHandle )

  Summary:
    Returns the number of bytes transmitted or received in a particular I2C 
    transaction. The transaction is identified by the handle.

  Description:
    This returns the transmitter and receiver transfer status.

  Parameters:
    handle          -  A valid open-instance handle, returned from the driver's 
                       open routine 
    bufferHandle    -  A valid buffer handle obtained when calling   
                       Transmit/Receive/TransmitThenReceive/TransmitForced or
                       BufferAddRead/BufferAddWrite/BufferAddReadWrite function

  Returns:
    The number of bytes transferred in a particular I2C transaction. 
 
   <code>
   
   numOfBytes = DRV_I2C_BytesTransferred (drvI2CHandle_Master,drvBufferHandle);
  
   </code>
  
*/

uint32_t DRV_I2C_BytesTransferred ( DRV_HANDLE handle,
                                    DRV_I2C_BUFFER_HANDLE bufferHandle );


/*****************************************************************************
    Function:
    void DRV_I2C_BufferEventHandlerSet (
                    const DRV_HANDLE handle,
                    const DRV_I2C_BUFFER_EVENT_HANDLER eventHandler,
                    const uintptr_t context )

  Summary:
    Allows a client to identify a buffer event handling function for the driver
    to call back when queued buffer transfers have finished.
    <p><b>Implementation:</b> Dynamic</p>

  Description:
This function allows a client to identify a buffer event handling function
    for the driver to call back when queued buffer transfers have finished.
    When a client calls either the DRV_I2C_BufferAddRead, 
    DRV_I2C_BufferAddWrite or DRV_I2C_BufferAddWriteRead function, it is provided 
    with a handle identifying the buffer that was added to the driver's buffer queue.  
    The driver will pass this handle back to the client by calling 
    "eventHandler" function when the buffer transfer has completed.

    The event handler should be set before the client performs any "buffer add"
    operations that could generate events. The event handler once set, persists
    until the client closes the driver or sets another event handler (which
    could be a "NULL" pointer to indicate no callback).
    
    When in Master mode, a callback event is registered when to let the 
    application know that the buffer has been transmitted. 
    DRV_I2C_BUFFER_EVENT_COMPLETE is set when the buffer has been transmitted
    without any errors.
    DRV_I2C_BUFFER_EVENT_ERROR is set when buffer transmission or reception has
    been aborted.
     
    When in Slave mode, since the Master controls when a transmit or receive 
    operation is terminated, a callback is registered every time a byte is
    written or read from the slave.

  Precondition:
    The DRV_I2C_Initialize routine must have been called for the specified
    I2C driver instance.

    DRV_I2C_Open must have been called to obtain a valid opened device handle.

  Parameters:
    handle       - A valid open-instance handle, returned from the driver's
                   open routine

    eventHandler - Pointer to the event handler function.

    context      - The value of parameter will be passed back to the client
                   unchanged, when the eventHandler function is called.  It can
                   be used to identify any client specific data object that
                   identifies the instance of the client module (for example,
                   it may be a pointer to the client module's state structure).

  Returns:
    None.

  Example:
    <code>
    #define MY_BUFFER_SIZE  10
    
    // function prototype of Event Handler Function
    void APP_I2CBufferEventFunction ( DRV_I2C_BUFFER_EVENT event,
                                      DRV_I2C_BUFFER_HANDLE bufferHandle,
                                      uintptr_t context );
    
    //Returned from DRV_I2C_Open
    DRV_HANDLE drvI2Chandle;  
    
    // myAppObj is an application specific state data object.
    DRV_I2C_BUFFER_EVENT operationStatus;
    
    uint8_t appBuffer[MY_BUFFER_SIZE];
	
    DRV_I2C_BUFFER_HANDLE drvI2CRDBUFHandle

    // Opens an instance of I2C driver
    drvI2Chandle = DRV_I2C_Open( DRV_I2C_INDEX_0,DRV_IO_INTENT_WRITE );

    // Client registers an event handler with driver. This is done once.
    DRV_I2C_BufferEventHandlerSet( drvI2Chandle, 
                                   APP_I2CBufferEventFunction,
                                   operationStatus );

    drvI2CRDBUFHandle = DRV_I2C_Receive (   drvI2CHandle, 
                                            slaveaddress
                                            &appBuffer[], 
                                            MY_BUFFER_SIZE, 
                                            NULL );

    if(NULL == drvI2CRDBUFHandle)
    {
        // Error handling here
    }

    // Event Processing Technique. Event is received when
    // the buffer is processed.

    void APP_I2CBufferEventFunction( DRV_I2C_BUFFER_EVENT event,
                                     DRV_I2C_BUFFER_HANDLE handle, 
                                     uintptr_t context)
    {

        switch(event)
		{
			case DRV_I2C_BUFFER_EVENT_COMPLETE:
                //perform appropriate action
			break;

            case DRV_I2C_BUFFER_EVENT_ERROR:
                // Error handling here.
            break;

            default:
                break;
        }
    }
    </code>

  Remarks:
    If the client does not want to be notified when the queued buffer transfer
    has completed, it does not need to register a callback. This function is
    thread safe when called in a RTOS application.
*/

void DRV_I2C_BufferEventHandlerSet (
                const DRV_HANDLE handle,
                const DRV_I2C_BUFFER_EVENT_HANDLER eventHandler,
                const uintptr_t context );


// *****************************************************************************
/* Function:
    void DRV_I2C_QueueFlush ( DRV_HANDLE handle )

  Summary:
    The existing transactions in the queue are voided and the queue   
    pointers are reset to their initial state. This renders the queue
    empty.

  Description:
    The existing transactions in the queue are voided and the queue   
    pointers are reset to their initial state. This renders the queue
    empty.

  Parameters:
    handle          -  A valid open-instance handle, returned from the driver's 
                       open routine 

  Returns:
    None
 
   <code>
       //Opens an instance of I2C driver
    drvI2Chandle = DRV_I2C_Open( DRV_I2C_INDEX_0,DRV_IO_INTENT_WRITE );
    
    DRV_I2C_QueueFlush ( drvI2CHandle );
  
   </code>
  
*/

void DRV_I2C_QueueFlush ( DRV_HANDLE handle );


#include "drv_i2c_compatibility.h"


// DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
// DOM-IGNORE-END


#endif // _DRV_I2C_H_

/*******************************************************************************
 End of File
*/


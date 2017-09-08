/*******************************************************************************
  MPLAB Harmony Project Main Source File

  Company:
    Microchip Technology Inc.
  
  File Name:
    main.c

  Summary:
    This file contains the "main" function for an MPLAB Harmony project.

  Description:
    This file contains the "main" function for an MPLAB Harmony project.  The
    "main" function calls the "SYS_Initialize" function to initialize the state 
    machines of all MPLAB Harmony modules in the system and it calls the 
    "SYS_Tasks" function from within a system-wide "super" loop to maintain 
    their correct operation. These two functions are implemented in 
    configuration-specific files (usually "system_init.c" and "system_tasks.c")
    in a configuration-specific folder under the "src/system_config" folder 
    within this project's top-level folder.  An MPLAB Harmony project may have
    more than one configuration, each contained within it's own folder under
    the "system_config" folder.
 *******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
Copyright (c) 2013-2014 released Microchip Technology Inc.  All rights reserved.

//Microchip licenses to you the right to use, modify, copy and distribute
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
// DOM-IGNORE-END


// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include <xc.h>
#include <stddef.h>                     // Defines NULL
#include <stdbool.h>                    // Defines true
#include <stdlib.h>
#include <proc/p32mx150f128b.h>                     // Defines EXIT_FAILURE
#include "system/common/sys_module.h"   // SYS function prototypes
#include "sys/kmem.h"                   // KVA_TO_PA macro
#include "main.h"

void init_i2s1();
void delay_ms(unsigned int count);
void i2s_init_DMA();
void timer3_init();
void generate_sine();

extern const short wavetable[];

extern short buffer_a[BUFFER_SIZE];
extern short buffer_b[BUFFER_SIZE];
extern short* buffer_pp;            // buffer_pp = buffer play pointer.

extern unsigned char isPlaying;
extern unsigned char isFillFlag;
extern unsigned char buffer_position;

extern unsigned long time_play;  // note duration.
extern unsigned long time_play_count;
extern unsigned long songIndex;

// test variables - for debugging purposes only!
unsigned long accumTest_m = 0;
unsigned long tempTest_m = 0;
unsigned long tuningWordTest_m = 39370533;
//--------------------------------------------------

extern volatile unsigned char isUpdateNote;

// *****************************************************************************
// *****************************************************************************
// Section: Main Entry Point
// *****************************************************************************
// *****************************************************************************

int main ( void )
{
    /* Initialize all MPLAB Harmony modules, including application(s). */
    SYS_Initialize ( NULL );
    
    TRISA = 0x0000;
    TRISB = 0x0000;
    PORTA = 0x0000;
    
    init_i2s1();
    
    delay_ms(50);
    
    // Fill all buffers first at start.
    buffer_pp = &buffer_a[0];
    channel1_generate();
    buffer_pp = &buffer_b[0];
    channel1_generate();
    
    i2s_init_DMA();
    
    DCH0SSA = KVA_TO_PA(&buffer_a[0]); // DMA source address.
        
    DCH0ECONbits.CFORCE = 1;
    
    time_play_count = 0;
    time_play = 1000;
    songIndex = 0;
    timer3_init();

    while ( true )
{
        /* Maintain state machines of all polled MPLAB Harmony modules. */
         if (isPlaying == 1) {
            if (isFillFlag == 1) {
                if (buffer_position == 1) {
                    DCH0SSA = KVA_TO_PA(&buffer_b[0]); // DMA source address.
                    DCH0ECONbits.CFORCE = 1;
                    buffer_pp = &buffer_a[0];
                    channel1_generate();
                    //generate_sine();
                } else {
                    DCH0SSA = KVA_TO_PA(&buffer_a[0]); // DMA source address.
                    DCH0ECONbits.CFORCE = 1;
                    buffer_pp = &buffer_b[0];
                    channel1_generate();
                    //generate_sine();
                }
                isFillFlag = 0;
            }
            if(isUpdateNote) {
                updateNote();
                isUpdateNote = 0;
            }
        } else {
            LATASET = 0x0001;
            //asm PWRSAV#0;                 // Sleep mode. (dsPIC33F - mikroC)
            asm volatile("wait");           // Sleep mode. (PIC32MX - xc32)
        }
    }

    /* Execution should not come here during normal operation */

    return ( EXIT_FAILURE );
}

void init_i2s1() {
    // http://chipkit.net/forum/viewtopic.php?f=6&t=3137&start=10
    /* The following code example will initialize the SPI1 Module in I2S Master mode. */
    /* It assumes that none of the SPI1 input pins are shared with an analog input. */
    unsigned int rData;
    IEC0CLR = 0x03800000; // disable all interrupts
    SPI1CON = 0; // Stops and resets the SPI1.
    SPI1CON2 = 0; // Reset audio settings
    SPI1BRG = 0; // Reset Baud rate register
    rData = SPI1BUF; // clears the receive buffer
    //IFS0CLR = 0x03800000; // clear any existing event
    //IPC5CLR = 0x1f000000; // clear the priority
    //IPC5SET = 0x0d000000; // Set IPL = 3, Subpriority 1
    //IEC0SET = 0x03800000; // Enable RX, TX and Error interrupts
    
    SPI1STATCLR = 0x40; // clear the Overflow
    SPI1CON2 = 0x00000080; // I2S Mode, AUDEN = 1, AUDMON = 0
    SPI1CON2bits.IGNROV = 1; // Ignore Receive Overflow bit (for Audio Data Transmissions)
    SPI1CON2bits.IGNTUR = 1; //  Ignore Transmit Underrun bit (for Audio Data Transmissions) 1 = A TUR is not a critical error and zeros are transmitted until thSPIxTXB is not empty 0 = A TUR is a critical error which stop SPI operation
    
    //SPI1CONbits.ENHBUF = 1; // 1 = Enhanced Buffer mode is enabled
    SPI1BRG = 7;
    SPI1CON = 0x00000060; // Master mode, SPI ON, CKP = 1, 16-bit audio channel
    SPI1CONbits.STXISEL = 0b11;
    SPI1CONbits.DISSDI = 1; // 0 = Disable SDI bit
    SPI1CONSET = 0x00008000;
    
    IFS1CLR = 0x000000f0;
    IPC7CLR = 0x1F000000;
    IPC7SET = 0x1C000000;
    
    IEC1bits.SPI1TXIE = 0;
    IFS1bits.SPI1TXIF = 0;

    // data, 32 bits per frame
    // from here, the device is ready to receive and transmit data
    /* Note: A few of bits related to frame settings are not required to be set in the SPI1CON */
    /* register during audio mode operation. Please refer to the notes in the SPIxCON2 register.*/

}

void i2s_init_DMA(void) {
    IEC1bits.DMA0IE = 1;
    IFS1bits.DMA0IF = 0;
    DMACONSET = 0x8000; // enable DMA.
    DCH0CON = 0x0000;
    DCRCCON = 0x00; // 
    DCH0INTCLR = 0xff00ff; // clear DMA interrupts register.
    DCH0INTbits.CHBCIE = 1; // DMA Interrupts when channel block transfer complete enabled.
    DCH0ECON = 0x00;
    DCH0SSA = KVA_TO_PA(&buffer_pp); // DMA source address.
    DCH0DSA = KVA_TO_PA(&SPI1BUF); // DMA destination address.
    DCH0SSIZ = BUFFER_SIZE*2; // DMA Source size (default).
    DCH0DSIZ = 2;   // DMA destination size.
    DCH0CSIZ = 2;   // DMA cell size.
    DCH0ECONbits.CHSIRQ = _SPI1_TX_IRQ; // DMA transfer triggered by which interrupt? (On PIC32MX - it is by _IRQ suffix!)
    DCH0ECONbits.AIRQEN = 0; // do not enable DMA transfer abort interrupt.
    DCH0ECONbits.SIRQEN = 1; // enable DMA transfer start interrupt.
    DCH0CONbits.CHAEN = 1; // DMA Channel 0 is always enabled right after the transfer.
    DCH0CONbits.CHEN = 1;  // DMA Channel 0 is enabled. 
}

void delay_ms(unsigned int count)
{
	T1CON = 0x8030;		// turn on timer, prescaler to 256 (type B timer)
	while(count--)
	{
		TMR1 = 0;
		while(TMR1 < 0x4e);
	}
	T1CONbits.ON = 0;
}

void timer3_init() {
    T3CON = 0x00;
    T3CONbits.TON = 0;
    TMR3 = 0x00;
    PR3 = 20000;       //  1ms timer3. 
    T3CONbits.TGATE = 0;
    T3CONbits.TCKPS1 = 0;  // 1:1 prescale value
    T3CONbits.TCKPS0 = 0;
    T3CONbits.TCS = 0;     // internal clock
    IFS0bits.T3IF = 0;
    IEC0bits.T3IE = 1;     // timer3 interrupt enabled!
    IPC3bits.T3IP = 6;
    IPC3bits.T3IS = 0;
    T3CONbits.TON = 1;

    
    
}

void generate_sine() {
    
    unsigned int i = 0;
    for(i = 0; i < BUFFER_SIZE/2; i++) {
        accumTest_m += tuningWordTest_m;                  // generating modulator for 1st channel.
        tempTest_m = (long)wavetable[accumTest_m >> 20];
        buffer_pp[2*i]   = tempTest_m;    // One channel.
        buffer_pp[2*i+1] = tempTest_m;    // the Other channel!
        
    }
    
}
/*******************************************************************************
 End of File
*/

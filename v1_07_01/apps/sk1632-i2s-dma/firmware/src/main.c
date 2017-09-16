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

extern short buffer_a[BUFFER_LENGTH];
extern short buffer_b[BUFFER_LENGTH];
extern short* buffer_pp;            // buffer_pp = buffer play pointer.

extern unsigned char isPlaying;
extern unsigned char isFillFlag;
extern unsigned char buffer_position;

extern volatile unsigned char bufferAFull;
extern volatile unsigned char bufferBFull;

extern unsigned long time_play;  // note duration.
extern unsigned long time_play_count;
extern unsigned long songIndex;

// test variables - for debugging purposes only!
unsigned long accum1t = 0;
unsigned long accum2t = 0;
unsigned long tuningWord1t = 236223201;
unsigned long tuningWord2t = 236223201;
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
    
    // Fill all buffers first at start.
    buffer_pp = &buffer_a[0];
    channel1_generate();
    buffer_pp = &buffer_b[0];
    channel1_generate();
    
    delay_ms(5);
        
    init_i2s1();
    i2s_init_DMA();
   
    // Trigger the DMA to start the transfer by switching the SPI1 transmit complete interrupt flag up.
    IFS1bits.SPI1TXIF = 1;
    
    time_play_count = 0;
    time_play = 1000;
    songIndex = 0;
    timer3_init();

    while (true) {
        /* Maintain state machines of all polled MPLAB Harmony modules. */
        if (isPlaying == 1) {

            // source: http://chipkit.net/forum/viewtopic.php?t=3137
            if (bufferAFull == 0) {
                buffer_pp = &buffer_a[0];
                channel1_generate();
                bufferAFull = 1;
            }
            if (bufferBFull == 0) {
                buffer_pp = &buffer_b[0];
                channel1_generate();
                bufferBFull = 1;
            }
        if (isUpdateNote) {
                updateNote();
                isUpdateNote = 0;
            }
        } else {
            LATASET = 0x0001;
            SPI1CON = 0;           // Stops and resets the SPI1.
            DCH0INTCLR = 0xff00ff; // clear DMA0 interrupts register.
            DCH1INTCLR = 0xff00ff; // clear DMA1 interrupts register.
            DCH0CONbits.CHEN = 0;  // DMA Channel 0 is disabled. 
            DCH0CONbits.CHEN = 0;  // DMA Channel 1 is disabled. 
            DMACONCLR = 0x8000; // disable entire DMA.
            
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
    IFS1bits.SPI1TXIF = 0;
    SPI1CON = 0; // Stops and resets the SPI1.
    SPI1CON2 = 0; // Reset audio settings
    SPI1BRG = 0; // Reset Baud rate register
    rData = SPI1BUF; // clears the receive buffer
    
    SPI1STATCLR = 0x40; // clear the Overflow
    SPI1CON2 = 0x00000080; // I2S Mode, AUDEN = 1, AUDMON = 0
    SPI1CON2bits.IGNROV = 1; // Ignore Receive Overflow bit (for Audio Data Transmissions)
    SPI1CON2bits.IGNTUR = 1; //  Ignore Transmit Underrun bit (for Audio Data Transmissions) 1 = A TUR is not a critical error and zeros are transmitted until thSPIxTXB is not empty 0 = A TUR is a critical error which stop SPI operation
    
    SPI1CONbits.ENHBUF = 1; // 1 = Enhanced Buffer mode is enabled
    SPI1BRG = 9;
    SPI1CON = 0x00000060; // Master mode, SPI ON, CKP = 1, 16-bit audio channel
    SPI1CONbits.STXISEL = 0b11;
    SPI1CONbits.DISSDI = 1; // 0 = Disable SDI bit
    SPI1CONSET = 0x00008000;
    
    IFS1CLR = 0x000000f0;
    IPC7CLR = 0x1F000000;
    IPC7SET = 0x1C000000;
    
    IEC1bits.SPI1TXIE = 0;


    // data, 32 bits per frame
    // from here, the device is ready to receive and transmit data
    /* Note: A few of bits related to frame settings are not required to be set in the SPI1CON */
    /* register during audio mode operation. Please refer to the notes in the SPIxCON2 register.*/
}

void i2s_init_DMA(void) {
    DMACONCLR = 0x8000; // disable entire DMA.
    IEC1bits.DMA0IE = 1;
    IFS1bits.DMA0IF = 0;
    IPC10bits.DMA0IP = 7;   // Setting DMA0 at highest priority.
    IPC10bits.DMA0IS = 3;   // Setting DMA0 at highest sub-priority.
    DMACONSET = 0x8000; // enable DMA.
    DCH0CON = 0x0000;
    DCRCCON = 0x00; // 
    DCH0INTCLR = 0xff00ff; // clear DMA0 interrupts register.
    DCH0INTbits.CHSDIE = 1; // DMA0 Interrupts when source done enabled.
    DCH0ECON = 0x00;
    DCH0SSA = KVA_TO_PA(&buffer_a[0]); // DMA0 source address.
    DCH0DSA = KVA_TO_PA(&SPI1BUF); // DMA0 destination address.
    DCH0SSIZ = BUFFER_LENGTH*2; // DMA0 Source size (default).
    DCH0DSIZ = 2;   // DMA0 destination size.
    DCH0CSIZ = 2;   // DMA0 cell size.
    DCH0ECONbits.CHSIRQ = _SPI1_TX_IRQ; // DMA0 transfer triggered by which interrupt? (On PIC32MX - it is by _IRQ suffix!)
    DCH0ECONbits.AIRQEN = 0; // do not enable DMA0 transfer abort interrupt.
    DCH0ECONbits.SIRQEN = 1; // enable DMA0 transfer start interrupt.
    DCH0CONbits.CHAEN = 0; // DMA Channel 0 is always disabled right after the transfer.
    DCH0CONbits.CHEN = 1;  // DMA Channel 0 is enabled. 
    
    IEC1bits.DMA1IE = 1;
    IFS1bits.DMA1IF = 0;
    IPC10bits.DMA1IP = 7;   // Setting DMA1 at highest priority.
    IPC10bits.DMA1IS = 3;   // Setting DMA1 at highest sub-priority.
    DCH1CON = 0x0000;
    DCH1INTCLR = 0xff00ff; // clear DMA1 interrupts register.
    DCH1INTbits.CHSDIE = 1; // DMA1 Interrupts when source done enabled.
    DCH1ECON = 0x00;
    DCH1SSA = KVA_TO_PA(&buffer_b[0]); // DMA1 source address.
    DCH1DSA = KVA_TO_PA(&SPI1BUF); // DMA1 destination address.
    DCH1SSIZ = BUFFER_LENGTH*2; // DMA1 Source size (default).
    DCH1DSIZ = 2;   // DMA1 destination size.
    DCH1CSIZ = 2;   // DMA1 cell size.
    DCH1ECONbits.CHSIRQ = _SPI1_TX_IRQ; // DMA1 transfer triggered by which interrupt? (On PIC32MX - it is by _IRQ suffix!)
    DCH1ECONbits.AIRQEN = 0; // do not enable DMA1 transfer abort interrupt.
    DCH1ECONbits.SIRQEN = 1; // enable DMA1 transfer start interrupt.
    DCH1CONbits.CHAEN = 0; // DMA Channel 1 is always disabled right after the transfer.
    DCH1CONbits.CHEN = 0;  // DMA Channel 1 is enabled.  
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

// Generate_sine is for debugging purposes only!
void generate_sine() {
    
    //source: https://github.com/pyrohaz
  unsigned int n = 0;
  short int sample = 0;
  for (n = 0; n < BUFFER_LENGTH; n++) {
    
    if (n & 0x01) {
      //sample = (short int)wavetable[accum1t >> 20];
      sample = 0;
      accum1t += tuningWord1t;
    }
    else {
      sample = (short int)wavetable[accum2t >> 20];
      accum2t += tuningWord2t;
    }

    buffer_pp[n] = sample;

  }
    
}
/*******************************************************************************
 End of File
*/


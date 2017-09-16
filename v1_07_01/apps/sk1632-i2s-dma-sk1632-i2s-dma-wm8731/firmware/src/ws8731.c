#include <xc.h>
#include "ws8731.h"

extern void delay_ms(unsigned int count);

// I2C1 related functions here:
// ------------------------------------------------------
void init_i2c() {
    I2C1CON = 0x000;
    I2C1CONbits.DISSLW = 1;
    I2C1CONbits.SMEN = 0;
    //I2C1ADD = 0b11010000;
    I2C1BRG = 0x60;   // 100kHz clock
    I2C1CONbits.A10M = 0;
    I2C1CONbits.ON = 1;
}

void i2c_wait() {
    // Debugging purposes only!
    //printf("BCL: %d\n", I2C1STATbits.BCL);
    //printf("IWCOL: %d\n", I2C1STATbits.IWCOL);
    //printf("IWCOV: %d\n", I2C1STATbits.I2COV);
    
    //while (I2C1CONbits.SEN || I2C1CONbits.PEN || I2C1CONbits.RSEN || I2C1CONbits.RCEN || I2C1CONbits.ACKEN
    //        || I2C1STATbits.TRSTAT);
    // https://electrosome.com/i2c-pic-microcontroller-mplab-xc8/
    while ((I2C1STAT & 0x4000) || (I2C1CON & 0x001F));  
}

void i2c_start() {
    i2c_wait();
    I2C1CONbits.SEN = 1;
}

void i2c_restart() {
    i2c_wait();
    I2C1CONbits.RSEN = 1;
}

void i2c_stop() {
    i2c_wait();
    I2C1CONbits.PEN = 1;
}

void i2c_write(unsigned char data) {
    i2c_wait();
    I2C1TRN = data;
}

void i2c_address(unsigned char address, unsigned char mode) {
    unsigned char l_address;

    l_address = address << 1;
    l_address |= mode;
    i2c_write(l_address);

}

unsigned char i2c_read(unsigned char ack) {

    unsigned char i2cReadData;

    i2c_wait();
    I2C1CONbits.RCEN = 1;
    i2c_wait();
    i2cReadData = I2C1RCV;
    i2c_wait();
    if (ack) I2C1CONbits.ACKDT = 0;
    else I2C1CONbits.ACKDT = 1;

    I2C1CONbits.ACKEN = 1;

    return i2cReadData;

}

// ------------------------------------------------------

// WM8731 Drivers - from MIKROE LIBSTOCK: https://libstock.mikroe.com/projects/view/304/wm8731-example
/**************************************************************************************************
* WM8731 sound chip register addresses
**************************************************************************************************/
const WM8731_ADDRESS             = 0x34;       // WM8731 chip address on I2C bus
const WM8731_REG_LLINE_IN        = 0x00;       // Left Channel Line Input Volume Control
const WM8731_REG_RLINE_IN        = 0x01;       // Right Channel Line Input Volume Control
const WM8731_REG_LHPHONE_OUT     = 0x02;       // Left Channel Headphone Output Volume Control
const WM8731_REG_RHPHONE_OUT     = 0x03;       // Right Channel Headphone Output Volume Control
const WM8731_REG_ANALOG_PATH     = 0x04;       // Analog Audio Path Control
const WM8731_REG_DIGITAL_PATH    = 0x05;       // Digital Audio Path Control
const WM8731_REG_PDOWN_CTRL      = 0x06;       // Power Down Control Register
const WM8731_REG_DIGITAL_IF      = 0x07;       // Digital Audio Interface Format
const WM8731_REG_SAMPLING_CTRL   = 0x08;       // Sampling Control Register
const WM8731_REG_ACTIVE_CTRL     = 0x09;       // Active Control
const WM8731_REG_RESET           = 0x0F;       // Reset register

/**************************************************************************************************
* WM8731 sound chip constants (for default set up)
**************************************************************************************************/
const _WM8731_LEFT_LINEIN        = 0X0180;     // MIC SETTINGS: ENABLE MUTE, ENABLE SIMULTANEOUS LOAD TO LEFT AND RIGHT CHANNELS
const _WM8731_RIGHT_LINEIN       = 0X0180;     // MIC SETTINGS: ENABLE MUTE, ENABLE SIMULTANEOUS LOAD TO LEFT AND RIGHT CHANNELS
const _WM8731_LEFT_HP            = 0X00F0;     // HEADPHONE SETTINGS : -9DB OUTPUT
const _WM8731_RIGHT_HP           = 0X00F0;     // HEADPHONE SETTINGS : -9DB OUTPUT
const _WM8731_ANALOGAUDIO        = 0XD0;       // DAC SELECT
const _WM8731_DIGITALAUDIO       = 0X00;
const _WM8731_POWER              = 0X00;       // DISABLE POWER DOWN
const _WM8731_DAIF               = 0X42;       // ENABLE MASTER MODE AND 16BIT DATA
const _WM8731_SAMPLING           = 0X18;       // 32000HZ,12.288MHz oscillator.
const _WM8731_ACTIVATE           = 0X01;       // MODULE IS ON
const _WM8731_DEACTIVATE         = 0X00;       // MODULE IS OFF
const _WM8731_RESET              = 0X00;       // RESET VALUE

/**************************************************************************************************
* Function WM8731_CMD
* -------------------------------------------------------------------------------------------------
* Overview: Function write word of data to WM8731
* Input: register address, data
* Output: Nothing
**************************************************************************************************/
void WM8731_CMD(unsigned char address, unsigned short cmd){
unsigned char addr;
  // B[15:9] Are Control Address Bits
  // B[8:0]  Are Control Data Bits
  addr = address << 1;                 // Shift left for one positions
  addr = addr | ((cmd >> 8) & 0x01);
    
  i2c_start();                              // Start I2C2 module
  i2c_write(WM8731_ADDRESS);                // Write Adress of WM8731 chip
  i2c_write(addr);                          // Write register address
  i2c_write((unsigned char)(cmd & 0xff));   // Write command
  i2c_stop();                               // Stop I2C2 module
}

/**************************************************************************************************
* Function WM8731_Init
* -------------------------------------------------------------------------------------------------
* Overview: Function Initializes WM8731
* Input: Nothing
* Output: Nothing
**************************************************************************************************/
void WM8731_Init(){
  // Initialize WM8731 module
  init_i2c();                          // Init I2C2 module (100Khz)
  //delay_ms(100);

  // Write to WM8731 registers appropriate values
  WM8731_CMD(WM8731_REG_RESET, _WM8731_RESET);               // RESET MODULE
  WM8731_CMD(WM8731_REG_LLINE_IN, _WM8731_LEFT_LINEIN);      // LEFT LINE IN SETTINGS
  WM8731_CMD(WM8731_REG_RLINE_IN, _WM8731_RIGHT_LINEIN);     // RIGTH LINE IN SETTINGS
  WM8731_CMD(WM8731_REG_LHPHONE_OUT, _WM8731_LEFT_HP);       // LEFT HEADPHONE OUT SETTINGS
  WM8731_CMD(WM8731_REG_RHPHONE_OUT, _WM8731_RIGHT_HP);      // RIGHT HEADPHONE OUT SETTINGS
  WM8731_CMD(WM8731_REG_ANALOG_PATH, _WM8731_ANALOGAUDIO);   // ANALOG PATHS
  WM8731_CMD(WM8731_REG_DIGITAL_PATH, _WM8731_DIGITALAUDIO); // DIGITAL PATHS
  WM8731_CMD(WM8731_REG_PDOWN_CTRL, _WM8731_POWER);          // POWER DOWN CONTROL
  WM8731_CMD(WM8731_REG_DIGITAL_IF, _WM8731_DAIF);           // DIGITAL INTERFACE
  WM8731_CMD(WM8731_REG_SAMPLING_CTRL, _WM8731_SAMPLING);    // SAMPLING CONTROL
//  WM8731_CMD(WM8731_Reg_Active_ctrl, _WM8731_Activate);      // Activate module

  delay_ms(10);
}

/**************************************************************************************************
* Function WM8731_SetVolume
* -------------------------------------------------------------------------------------------------
* Overview: Function Sets volume on both output channels
* Input: Left and Right channel Volume
*        Inputs are from 0 to 80 and outout is from -73dB to 6dB in 1dB steps
*        0 = mute
*        1 = - 73 dB
*        80 = + 6 dB
* Output: Nothing
**************************************************************************************************/
void WM8731_SetVolume(char LeftCh, char RightCh){
unsigned int temp;

  if (LeftCh > 80)
    LeftCh = 80;
  if (RightCh > 80)
    RightCh = 80;
  
  temp = LeftCh + 0x00AF;
  WM8731_CMD(WM8731_REG_LHPHONE_OUT, temp);      //LEFT HEADPHONE OUT
  temp = RightCh + 0x00AF;
  WM8731_CMD(WM8731_REG_RHPHONE_OUT, temp);      //RIGHT HEADPHONE OUT
}

/**************************************************************************************************
* Function WM8731_Activate
* -------------------------------------------------------------------------------------------------
* Overview: Function Activates WM8731
* Input: Nothing
* Output: Nothing
**************************************************************************************************/
void WM8731_Activate(){
  WM8731_CMD(WM8731_REG_ACTIVE_CTRL, _WM8731_ACTIVATE);
}

/**************************************************************************************************
* Function WM8731_Deactivate
* -------------------------------------------------------------------------------------------------
* Overview: Function Deactivates WM8731
* Input: Nothing
* Output: Nothing
**************************************************************************************************/
void WM8731_Deactivate(){
  WM8731_CMD(WM8731_REG_ACTIVE_CTRL, _WM8731_DEACTIVATE);
}

#ifndef _PLIB_I2C_PROCESSOR_H
#define _PLIB_I2C_PROCESSOR_H

#if defined(__PIC16F__)
    #include <peripheral/i2c/processor/i2c_pic_other.h>

#elif defined(__18CXX)
    #include <peripheral/i2c/processor/i2c_pic18.h>

#elif defined(_PIC18)
    #include <peripheral/i2c/processor/i2c_pic18.h>

#elif defined(__PIC24F__)
    #include <peripheral/i2c/processor/i2c_p24Fxxxx.h>

#elif defined(__PIC24H__)
    #include <peripheral/i2c/processor/i2c_p24Hxxxx.h>

#elif defined(__dsPIC30F__)
    #include <peripheral/i2c/processor/i2c_p30Fxxxx.h>

#elif defined(__dsPIC33E__)
    #include <peripheral/i2c/processor/i2c_p33Exxxx.h>

#elif defined(__dsPIC33F__)
    #include <peripheral/i2c/processor/i2c_p33Fxxxx.h>

#elif defined(__PIC32MX__)
    #include <peripheral/i2c/processor/i2c_p32xxxx.h>

#elif defined(__PIC32MZ__)
    #include "i2c_p32xxxx.h"
	
#elif defined(__PIC32WK__)
    #include "i2c_p32xxxx.h"

#else
    #error "Can't find header"

#endif

#endif//_PLIB_I2C_PROCESSOR_H
#ifndef _WS8731_H
#define _WS8731_H

void init_i2c();
void i2c_wait();
void i2c_start();
void i2c_restart();
void i2c_stop();
void i2c_write(unsigned char data);
void i2c_address(unsigned char address, unsigned char mode);
unsigned char i2c_read(unsigned char ack) ;





#endif
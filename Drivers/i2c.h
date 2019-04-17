// Sanket Patil and Sagar Bhatnagar final project i2c driver.

#ifndef i2c_h
#define i2c_h
#include<stdint.h>

void i2c0_write_bytes( uint8_t dev, uint8_t reg, uint8_t data);
void i2c0_read_bytes( uint8_t dev, uint8_t reg, uint8_t count, uint8_t *buf);
uint8_t i2c0_read_byte( uint8_t dev , uint8_t reg);
void initialize_i2c0();

#endif

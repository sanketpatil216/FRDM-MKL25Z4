// Sanket Patil and Sagar Bhatnagar final project  driver. This is driver for SWITCH on the freedom board

#ifndef SW_H
#define SW_H
#include <stdint.h>


void initialize_sw();
uint32_t get_and_clear_switch_count();

#endif

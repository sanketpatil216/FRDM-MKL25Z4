// Sanket Patil and Sagar Bhatnagar final project  driver. This is driver for Watchdog on the freedom board

#include <stdint.h>
#include <MKL25Z4.h>
#include "watchdog.h"


void initialize_wd()
{
	SIM-> COPC = SIM_COPC_COPT(3) | SIM_COPC_COPCLKS(0) | SIM_COPC_COPW(0);
}

void service_wd()
{
	SIM-> SRVCOP = 0x55;
	SIM-> SRVCOP = 0xAA;
}
// Sanket Patil and Sagar Bhatnagar final project  driver. This is driver for Switch on the freedom board

#include "sw.h"
#include <MKL25Z4.h>
#include <stdint.h>

#define SW_SHIFT (20)
#define MASK(x) (1UL<<(x))

uint32_t g_switch_count = 0;

void initialize_sw()
{
	SIM-> SCGC5 |= SIM_SCGC5_PORTA_MASK;
	PORTA->PCR[SW_SHIFT]= PORT_PCR_MUX(1) | PORT_PCR_IRQC(10) | PORT_PCR_PS_MASK | PORT_PCR_PE_MASK;
	PTA-> PDDR &= ~MASK(SW_SHIFT);
	NVIC_SetPriority(PORTA_IRQn, 3);
	NVIC_ClearPendingIRQ(PORTA_IRQn);
	NVIC_EnableIRQ(PORTA_IRQn);
}

void PORTA_IRQHandler(void)
{
	g_switch_count++;
	PORTA->ISFR = MASK(SW_SHIFT);
}
uint32_t get_and_clear_switch_count()
{
	uint32_t retval;
	uint32_t masking_state;
	masking_state= __get_PRIMASK();
	__disable_irq();
	retval= g_switch_count;
	g_switch_count = 0;
	__set_PRIMASK(masking_state);
	return retval;
	
}

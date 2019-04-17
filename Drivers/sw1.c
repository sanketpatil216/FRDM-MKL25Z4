//Sanket Patil. This is driver for Switch 1 on freedom board. 

#include "sw1.h"
#include <MKL25Z4.h>
#include <stdbool.h>

#define SW1_SHIFT (20)
#define MASK(x) (1UL<< (x))


_Bool sw1_is_pressed()

	{
		return! (PTA->PDIR & MASK(SW1_SHIFT));
	}

_Bool sw1_is_not_pressed()

	{
		return! sw1_is_pressed();
	}

void sw1_wait_for_press_release()

	{
		while(sw1_is_not_pressed());
		while(sw1_is_pressed());
	}

void configure_sw1()

	{
		SIM->SCGC5 |= SIM_SCGC5_PORTA_MASK;

		PORTA-> PCR[SW1_SHIFT] &= ~PORT_PCR_MUX_MASK;
		PORTA-> PCR[SW1_SHIFT] |= PORT_PCR_MUX(1);

		PTA->PDDR &= ~MASK(SW1_SHIFT);
	}









#include"led.h"
#include"MKL25Z4.h"
#define  LED1_SHIFT ( 19 )
#define MASK(x) (1UL<<(x))
void turn_on_led()
        {
                PTB->PSOR = MASK (LED1_SHIFT);
        }

void turn_off_led()
        {
                PTB->PCOR = MASK(LED1_SHIFT);
        }

void toggle_led()
        {
                PTB->PTOR = MASK(LED1_SHIFT);
        }

void configure_led()
        {
        SIM->SCGC5  |=SIM_SCGC5_PORTB_MASK; 

        PORTB-> PCR[LED1_SHIFT] &= ~PORT_PCR_MUX_MASK;
	PORTB-> PCR[LED1_SHIFT] |= PORT_PCR_MUX(1);

        PTB->PDDR |= MASK(LED1_SHIFT);

        }


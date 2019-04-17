#include <MKL25Z4.h>
#include <stdint.h>
#include "tsi.h"

#define TSI_SHIFT1 16
#define TSI_SHIFT2 17

#define MASK(x) (1UL<< x)

void initialize_tsi()
{
	SIM->SCGC5 |= SIM_SCGC5_TSI_MASK;
	SIM->SCGC6 |= SIM_SCGC5_PORTB_MASK;

	PORTB->PCR[TSI_SHIFT1] = PORT_PCR_MUX(0);
	PORTB->PCR[TSI_SHIFT2] = PORT_PCR_MUX(0);

	TSI0-> GENCS= TSI_GENCS_STM(0) | TSI_GENCS_TSIEN(0) | TSI_GENCS_NSCN(0) |  TSI_GENCS_PS(4) |  TSI_GENCS_EXTCHRG(7) | TSI_GENCS_DVOLT(0) | TSI_GENCS_REFCHRG(4) | TSI_GENCS_MODE(0);

	TSI0->GENCS |= TSI_GENCS_TSIEN_MASK;
//	PORTB-> PCR[TSI_SHIFT1] &= ~PORT_PCR_MUX_MASK;
//	PORTB-> PCR[TSI_SHIFT1] |= PORT_PCR_MUX(1);

//	PORTB-> PCR[TSI_SHIFT2] &= ~PORT_PCR_MUX_MASK;
//	PORTB-> PCR[TSI_SHIFT2] |= PORT_PCR_MUX(1);

//	PTB-> PDDR &= ~MASK(TSI_SHIFT1);
//	PTB-> PDDR &= ~MASK(TSI_SHIFT2);
}

uint8_t scan_complete()
{

	while(!(TSI0-> GENCS & TSI_GENCS_EOSF_MASK));
}

void start_scan()
{

	TSI0-> DATA = TSI_DATA_SWTS_MASK | TSI_DATA_TSICH(9);
//	scan_complete();
}

uint32_t scan_result()
{
	return  TSI0-> DATA & TSI_DATA_TSICNT_MASK;
	TSI0->GENCS |= TSI_GENCS_EOSF_MASK;
}

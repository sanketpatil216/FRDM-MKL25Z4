#include <MKL25Z4.h>
#include "systick.h"
#include <stdint.h>


#define TOPVAL 480000  

uint8_t g_flag =0;
void systick_timer()
{
	SysTick -> LOAD = (TOPVAL);
	SysTick -> VAL = 0;
	SysTick-> CTRL = SysTick_CTRL_TICKINT_Msk | SysTick_CTRL_ENABLE_Msk | SysTick_CTRL_CLKSOURCE_Msk;
}

void SysTick_Handler()
{
	static int g_tick_count =0;
	g_tick_count ++;
	if(g_tick_count%20 == 0)
		{
			g_flag=1;
			g_tick_count=0;
		}
	else 
		g_flag = 0;
}

	
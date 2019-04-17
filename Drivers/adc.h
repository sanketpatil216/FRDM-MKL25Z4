#ifndef ADC_H
#define ADC_H

void initialize_adc();
void adc_start_conversion();
_Bool adc_input_is_ready();
unsigned adc_get_input();

#endif

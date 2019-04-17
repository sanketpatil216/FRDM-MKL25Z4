#ifndef tsi_h
#define tsi_h
#include <stdint.h>


void initialize_tsi();
uint8_t scan_complete();
void start_scan();
uint32_t scan_result();

#endif

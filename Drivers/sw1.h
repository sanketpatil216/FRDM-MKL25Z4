//Sanket Patil. This is header file for the Switch 1 on the freedom board.

#ifndef sw1_h
#define sw1_h
#include <stdbool.h>

void sw1_wait_for_press_release();
_Bool sw1_is_not_pressed();
_Bool sw1_is_pressed();
void  configure_sw1();

#endif


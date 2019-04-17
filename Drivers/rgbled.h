// Sanket Patil and Sagar Bhatnagar final project  driver. This is driver for RGBLED on the freedom board

#ifndef RGBLED_H
#define RGBLED_H

typedef enum RGBLED_COLORS {RGBLED_COLOR_BLACK = 0,
RGBLED_COLOR_BLUE = 1,
RGBLED_COLOR_GREEN =2,
RGBLED_COLOR_CYAN = 3,
RGBLED_COLOR_RED = 4,
RGBLED_COLOR_MAGENTA = 5,
RGBLED_COLOR_YELLOW = 6,
RGBLED_COLOR_WHITE = 7,
} RGBLED_COLOR;

void set_rgbled_color_to (RGBLED_COLOR color);
void toggle_red_led();
void turn_on_red_led();
void turn_off_red_led();

void toggle_green_led();
void turn_on_green_led();
void turn_off_green_led();

void toggle_blue_led();
void turn_on_blue_led();
void turn_off_blue_led(); 

void initialize_rgbled();

#endif





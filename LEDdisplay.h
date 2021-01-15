
#ifndef _LEDdisplay_H_

#define _LEDdisplay_H_

#ifndef _REG52_H_
#define _REG52_H_
#include "reg52.h"
#endif

#define leddata P0
sbit wei1 = P2^4;
sbit wei2 = P2^5;
sbit wei3 = P2^6;
sbit wei4 = P2^7;

void single_led(char posi, char outdata);
void set_disp_int(int num);
void close_led(void);
	
#endif
#include "LEDdisplay.h"

char table[] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x27,0x7f,0x6f,
								0xbf,0x86,0xdb,0xcf,0xe6,0xed,0xfd,0xa7,0xff,0xef};
char led_num[] = {0,0,0,0};
char current_led = 0;

void single_led(char posi, char outdata){
		
	leddata = table[outdata];
	switch(posi){
		case 0: wei1 = 1, wei2 = 0, wei3 = 0, wei4 = 0; break;
		case 1: wei1 = 0, wei2 = 1, wei3 = 0, wei4 = 0; break;
		case 2: wei1 = 0, wei2 = 0, wei3 = 1, wei4 = 0; break;
		case 3: wei1 = 0, wei2 = 0, wei3 = 0, wei4 = 1; break;
	}
}

void set_disp_int(int num){
	if(current_led == 0){
		led_num[0] = num/1000;
		led_num[1] = num%1000/100 + 10;
		led_num[2] = num%100/10;
		led_num[3] = num%10;
	}
	
	single_led(current_led, led_num[current_led]);
	current_led++;
	current_led &= 0x03;
}

void close_led(){
	wei1 = 0, wei2 = 0, wei3 = 0, wei4 = 0;
}
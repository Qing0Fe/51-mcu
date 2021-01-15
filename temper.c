
#include "temper.h"

void DelayX2us(uchar t){
	while(--t);
}

uchar ds18b20_ack(){
	pin_ds = 0;
	DelayX2us(250);
	pin_ds = 1;
	DelayX2us(30);
	return pin_ds;
}
	
void ds18b20_set_H(){
	pin_ds = 0;
	DelayX2us(1);
	pin_ds = 1;
	DelayX2us(30);
}

void ds18b20_set_L(){
	pin_ds=0;
	DelayX2us(10);
  pin_ds=1;
	DelayX2us(20);
}

void ds18b20_set_byte(uchar com){
	uchar i;
	for(i = 0; i <= 7; i++){
		if(com&0x01){
			ds18b20_set_H();
		}else{
			ds18b20_set_L();
		}
		com >>= 1;
	}
}

uchar ds18b20_read_bit(){
	pin_ds = 0;
	DelayX2us(1);
	pin_ds = 1;
	DelayX2us(4);
	return pin_ds;
}

uchar ds18b20_read_byte(){
	uchar i, com;
	for(i = 0, com = 0; i <= 7; i++){
		com = (ds18b20_read_bit() << 7)|(com>>1);
	}
	return com;
}

/*
invoke example
		ds18b20_ack();
		DelayX2us(25);
		ds18b20_set_byte(0xcc);
		ds18b20_set_byte(0x44);
*/

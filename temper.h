#ifndef _TEMPER_H_
#define _TEMPER_H_

#ifndef _REG52_H_
#define _REG52_H_

#include "reg52.h"

#endif

#define uchar unsigned char
#define uint  unsigned int

sbit pin_ds = P3^7;

void DelayX2us(uchar t);
uchar ds18b20_ack(void);
void ds18b20_set_H(void);
void ds18b20_set_L(void);
void ds18b20_set_byte(uchar com);
uchar ds18b20_read_bit(void);
uchar ds18b20_read_byte(void);

#endif
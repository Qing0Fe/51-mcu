#include "temper.h"
#include "LEDdisplay.H"

uint temperature = 0;
uchar temp_L = 0;

void led_init(){
	/*led fps = 50hz*/
	TMOD &= 0xF0;		  //���ö�ʱ��ģʽ
	TMOD |= 0x01;		  //���ö�ʱ��ģʽ
	TL0 = 0x00;		    //���ö�ʱ��ֵ
	TH0 = 0xEE;	    	//���ö�ʱ��ֵ
	TF0 = 0;		      //���TF0��־
	EA = 1;           //���������ж�
  ET0 = 1;          //���Ŷ�ʱ��0�жϿ���λ
	TR0 = 1;		      //��ʱ��0��ʼ��ʱ	
}

void led_disp_rate() interrupt 1 {
	TR0 = 0; 
	close_led();
	TL0 = 0x00;
	TH0 = 0xEE;
	set_disp_int(temperature);
	TR0 = 1;
}

void main(){	
	
	led_init();
	
	while(1){
		EA = 0;
		ds18b20_ack();
		DelayX2us(25);
		ds18b20_set_byte(0xcc);
		ds18b20_set_byte(0x44);
    
		ds18b20_ack();
		DelayX2us(25);
		ds18b20_set_byte(0xcc);
		ds18b20_set_byte(0xbe);
		
		temp_L = ds18b20_read_byte();
		temperature = ds18b20_read_byte();
		
		temperature = (temperature<<8) | temp_L;	
		temperature = temperature * 6 + temperature / 4;
		EA = 1;
	}
}




/*
 * led.c
 *
 * Created: 1/25/2023 9:47:02 PM
 *  Author: yahia
 */ 

#include "led.h"
//#include <avr/delay.h>

void Led_init(uint8 pin_id , uint8 port_id)
{
	DIO_Set_Pin_Direction(pin_id,port_id,output);
}

void Led_on(uint8 pin_id , uint8 port_id)
{
	DIO_Set_Pin_Val(pin_id,port_id,HIGH);
}

void led_off(uint8 pin_id , uint8 port_id)
{
	DIO_Set_Pin_Val(pin_id,port_id,LOW);
}

void led_blink(uint8 pin_id , uint8 port_id)
{
	Led_on(pin_id,port_id);
	Timer_delay(100);
	//_delay_ms(100);
	led_off(pin_id,port_id);
	Timer_delay(100);
	//_delay_ms(100);
	
}
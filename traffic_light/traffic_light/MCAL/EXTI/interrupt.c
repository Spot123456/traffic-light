/*
 * interrupt.c
 *
 * Created: 1/25/2023 6:16:31 PM
 *  Author: yahia
 */ 
#include "interrupt.h"
  
void EXT_Global_Interrupt()
{
	SREG|=(1<<7);	// for global interrupt
}
void EXT_Interrupt_init()
{
	// we select rising edge interrupt
	MCUCR |=(1<<0);
	MCUCR |=(1<<1);
	// we should clear flag of interrupt 0 by (set 1 on it ) 
	GIFR |=(1<<6); 
}

void EXT_Enable_Int0()
{
	GICR |=(1<<6);
	//External Interrupt is activated on rising and/or falling edge of the INT0 pin or level sensed
}


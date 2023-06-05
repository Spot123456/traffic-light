/*
 * timer.c
 *
 * Created: 1/25/2023 3:49:05 PM
 *  Author: yahia
 */ 

#include "timer.h"
#define freq 1000000
void Timer0_init(ST_Timer_Config Prescaler)
{	TCCR0=0x00; //as def 
	switch(Prescaler)
	{
		case normal : TCCR0=0x00; break;
	    /*work as normal mode with no prescaler Oc0 disconnected */
		case nopre   : TCCR0 |=(1<<0); break;
		case pre8    : TCCR0 |=(2<<0); break;
		case pre64   : TCCR0 |=(3<<0); break;
		case pre256  : TCCR0 |=(4<<0); break;
		case pre1024 : TCCR0 |=(5<<0); break;
		 
	}
}


void timer0_start(uint8 value) 
{
	TCNT0 = value ;  // start from 
}

void timer0_Get(uint8 * value)
{
	while((TIFR0 & (1<<0))==0); // loop 48ala l8ayt lma y7sel OVF (i.e TIFR0 =0x01)
	*value =1 ;
}
void Timer_stop()
{
	TCCR0 =0x00;
}


/*
void Timer_delay(float msec) 
{
	uint64 overflow_count = 0 ;
	Timer0_init(pre64);
	float time_tick= 64/freq; 
	float time_maxDelay= 256 *time_tick ;  //256 = 2^8 (8 for no of bits)
	msec=msec*(1/1000);
	int64 n_overFlow = (int) (msec/time_maxDelay);
	while(overflow_count<n_overFlow)
	{ // wait timer interrupt flag register
		while((TIFR0 & (0x01))==0) ;
		TIFR0|=(1<<0); // clear flag by adding 1 on it
		overflow_count++;  // for one clear inc the counter
	}
	overflow_count=0 ; // after end set ovf 0 and stop timer
	Timer_stop();
}
*/

void Timer_delay(float msecend)
{
	unsigned int overflow_counter=0;
	Timer0_init(pre64);
//	float timer_clk=64*.000001;
//	float time_overflow=256*timer_clk;
//	msecend=msecend*.001;
	int num_over_flow=(int)(msecend*61);
	while (overflow_counter<num_over_flow)
	{
		//wait for flag occurs
		while((TIFR0 &(1<<0))==0);
		//clear flag
		TIFR0 |=(1<<0);
		overflow_counter++;
	}
	overflow_counter=0;
	//set time to 0
	TCCR0 =0x00;
}

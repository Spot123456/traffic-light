/*
 * timer.h
 *
 * Created: 1/25/2023 3:49:27 PM
 *  Author: yahia
 */ 


#ifndef TIMER_H_
#define TIMER_H_
#include "../DIO/dio.h"
#include "../../Utilites/Bit_Math.h"
#include "../../Utilites/DIO_REG.h"
#include "../../Utilites/REG_TYPE.h"
typedef enum
{
	normal,
	nopre,
	pre8,
	pre64,
	pre256,
	pre1024
}ST_Timer_Config;



void Timer0_init(ST_Timer_Config Prescaler);
void timer0_start( uint8 value);
void timer0_Get(uint8 * value);
void Timer_stop();
//void Timer_delay(float msec) ;
void Timer_delay(float msecend);
#endif /* TIMER_H_ */
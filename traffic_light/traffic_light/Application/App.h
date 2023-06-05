/*
 * App.h
 *
 * Created: 2/1/2023 8:22:19 PM
 *  Author: yahia
 */ 


#ifndef APP_H_
#define APP_H_

#include "../ECUAL/Push Button/Button.h"
#include "../ECUAL/LED/led.h"
#include "../ECUAL/ECUAL.h"

typedef enum
{
	Normal_mode,
	pedestrian_mode
}flag_mode;
	
typedef enum
{
	Green,
	Yellow,
	red
}Flag_color;

void APP_init();
void APP_start();


#endif /* APP_H_ */
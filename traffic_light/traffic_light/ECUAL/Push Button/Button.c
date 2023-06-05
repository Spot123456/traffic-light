/*
 * Button.c
 *
 * Created: 1/25/2023 9:28:34 PM
 *  Author: yahia
 */ 

#include "Button.h"

void Button_init(uint8 pin_id, uint8 port_id)
{
	DIO_Set_Pin_Direction(pin_id,port_id,input);
}
uint8 Button_read(uint8 pin_id, uint8 port_id )
{
	DIO_Value val;
	val =DIO_Get_Pin_Val(pin_id,port_id);
	return val ; 
}
/*
 * dio.c
 *
 * Created: 1/24/2023 7:05:24 AM
 *  Author: PC
 */ 

#include "dio.h"

void DIO_Set_PortDirection(DIO_PORT_ID PORT_ID ,DIO_Direction Direction )
{	
	if(Direction == output)
	{
		switch(PORT_ID)
		{
			case PORTA : DDRA_REG= 0xFF ; break;
			case PORTB : DDRB_REG= 0xFF ; break;
			case PORTC : DDRC_REG= 0xFF ; break;
			case PORTD : DDRD_REG= 0xFF ; break; 
		}
	}
	if (Direction == input)
	{
		switch(PORT_ID)
		{
			case PORTA : DDRA_REG= 0x00 ; break;
			case PORTB : DDRB_REG= 0x00 ; break;
			case PORTC : DDRC_REG= 0x00 ; break;
			case PORTD : DDRD_REG= 0x00 ; break;
		}
	}
}

void DIO_Set_PortVal(DIO_PORT_ID PORT_ID , uint8 value)
{
		switch(PORT_ID)
		{
			case PORTA : PORTA_REG = value ; break;
			case PORTB : PORTB_REG = value ; break;
			case PORTC : PORTC_REG = value ; break;
			case PORTD : PORTD_REG = value ; break;
		}

}

void DIO_Set_Pin_Direction(DIO_Pin_ID PIN_ID ,DIO_PORT_ID PORT_ID , DIO_Direction Direction) 
{
	if(PORT_ID<=PORTD && PIN_ID<=pin7)
	{
		if(Direction==output)
		{
			switch(PORT_ID)
			{
				case PORTA : Set_Bit(DDRA_REG,PIN_ID)  ; break;
				case PORTB : Set_Bit(DDRB_REG,PIN_ID)  ; break;
				case PORTC : Set_Bit(DDRC_REG,PIN_ID)  ; break;
				case PORTD : Set_Bit(DDRD_REG,PIN_ID)  ; break;
				
			}
		}
		
		
		if(Direction==input)
		{
			switch(PORT_ID)
			{
				case PORTA : Clear_Bit(DDRA_REG,PIN_ID)  ; break;
				case PORTB : Clear_Bit(DDRB_REG,PIN_ID)  ; break;
				case PORTC : Clear_Bit(DDRC_REG,PIN_ID)  ; break;
				case PORTD : Clear_Bit(DDRD_REG,PIN_ID)  ; break;
				
			}
		}
	}
}

void DIO_Set_Pin_Val(DIO_Pin_ID PIN_ID ,DIO_PORT_ID PORT_ID , DIO_Value value)
{
	if(PORT_ID<=PORTD && PIN_ID <=pin7)
	{
		if (value == HIGH)
		{
			switch(PORT_ID)
			{
				case PORTA : Set_Bit(PORTA_REG,PIN_ID); break;
				case PORTB : Set_Bit(PORTB_REG,PIN_ID); break;
				case PORTC : Set_Bit(PORTC_REG,PIN_ID); break;
				case PORTD : Set_Bit(PORTD_REG,PIN_ID); break;
			}
		}
		
		if (value == LOW)
		{
			switch(PORT_ID)
			{
				case PORTA : Clear_Bit(PORTA_REG,PIN_ID); break;
				case PORTB : Clear_Bit(PORTB_REG,PIN_ID); break;
				case PORTC : Clear_Bit(PORTC_REG,PIN_ID); break;
				case PORTD : Clear_Bit(PORTD_REG,PIN_ID); break;
			}
		}
	}
}

DIO_Value DIO_Get_Pin_Val(DIO_Pin_ID PIN_ID , DIO_PORT_ID PORT_ID )
{
	DIO_Value val;
	if (PORT_ID<=PORTD && PIN_ID<=pin7)
	{
		switch(PORT_ID)
		{
			case PORTA : val= Get_Bit(PINA_REG,PIN_ID) ; break;
			case PORTB : val= Get_Bit(PINB_REG,PIN_ID) ; break;
			case PORTC : val= Get_Bit(PINC_REG,PIN_ID) ; break;
			case PORTD : val= Get_Bit(PIND_REG,PIN_ID) ; break;
		}
	}
	return val ;
}

void DIO_toggle(uint8 pin_id, uint8 port_id)
{
	switch (port_id)
	{
		case PORTA :
		Toggle_Bit(PORTA_REG , pin_id );
		break;
		
		case PORTB :
		Toggle_Bit(PORTA_REG , pin_id );
		break;
		
		case PORTC :
		Toggle_Bit(PORTA_REG , pin_id );
		break;
		
		case PORTD :
		Toggle_Bit(PORTA_REG , pin_id );
		break;
		
	}
}
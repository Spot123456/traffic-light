/*
 * REG_TYPE.h
 *
 * Created: 1/24/2023 7:07:28 AM
 *  Author: PC
 */ 


#ifndef REG_TYPE_H_
#define REG_TYPE_H_


typedef unsigned char   uint8 ;
typedef unsigned short  uint16 ;
typedef unsigned int uint64;

typedef signed char     int8 ;
typedef signed short    int16 ;
typedef signed int      int64;


typedef enum
{
	input,
	output
}DIO_Direction;
typedef enum
{
	PORTA,
	PORTB,
	PORTC,
	PORTD
}DIO_PORT_ID;
typedef enum
{
	LOW,
	HIGH
}DIO_Value;
typedef enum
{ pin0,
	pin1,
	pin2,
	pin3,
	pin4,
	pin5,
	pin6,
pin7}DIO_Pin_ID;


#endif /* REG_TYPE_H_ */
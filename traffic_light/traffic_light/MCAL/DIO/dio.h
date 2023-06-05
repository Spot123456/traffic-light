/*
 * dio.h
 *
 * Created: 1/24/2023 7:05:40 AM
 *  Author: PC
 */ 


#ifndef DIO_H_
#define DIO_H_
#include "../../Utilites/Bit_Math.h"
#include "../../Utilites/DIO_REG.h"
#include "../../Utilites/REG_TYPE.h"


void DIO_Set_PortDirection(DIO_PORT_ID PORT_ID ,DIO_Direction Direction );
void DIO_Set_PortVal(DIO_PORT_ID PORT_ID , uint8 value);
void DIO_Set_Pin_Direction(DIO_Pin_ID PIN_ID ,DIO_PORT_ID PORT_ID , DIO_Direction Direction) ;
void DIO_Set_Pin_Val(DIO_Pin_ID PIN_ID ,DIO_PORT_ID PORT_ID , DIO_Value value);
DIO_Value DIO_Get_Pin_Val(DIO_Pin_ID PIN_ID , DIO_PORT_ID PORT_ID );
void DIO_toggle(uint8 pin_id, uint8 port_id);

#endif /* DIO_H_ */
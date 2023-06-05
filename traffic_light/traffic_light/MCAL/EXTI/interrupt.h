/*
 * interrupt.h
 *
 * Created: 1/25/2023 6:16:48 PM
 *  Author: yahia
 */ 


#ifndef INTERRUPT_H_
#define INTERRUPT_H_

#include "../DIO/dio.h"
#include "../../Utilites/Bit_Math.h"
#include "../../Utilites/DIO_REG.h"
#include "../../Utilites/REG_TYPE.h"
#define EXTI_INT_0  __vector_1
#define EXTI_INI_1  __vector_2
#define EXTI_INI_2  __vector_3

//micro Define the ISR
#define ISR(INT_VECT)void INT_VECT(void) __attribute__((signal,used));\
void INT_VECT(void)


void EXT_Global_Interrupt(); // to enable the global interrupt the last reg -->7      (1)
void EXT_Interrupt_init(); //to select the type falling or rising edge                (2)
void EXT_Enable_Int0();                                                             //(3)
//External Interrupt is activated on rising and/or falling edge of the INT0 pin or level sensed








#endif /* INTERRUPT_H_ */
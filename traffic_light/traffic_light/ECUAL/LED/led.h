/*
 * led.h
 *
 * Created: 1/25/2023 9:47:13 PM
 *  Author: yahia
 */ 


#ifndef LED_H_
#define LED_H_


#include "../../MCAL/DIO/dio.h"
#include "../../MCAL/EXTI/interrupt.h"
#include "../../MCAL/Timer/timer.h"

#define Led_car_port  PORTA
#define Led_pedestrian_port PORTB

#define Green_led_Car  0
#define Yellow_led_car 1
#define Red_led_car    2

#define Green_led_Pedestrian  0
#define Yellow_led_Pedestrian 1
#define Red_led_Pedestrian    2

void Led_init(uint8 pin_id , uint8 port_id);
void Led_on(uint8 pin_id , uint8 port_id);
void led_blink(uint8 pin_id , uint8 port_id);
void led_off(uint8 pin_id , uint8 port_id);


#endif /* LED_H_ */
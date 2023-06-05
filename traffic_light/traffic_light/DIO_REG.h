/*
 * DIO_REG.h
 *
 * Created: 1/24/2023 7:06:47 AM
 *  Author: PC
 */ 


#ifndef DIO_REG_H_
#define DIO_REG_H_

/******************************************/
/*              GPIO REG                  */
/******************************************/

#define PORTA_REG *((volatile uint8*) 0x3B)
#define DDRA_REG  *((volatile uint8*) 0x3A)
#define PINA_REG  *((volatile uint8*) 0x39)

#define PORTB_REG *((volatile uint8*) 0x38)
#define DDRB_REG  *((volatile uint8*) 0x37)
#define PINB_REG  *((volatile uint8*) 0x36)

#define PORTC_REG *((volatile uint8*) 0x35)
#define DDRC_REG  *((volatile uint8*) 0x34)
#define PINC_REG  *((volatile uint8*) 0x33)

#define PORTD_REG *((volatile uint8*) 0x32)
#define DDRD_REG  *((volatile uint8*) 0x31)
#define PIND_REG  *((volatile uint8*) 0x30)

/******************************************/
/*              ADC REG                  */
/******************************************/

#define ADMUX   *((volatile uint8*) 0x27)
#define ADCSRA  *((volatile uint8*) 0x26)
#define ADCH    *((volatile uint16*) 0x25)  // ADC data register High bit
#define ADCL    *((volatile uint16*) 0x24) // ADC data register LOW bit
// 16 --> bec returen 10 bit as adc .


/******************************************/
/*            Timer REG                   */
/******************************************/
#define TCCR0  *((volatile uint8*) 0x53)
#define TCNT0  *((volatile uint8*) 0x52)
#define TIFR0  *((volatile uint8*) 0x53)
#define TIMSK  *((volatile uint8*) 0x59)

/******************************************/
/*            Interrupt REG               */
/******************************************/
#define GICR   *((volatile uint8*) 0x5B)
#define GIFR   *((volatile uint8*) 0x5A)
#define MCUCR  *((volatile uint8*) 0x55)
#define MCUCSR *((volatile uint8*) 0x54)
#define SREG   *((volatile uint8*) 0x5F)

/******************************************/
/*             UART REG                   */
/******************************************/

#define UBRRH *((volatile uint8*) 0x40)
#define UCSRC *((volatile uint8*) 0x40) // the two have the same address to select between them from (URSEL= 0 or 1 )
#define UDR   *((volatile uint8*) 0x2C)
#define UCSRA *((volatile uint8*) 0x2B)
#define UCSRB *((volatile uint8*) 0x2A)
#define UBRRL *((volatile uint8*) 0x29)


#endif /* DIO_REG_H_ */
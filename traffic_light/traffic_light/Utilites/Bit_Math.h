/*
 * Bit_Math.h
 *
 * Created: 1/24/2023 7:18:53 AM
 *  Author: PC
 */ 


#ifndef BIT_MATH_H_
#define BIT_MATH_H_


#define  Set_Bit(PORT_ID,PIN_ID)          PORT_ID |= (1<<PIN_ID)
#define  Clear_Bit(PORT_ID,PIN_ID)        PORT_ID &= ~(1<<PIN_ID)
#define  Toggle_Bit(PORT_ID,PIN_ID)       PORT_ID ^= (1<<PIN_ID)
#define  Get_Bit(PORT_ID,PIN_ID)		  (((PORT_ID)>>(PIN_ID)) & 0x01)								//PORT_ID &= ((1<<PIN_ID)>>PIN_ID)






/* Rotate left the register value with specific number of rotates */
#define ROL(REG,num) ( REG= (REG<<num) | (REG>>(8-num)) )

/* Check if a specific bit is set in any register and return true if yes */
#define BIT_IS_SET(REG,BIT) ( REG & (1<<BIT) )

/* Check if a specific bit is cleared in any register and return true if yes */
#define BIT_IS_CLEAR(REG,BIT) ( !(REG & (1<<BIT)) )


#endif /* BIT_MATH_H_ */
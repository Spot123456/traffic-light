/*
 * App.c
 *
 * Created: 2/1/2023 8:22:02 PM
 *  Author: Ahmed Nour
 */ 


#include "App.h"
flag_mode mode= Normal_mode;
Flag_color color ;
char i ;


void APP_init()
{
	// in normal mode
	
	//for cars
	Led_init(Green_led_Car,Led_car_port);//set port A pin 0 as output for green led of Normal_mode
	Led_init(Yellow_led_car,Led_car_port);//set port A pin 1 as output for green led of Normal_mode
	Led_init(Red_led_car,Led_car_port);//set port A pin 2 as output for green led of Normal_mode
	
	// for pedestrian
	Led_init(Green_led_Pedestrian,Led_pedestrian_port);//set port A pin 0 as output for green led of Normal_mode
	Led_init(Yellow_led_Pedestrian,Led_pedestrian_port);//set port A pin 1 as output for green led of Normal_mode
	Led_init(Red_led_Pedestrian,Led_pedestrian_port);//set port A pin 2 as output for green led of Normal_mode
	
	//button init
	Button_init(pin2,PORTD);
	
	Timer0_init(normal); // set timer in normal mode
	timer0_start(0x00); // set initial value 0 for timer0
	EXT_Interrupt_init(); // clear flag before start
	EXT_Global_Interrupt(); // open global interrupt
	EXT_Enable_Int0(); // enable interrupt flag for int0
	
}


void APP_start()
{
	while(1)
	{
		
		/************************************************************************/
		/*                   Normal Mode                                        */
		/************************************************************************/
		
		if (mode==Normal_mode)
		{
			Led_on(Red_led_Pedestrian,Led_pedestrian_port); //pedestrian red on 
			
			Led_on(Green_led_Car,Led_car_port); //green on car
			
			color= Green ;   //
			for (i=0;i<50;i++)
			{
				if(mode==pedestrian_mode){break;}
				Timer_delay(100);  //0.1 sec
				
			}
				if (mode==pedestrian_mode){continue;}
				led_off(Green_led_Car,Led_car_port); // green off car
				led_blink(Yellow_led_car,Led_car_port); //blink yellow car
			
			
				// yellow blink for 0.1 on and 0.1 off so half (I green) need i.e --> (i<24.5 = 25)
			color=Yellow; //color flag = yellow
			for (i=0;i<25;i++)
			{
				led_blink(Yellow_led_car,Led_car_port); //blink yellow traffic car
				if(mode==pedestrian_mode){break;} // if pressed out of loop
					Timer_delay(1);
			}
			if(mode==pedestrian_mode){continue;} //  if pressed out from while and go to interrupt (pedestrian mode)
			led_off(Yellow_led_car,Led_car_port); // yellow traffic care off
			Led_on(Red_led_car,Led_car_port); // red traffic on 
			
			
			color=red;            //color flag = red
			for(i=0;i<50;i++)
			{
				if(mode==pedestrian_mode){break;} //if pressed push button out from loop
					Timer_delay(100); //0.1 sec  wait 0.1 sec
			}
			if(mode==pedestrian_mode){continue;} // out from while and go to interrupt
			led_off(Red_led_car,Led_car_port); // off traffic red led
			led_blink(Yellow_led_car,Led_car_port); // blink yellow led
			
			color=Yellow;  // color flag = yellow
			for(i=0;i<25;i++)
			{
				led_blink(Yellow_led_car,Led_car_port);  //blink yellow traffic car
				if(mode==pedestrian_mode){break;}
					Timer_delay(1);
			}
			if(mode==pedestrian_mode){continue;}
			led_off(Yellow_led_car,Led_car_port); // turn off yellow traffic
		}
		
	else if (mode==pedestrian_mode)
	{
		/************************************************************************/
		/*                   pedestrian Mode                                    */
		/************************************************************************/
		//if the button pressed we go to pedestrian mode so we need to check the color flag to order the right one 
		
		if(color==red)           // if color flag == red
		{
			led_off(Red_led_Pedestrian,Led_pedestrian_port); // turn off led pedestrian 
			Led_on(Green_led_Pedestrian,Led_pedestrian_port); // turn on green pedestrian
			Led_on(Red_led_car,Led_car_port); // red traffic light on 
			for(i=0;i<50;i++) // wait 0.1 * 50 = 5 sec
			{
				Timer_delay(100); 
			}
			led_off(Red_led_car,Led_car_port); //red traffic off
			led_off(Green_led_Pedestrian,Led_pedestrian_port); // green pedestrian on
			for(i=0;i<25;i++)
			{
				led_blink(Yellow_led_car,Led_car_port); // blink yellow led car
				led_blink(Yellow_led_Pedestrian,Led_pedestrian_port); // blink yellow led pedestrian
				Timer_delay(1);	
			}
			mode=Normal_mode;
			
		}
		if(color == Green ||color== Yellow)
		{
			led_off(Green_led_Car,Led_car_port);
			led_off(Yellow_led_car,Led_car_port);
			
			Led_on(Red_led_Pedestrian,Led_pedestrian_port);
			Timer_delay(5000);
			led_off(Red_led_Pedestrian,Led_pedestrian_port);
		//	led_blink(Yellow_led_car,Led_car_port);
			//led_blink(Yellow_led_Pedestrian,Led_pedestrian_port);
			for(i=0 ; i< 25 ; i++)
			{
				led_blink(Yellow_led_car,Led_car_port); 
				led_blink(Yellow_led_Pedestrian,Led_pedestrian_port); 
				Timer_delay(1);
			}
			led_off(Yellow_led_car,Led_car_port);
			led_off(Yellow_led_Pedestrian,Led_pedestrian_port);
			Led_on(Green_led_Pedestrian,Led_pedestrian_port);
			Led_on(Red_led_car,Led_car_port);
			for(i=0 ; i< 50 ; i++)
			{
				Timer_delay(100);
			}
			led_off(Green_led_Pedestrian,Led_pedestrian_port);
			led_off(Red_led_car,Led_car_port);
			mode=Normal_mode;
		}
	}
		
		
		
		
		
		
		
		
	}
	
}
ISR(EXTI_INT_0)
{
	mode=pedestrian_mode;
	GIFR |=(1>>6); //clear flag 	
}
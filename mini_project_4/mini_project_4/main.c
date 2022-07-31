/*******************************************************************************
 *
 * Module: main function
 *
 * File Name: main.c
 *
 * Description:application
 * Created on: Oct 18, 2021
 * Author: mahmoud Mohamed
 *
 *******************************************************************************/
#define F_CPU 8000000
#include "lcd.h"
#include "ultrasonic.h"
#include <avr/io.h> /* To use the SREG register */


int main()
{
    /*local variable to hold the value of distance */
	uint16 distance;

	/* Enable Global Interrupt I-Bit */
	SREG |= (1<<7);


	/* Initialize both the LCD and Ultrasonic driver */
	LCD_init();
	Ultrasonic_init();

	LCD_displayString("distance=   cm ");
	while(1)
	{
		distance=Ultrasonic_readDistance();
		LCD_moveCursor(0,9);
		/* Display the distance value every time at same position */
		if (distance<10)
		{
			LCD_intgerToString((uint16)distance);
			/* In case the digital value is one digits print space in the next digit place */
			LCD_displayCharacter(' ');
			LCD_displayCharacter(' ');
		}
		else if (distance<100)
		{
			LCD_intgerToString((uint16)distance);
			/* In case the digital value is two  digits print space in the next digit place */
			LCD_displayCharacter(' ');
		}
		else
		{
			LCD_intgerToString((uint16)distance);
		}
	}
}



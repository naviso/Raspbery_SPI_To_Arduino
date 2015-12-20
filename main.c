/*
 * untitled.c
 * 
 * Copyright 2015  <pi@raspberrypi>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */

#include <stdio.h>
#include <bcm2835.h>						// C libraries for Raspberry Pi version 1 & 2

#include "SPI.h"
#include "test.h"

//#define BUS_CLOCK 16000000
#define LED_TEST RPI_V2_GPIO_P1_12		    // Assigning LED output to pin 12?

int HardwareInit(void);

int main(int argc, char **argv)
{
	const unsigned int delay_time_ms = 5;  
	
	if ( HardwareInit() )
	{
		printf("SPI Initialisation has gone all wrong");	
		return 1;		
	}
			
	while (1)
	{  
		
		/***** LED Test
		 * 
		 * LED TEST
		bcm2835_gpio_set(LED_TEST); 						//Sets the specified pin output to HIGH 
		//test_printing();
		//printf("Rand Value: %f\r", rand() * 3.14);
		bcm2835_delay (delay_time_ms);						// Delay function
		bcm2835_gpio_clr(LED_TEST);					     	//Sets the specified pin output to LOW
		bcm2835_delay (delay_time_ms);	
		*/
		test_printing();
		bcm2835_delay (delay_time_ms);						// Delay function
		bcm2835_gpio_set(LED_TEST);					     	// Sets the specified pin output to LOW
		bcm2835_delay (delay_time_ms);	
		
	}
	
	return 0;
}

int HardwareInit(void)
{
	if ( !bcm2835_init() )
		return 1;											// return value if initialisation of bcm2835 C functions fails
	
	bcm2835_gpio_fsel(LED_TEST, BCM2835_GPIO_FSEL_OUTP);	// Set the registers as either input or output of the pin for LED Test Function
	
	SPI_Init();
	
	return 0; 												// All good
}

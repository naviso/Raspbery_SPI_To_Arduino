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
 
// Shutdown Sequence using SIGINT: http://www.thegeekstuff.com/2012/03/catch-signals-sample-c-code/
								

#include <stdio.h>
#include <bcm2835.h>						// C libraries for Raspberry Pi version 1 & 2

#include "SPI.h"
#include "test.h"

//#define BUS_CLOCK 16000000
#define LED_TEST RPI_V2_GPIO_P1_12		    // Assigning LED output to pin 12?

uint16_t Test_Value = 123;


int HardwareInit(void);

int main(int argc, char **argv)
{
	const unsigned int delay_time_ms = 1;  

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
		test_printing();									// Prints random number
		bcm2835_delay (delay_time_ms);						// Delay function
		bcm2835_gpio_set(LED_TEST);					     	// Sets the specified pin output to LOW
		bcm2835_delay (delay_time_ms);	
		bcm2835_gpio_clr(LED_TEST);		
		
		uint8_t send_data = 0x23;
        uint8_t read_data = bcm2835_spi_transfer(send_data);	// just get arduino to send 0x23 via SPI
    
       // printf("Sent to SPI: 0x%02X. Read back from SPI: 0x%02X.\n", send_data, read_data);
        if (send_data != read_data)
			printf("Do you have the loopback from MOSI to MISO connected?\r");
		else 
			printf("WERKS: Data trans Success");
		
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

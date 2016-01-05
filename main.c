/*


 */
 
// Shutdown Sequence using SIGINT: http://www.thegeekstuff.com/2012/03/catch-signals-sample-c-code/
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>								
//////////////////////////////////////////////

#include <stdio.h>
#include <bcm2835.h>						// C libraries for Raspberry Pi version 1 & 2

#include "SPI.h"
#include "test.h"

#include "ShutDown.h"

//#define BUS_CLOCK 16000000
#define LED_TEST RPI_V2_GPIO_P1_12		    // Assigning LED output to pin 12?

uint16_t Test_Value = 123;


int Hardware_Init(void);

/* FUNCTION DECLARATIONS */
// void signal_callback_handler(int);          // Catches signal (e.g. ^c shutdown)
ShutDown_Init();

int main(int argc, char **argv)
{
	const unsigned int delay_time_ms = 1;  
	
	/* CALL THE SIGNAL HANDLER FUNCTION ON A Ctrl-C EXIT */
   // signal(SIGINT, signal_callback_handler);
	ShutDown_Init_Signal_Function();

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

/*
void signal_callback_handler(int signum)
{
   printf("\nCaught signal %d\n",signum);
 
   bcm2835_gpio_write(LED1, LOW);
   bcm2835_gpio_write(LED2, LOW);
   bcm2835_gpio_write(LED3, LOW);
   bcm2835_gpio_write(LED4, LOW);
   bcm2835_gpio_write(LED5, LOW);
   bcm2835_gpio_write(LED6, LOW);
   bcm2835_gpio_write(LED7, LOW);
   bcm2835_gpio_write(LED8, LOW);
   bcm2835_gpio_write(ACRELAY, LOW);
   bcm2835_gpio_write(RELAY1, LOW);

   bcm2835_close();
   exit(signum);
}
*/

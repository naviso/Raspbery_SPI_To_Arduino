/*
 * // Refer to: 
 * 		Shutdown Sequence using SIGINT: http://www.thegeekstuff.com/2012/03/catch-signals-sample-c-code/
*/


#include "ShutDown.h"

void ShutDown_Init(void)
{
	//void SHUTDOWN_Init_Signal_Function(void);
	void signal_callback_handler(int);
}

void ShutDown_Init_Signal_Function(void)
{
	signal(SIGINT, signal_callback_handler);
}

void signal_callback_handler(int signum)
{
   printf("\nCaught signal %d\n",signum);
 /*  
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
*/
   bcm2835_gpio_clr_multi(1 << RPI_V2_GPIO_P1_12);
   bcm2835_spi_end();
   bcm2835_close();
   exit(signum);
}

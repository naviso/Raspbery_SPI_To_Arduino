// File used for interfacing Pi with Ardruino

#include "SPI.h"


void printing(void)
{
	//printf("Rand Value Generator: %f\r", rand() * -0.1);
}

void SPI_Init(void)
{
	
	// Im Assuming this the PI is going to be the master......
	
	bcm2835_spi_begin(); 									    // Start SPI operations (See details on bcm2835 library)
	
	bcm2835_spi_setBitOrder(BCM2835_SPI_BIT_ORDER_MSBFIRST);	// Is data shifted in Most Significant Bit (MSB) or Least Significant Bit (LSB) first?
	
	bcm2835_spi_setDataMode(BCM2835_SPI_MODE3);                 // NEED TO ASK WHAT THE SETTINGS OF ARDUINO IS												
	
	bcm2835_spi_setClockDivider(BCM2835_SPI_CLOCK_DIVIDER_64);  // I'M ASSUMING ARDUINO IS 4MHZ CLOCK SPEED
	
	bcm2835_spi_chipSelect(BCM2835_SPI_CS_NONE);     // NEED MORE INFORMATION
	
	bcm2835_spi_setChipSelectPolarity(BCM2835_SPI_CS_NONE, LOW); // NEED MORE INFORMATION

}




// File used for interfacing Pi with Ardruino

#include "SPI.h"


void printing(void)
{
	//printf("Rand Value Generator: %f\r", rand() * -0.1);
}

void SPI_Init(void)
{
	// Im Assuming this the PI is going to be the master......
	
	bcm2835_spi_begin(); 									     // Start SPI operations (See details on bcm2835 library)
	
	bcm2835_spi_setBitOrder(BCM2835_SPI_BIT_ORDER_MSBFIRST);	 // Is data shifted in Most Significant Bit (MSB) or Least Significant Bit (LSB) first?
	
	bcm2835_spi_setDataMode(BCM2835_SPI_MODE3);                  // NEED TO ASK WHAT THE SETTINGS OF ARDUINO IS												
	
	bcm2835_spi_setClockDivider(BCM2835_SPI_CLOCK_DIVIDER_64);   // SPI Clock Speed I'M ASSUMING ARDUINO IS 4MHZ CLOCK SPEED (250 / 64 = ~4 MHz)
	
	bcm2835_spi_chipSelect(BCM2835_SPI_CS_NONE);                 // NEED MORE INFORMATION -> Only using 1 device........
	 
	bcm2835_spi_setChipSelectPolarity(BCM2835_SPI_CS_NONE, LOW); // NEED MORE INFORMATION -> Default setup
	
	/*
	
	bcm2835_spi_setBitOrder(BCM2835_SPI_BIT_ORDER_MSBFIRST);      // The default
    bcm2835_spi_setDataMode(BCM2835_SPI_MODE0);                   // The default
    bcm2835_spi_setClockDivider(BCM2835_SPI_CLOCK_DIVIDER_65536); // The default
    bcm2835_spi_chipSelect(BCM2835_SPI_CS0);                      // The default
    bcm2835_spi_setChipSelectPolarity(BCM2835_SPI_CS0, LOW);      // the default
    
    // Send a byte to the slave and simultaneously read a byte back from the slave
    // If you tie MISO to MOSI, you should read back what was sent
    uint8_t send_data = 0x23;
    uint8_t read_data = bcm2835_spi_transfer(send_data);
    
    printf("Sent to SPI: 0x%02X. Read back from SPI: 0x%02X.\n", send_data, read_data);
    if (send_data != read_data)
      printf("Do you have the loopback from MOSI to MISO connected?\n");
    
    */
	
	

}




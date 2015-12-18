#ifndef SPI_H
#define SPI_H

#include <stdio.h>
#include <bcm2835.h>						// C libraries for Raspberry Pi version 1 & 2

typedef struct{
	unsigned int bitOrder;
	unsigned int dataMode;
	unsigned int clockDivider;      // 
	unsigned int chipSelect;		// What pins?
	unsigned int activePolarity;	// Active low or active high?

}TSPISetup;

void printing(void);

/* Initialiases the SPI settings 
 * 
 */
void SPI_Init(void);

#endif

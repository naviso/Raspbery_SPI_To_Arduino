# Variables to use rather than typing the same length 
compiler = gcc
# C compiler option (c = compile)
cflags = -c
# finding libraries
pi = -l bcm2835


all: SPI_Comms

# Listing All object that SPI_Coms need
SPI_Comms: main.o SPI.o
	$(compiler) main.o SPI.o -o SPI_Comms $(pi)

# Listing object dependancies	
main.o: main.c
	$(compiler) $(cflags) main.c
	
SPI.o: SPI.c
	$(compiler) $(cflags) SPI.c
	
# Clean *o removes object files, and inserting exe name removes executable
clean:
	rm rf *o *SPI_Comms


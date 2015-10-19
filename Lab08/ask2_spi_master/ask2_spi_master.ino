#include <avr/io.h>
#include <util/delay.h>

#define SPI_PORT PORTB
#define SPI_DDR  DDRB
#define SPI_CS   PINB2


unsigned char SPI_WriteRead(unsigned char dataout) {

  unsigned char datain;
  
  // start transmiision(MOSI)
  SPDR = dataout;
  
  //wait for transmission complete
  while( !(SPSR & (1<<SPIF) ));
  
  // Get return value;
  datain = SPDR;
  
  // Latch the output using rising pulse to the RCK Pin
  SPI_PORT |= (1<<SPI_CS);
  _delay_us(1); // hold pulse for 1 microsec
  
  // diable latch
  SPI_PORT &= ~(1<<SPI_CS);
  // Return serial in value(MISO)
  
  return datain;

}

void setup() {

  Serial.begin(9600);
  
  //set MOSI and SCK as output, others as input
  SPI_DDR = (1<<DDB3) | (1<<DDB5) | (1<<DDB2);
  
  // Latsch disable(RCK Low)
  SPI_PORT &= ~(1<<SPI_CS);
  
  //Enable SPI Master, set clock rate fck/2 (maximum)
  SPCR = (1<<SPE) | (1<<MSTR) | (1<DORD);
  SPSR = (1<<SPI2X);


}


void loop() {

  // Latch disable(RCK Low)
  SPI_PORT &= ~(1<<SPI_CS);
  
  Serial.println("Starting transmission:");
  SPI_WriteRead('T');
  _delay_ms(1000);

}

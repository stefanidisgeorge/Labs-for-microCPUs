#include <avr/io.h>
#include <util/delay.h>

#define SPI_PORT PORTB
#define SPI_DDR  DDRB
#define SPI_CS   PINB2
unsigned char cnt;

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
  
  // Set MISO output, all others input
  SPI_DDR |= (1<<DDB4);
  //enable SPI, the atmega is in slave mode at startup
  SPCR |= (1<<SPE);
  
  Serial.println("Receiving Transmission:");


}

void loop() {

  cnt = SPI_WriteRead(0);
  Serial.println( cnt );
  _delay_ms(500);


}

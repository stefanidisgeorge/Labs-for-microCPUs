#include "ask2.h"

uint16_t a;

void setup() {
  InitADC();
  aetherphone();
  Serial.begin(9600);
}

void loop() {

  
  //a = ReadADC(3);
  Serial.println(adval);
  

}


uint16_t ReadADC(uint8_t ch) {

  //select ADC channel ch must be 0-7
  ch = ch & 0b00000111;
  ADMUX |= ch;
  
  // start single conversion
  ADCSRA |= ( 1 << ADSC);
  
  // Wait for conversion to complete
  while(! (ADCSRA & (1<<ADIF)));
  
  // clear ADIF by writing one to it
  ADCSRA |= ( 1 << ADIF);
  
  return(ADC);

}

void InitADC() {
  ADMUX = (1 << REFS0);   // for Ared=AVcc
  ADCSRA = (1 << ADEN) | (1<<ADPS2) | (1<<ADPS1) | (1<<ADPS0); // prescalar div factor
}

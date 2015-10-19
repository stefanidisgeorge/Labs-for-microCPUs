/*
automatically subtract 0x20 form I/O addresses
*/
#define __SFR_OFFSET 0

#include <avr/io.h>
#include "ask2.h"
#icnlude <avr/interrupt.h>

.section .data

.global adval
adval: .byte 0x00

.section .text

.global aetherphone
aetherphone:
reset:
  CLR r16          // clear analog input pins with no pull ups (PORTC)
  OUT DDRC, r16    // all pins input
  OUT PORTC, r16   // no pull ups, Tri-State(Hi-Z 10K optimal impedance
  CBI PORTB, 3    // pin 11
  SBI DDRB, 3     // all DDRB
rloop:
  //ldi r16, (1<<ADEN) | (1<<ADSC) | (1<<ADLAR) | (0<<MUX3) | (0<<MUX2) | (0<<MUX1) | (0<<MUX0)
  LDI r16, 0b11000111 // enable start conversion and 
  //set prescaler to 128
  STS ADCSRA, r16
  LDI r16,0b01000011 // select adc in 3 PORTC 3
  STS ADMUX, r16

wait:
  LDS r16, ADCSRA
  ANDI r16, 0b00010000
  BREQ wait
  LDS r16, ADCL    // must read ADCL before ADCH
  LDS r16, ADCH     // Required, though  not used
  STS adval, r16
  RCALL pause
  RCALL sound
  RJMP rloop
ret

sound:
  LDI r20,_BV(3)
  IN r18, PORTB
  EOR r18, r20
  OUT PORTB, r18
ret

pause:
  DEC r16
  BRNE pause
ret

.end

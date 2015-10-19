void setup() {

  // Setup serial
  Serial.begin(9600);
  while( !Serial ) {}
  
  
  // Setup timer/counter 1
  sei();
  
  TCCR1A = 0; // disable all PWM on timer1 whilst we set it up
  ICR1   = 4999; // create frequency of 20ms, with prescale 64, configures next  
  // configure timer  1 with prescaler 64 and mode 14
  TCCR1A = (1 << WGM11);
  TCCR1B = (1 << WGM13) | (1 << WGM12) | (1 << CS10) | (1 << CS11);
  // set PB1 and PB2 as outputs
  DDRB |= _BV(1) | _BV(2);
  
  TCCR1A |= 2 << 6; // enable PWM on port B1 in non-inverted compare mode 2
  TCCR1A |= 2 << 4; // enable PWM on port B2 in non-inverted compare mode 2
  OCR1B = ICR1 * 2/20; // 2ms pulse to right motor on PB2
  
}


void loop() {
  
  OCR1A = 160; // Most right 0 degree
  delay(500);

  OCR1A = 370; // middle 90 degrees
  delay(500);
 
 
  OCR1A = 590; // most left 180 degree
  delay(500);

}

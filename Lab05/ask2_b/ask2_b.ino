volatile long timer; // timer to keep count of the ISR ocurred

void setup() {
  
  
  // SETUP TCTN1
  cli(); // disable global interrupts
  
  TCCR1A = 0; // register set to 0
  TCCR1B = 0; // register set to 0
  TCNT1 = 0;
  OCR1A = 1599;
  TCCR1B |= ( 1 << WGM12 ); // CTC mode
  TCCR1B |= ( 1 << CS10  ); // No prescaler
  TIMSK1 |= ( 1 << OCIE1A); // overflow interrupt mode
  
  sei(); // enable global interrupts
  
  
  // enable serial
  Serial.begin(9600);
  while( !Serial ) {}

}

void loop() {
  // that is exactly once a second polling
  static unsigned long old_millis = 0UL;
  
  if ( millis() - old_millis >= 1000UL ) {
    Serial.println(timer); // print timer value
    timer = 0;
  
    // advance to next event, regardless the time needed by Serial.println()
    old_millis += 1000UL;
  
  }


}


// Compare Interupt handler
ISR(TIMER1_COMPA_vect){
  timer++;
}

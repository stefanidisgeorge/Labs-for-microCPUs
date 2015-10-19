volatile long timer; // timer to keep count of the ISR ocurred
static unsigned long period = 0; // zero-unsigneg-long

void setup() {
  cli(); // disable global interrupts
  
  TCCR1A = 0; // register set to 0
  TCCR1B = 0; // register set to 0
  TCNT1 = 0;
  OCR1A = 15999;
  // TCCR1B |= ( 1 << WGM12); // CTC mode // normal mode
  TCCR1B |= ( 1 << CS10) | (1 << CS12); // prescaler=1024
  TIMSK1 |= ( 1 << TOIE1); // overflow interrupt mode
  
  sei(); // enable global interrupts
  
  Serial.begin(9600);

}

ISR(TIMER1_OVF_vect){
  timer++;

}

void loop() {
  // that is exactly once a second polling
  period += micros();

  if( timer == 1 ) {
    timer = 0;
    unsigned long pp=period;
    period=micros()-pp;
    Serial.println(period/(1000.0*1000.0) );
    period=0;
  }

}

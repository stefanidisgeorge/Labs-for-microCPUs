// assign pin vlaues here
const char sda_pin = 2;
const char scl_pin = 7;

//sampling window
const int data_size = 1250;

//array to contain sampled data
byte captured_data[data_size];

// housekeeping booleans
boolean captured;
boolean dumped;

void setup() {

  Serial.begin(9600);
  
  pinMode(sda_pin, INPUT);
  pinMode(scl_pin, INPUT);
  
  captured = false;
  dumped = false;

  Serial.println("Good to go, chief!");

}

void loop() {
  
  while( digitalRead(sda_pin) == HIGH){}
  capture();
  if( captured == true && dumped==false ) {
    serial_dump();
    dumped = true;
  }

}

void capture( void ) {
  
  byte tempdata;
  for( int x=0; x<data_size; x++ ) {
    tempdata = PIND;
    captured_data[x] = tempdata;
  }
  captured =true;

}

void serial_dump() {

  byte temp;
  Serial.println("Sample, sda, sck");
  
  for( int x=0; x<data_size; x++) {
    
    if(x<10 ) { Serial.print("0"); }
    if(x<100) { Serial.print("0"); }

    Serial.print(x);
    Serial.print(",  ");

    temp = bitRead( captured_data[x], sda_pin);
    if( temp == 0) { Serial.print(0); }
    else           { Serial.print(1); }
    Serial.print(",   ");
    
    temp = bitRead( captured_data[x], scl_pin);
    if( temp == 0) { Serial.println(0); }
    else           { Serial.println(1); }
  
  }

}

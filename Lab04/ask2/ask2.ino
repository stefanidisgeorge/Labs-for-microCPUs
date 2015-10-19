#include "ask2.h"


void setup() {
  Serial.begin(9600);
  
  // wait for serial
  while( !Serial ) { }

  // give prompt
  Serial.print("IN char=");

}

void loop() {

  // wait for value
  if (Serial.available() > 0) {

    // read input value
    in_char=Serial.read();
    Serial.println(in_char);

    // process the value now
    next_char();
  
    Serial.print("OUT char=");
    Serial.println(out_char);
    Serial.println();

    // and prompt again
    Serial.print("IN char=");

  }
  

}

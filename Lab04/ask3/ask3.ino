#include "ask3.h"


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
    s1=Serial.read();
    Serial.println(s1);

    // process the value now
    stack_add();
  
    Serial.print("OUT char=");
    Serial.println(s1);
    Serial.println();

    // and prompt again
    Serial.print("IN char=");

  }

}

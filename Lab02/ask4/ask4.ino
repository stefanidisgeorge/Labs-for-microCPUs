#include "ask4.h"



void setup() {
  
    Serial.begin(9600);
    while( !Serial ) {}
 
}


void loop() {
  
  start_time = millis();
  
  my_delay();
  
  end_time = millis();


  Serial.print("Delay was: ");
  Serial.print(end_time - start_time);
  Serial.println(" ms");
}

#include "ask1.h"

void setup() {

  Serial.begin(115200);
  while( !Serial ) { }

}

int dir = 1;

void loop() {

  if(dir==1) {
    cup();
    Serial.println(counter,HEX);
    if(counter==4500) { dir=0; }
    delay(10);
  }
  else {
    cdown();
    Serial.println(counter,HEX);
    if(counter==0) { dir=1; }
    delay(10);
  }


}

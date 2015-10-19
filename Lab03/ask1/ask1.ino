#include "ask1.h"

void setup() {

  Serial.begin(9600);
  while( !Serial ) { }

}


void loop() {

  read8();
  delay(1000);


}

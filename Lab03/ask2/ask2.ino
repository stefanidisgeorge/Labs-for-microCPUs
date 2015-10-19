#include "ask2.h"

void setup() {

  Serial.begin(9600);
  while(!Serial) {}  

  Serial.setTimeout(5000);

}

void loop() {

  Serial.print("n1=");
  n1=Serial.parseInt();
  Serial.println(n1);

  Serial.print("n2=");
  n2=Serial.parseInt();
  Serial.println(n2);
  
  make_add();
  
  Serial.print("RES=");
  Serial.println(res);


}

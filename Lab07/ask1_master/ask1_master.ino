#include <Wire.h>

int x=0;

void setup() {

  Wire.begin(); // join i2c bus

}


void loop() {

  // Wire.write(x); // send one byte
  Wire.beginTransmission(4);
  Wire.write("x is "); // sends five bytes
  Wire.write(x);       // send one byte
  Wire.endTransmission();
  
  x++;
  delay(500);

}

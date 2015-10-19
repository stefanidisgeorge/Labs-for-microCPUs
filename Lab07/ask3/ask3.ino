#include <Wire.h>
#include "Adafruit_SI1145.h"

#define addr 0x60
#define reg  0x22

uint16_t ret;
Adafruit_SI1145 x;

void setup(){
  
 x.begin();
 Wire.begin();
 Serial.begin(9600);
  
}

void loop(){
 
  Wire.beginTransmission(addr);
  Wire.write(reg);
  Wire.endTransmission(); 
  
  Wire.requestFrom(addr,2);
  
  ret = Wire.read();
  ret = (uint16_t)Wire.read()<<8;
  Serial.println(ret,HEX);

  delay(2000);

}

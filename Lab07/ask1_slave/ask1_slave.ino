#include <Wire.h>

int x=0;
void setup()
{

  Wire.begin(4);
  Wire.onReceive(receiveEvent);
  Serial.begin(9600);

}

void loop(){
 
  delay(100); 
  
}

void receiveEvent(int howMany){
  
  while(Wire.available()) {
    char c= Wire.read();
    Serial.print(c);
  } 
  Serial.println(" ");  
}

#include "ask3_spi_master.h"

void setup() {

  Serial.begin(9600);
  while( !Serial ) {}
    spi_init();
    Serial.println("Master Start");
    delay(1000);

}

void loop() {

  Serial.println("Sending data");
  spi_send();
  delay(2000);
  
}

#include "ask3.h"

void setup() {
  
    Serial.begin(9600);
    while( !Serial ) {}
  
    uint8_t *t=p;  // make a pointer to first element of table

    table_init(); // init the table with assembly

    for ( int i=0; i<10; i++) {
        Serial.print(*t);
        Serial.print(" ");
        Serial.println(p[i]);
        t++;
    }

}


void loop() {



}

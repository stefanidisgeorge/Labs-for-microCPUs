#include "ask4.h"

// vars that specifies the prompt message
bool prompted = false;
int i = 0;

// var that checks when args was given
bool args_done = false;


void setup() {
  Serial.begin(9600);
  
  // wait for serial
  while( !Serial ) { }

}

void loop() {
  
  /*
  ** ----------------------------------
  ** Give the prompt for arguments
  ** ----------------------------------
  */
  if( (prompted == false) && ( i <= 2 ) ) {
    if(i == 0) {
      Serial.print("Give a: ");
      prompted = true;
    }
    else if(i == 1) {
      Serial.print("Give x: ");
      prompted = true;
    }
    else if(i == 2) {
      Serial.print("Give b: ");
      prompted = true;
    }
  }
  
  
  /*
  ** ----------------------------------
  ** now  wait for something in Serial
  ** and when, take the arguments
  ** ----------------------------------
  */
  if( (Serial.available() > 0) && (i<=2) ) {
    
    // read input value
    args[i] = Serial.parseInt();
    Serial.println( args[i] );
    
    // next argument
    i = i + 1;
    prompted = false;
    
    if( i == 3 ) {
      // all arguments given go compute
      args_done = true;
    }

  }
  
  /*
  ** ----------------------------------
  ** when all arguments given compute
  ** ----------------------------------
  */
  if( args_done == true ) {
    // call compute function
    Serial.println("Compute now!!!");
    f_compute();
    
    // display results
    Serial.println("Results!!!");
    Serial.print("Res = ");
    Serial.println(res);
    
    
    
    // and back to start again
    Serial.println("From start again!!!");
    i = 0;
    prompted = false;
    args_done = false;
    
    Serial.println();
  
  
  }
  
  
}

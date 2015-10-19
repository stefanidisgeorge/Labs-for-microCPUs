/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 */
 
// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int led_RED    = 13;
int led_GREEN  = 12;
int led_YELLOW = 11;

int change1    = 2000;
int change2    = 3500;
int change3    = 2909;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(led_RED, OUTPUT);
  pinMode(led_GREEN, OUTPUT);
  pinMode(led_YELLOW, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  
  
  digitalWrite(led_RED, HIGH);   // turn the LED on (HIGH is the voltage level)

  delay(change1);              
  digitalWrite(led_RED, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(led_GREEN, HIGH);   // turn the LED on (HIGH is the voltage level)

  delay(change2);
  digitalWrite(led_GREEN, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(led_YELLOW, HIGH);   // turn the LED on (HIGH is the voltage level)
  
  delay(change3);
  digitalWrite(led_YELLOW, LOW);   // turn the LED on (HIGH is the voltage level)


}

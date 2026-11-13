#include <Arduino.h>

#define PIN 48 // use pin 48 for on board RGB
void setup(){
  Serial.begin(115200);
}

void loop(){
  Serial.println("WHAT!!!!!!");
  // neopixelWrite uses unsigned 8-bit range 0-255
  // so [255, 255, 255] is white 
  neopixelWrite(PIN, 0, 0, 32); // blue
  delay(500);
  neopixelWrite(PIN, 0, 32, 0); // green
  delay(500);
  neopixelWrite(PIN, 32, 0, 0); // red 
  delay(500);
}

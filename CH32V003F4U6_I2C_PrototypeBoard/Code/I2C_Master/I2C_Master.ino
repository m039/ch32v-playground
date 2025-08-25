#include <Wire.h>

#define BUTTON 2 // D2

uint8_t bState;
uint8_t lState;

const byte SLAVE_ADDRESS = 0x09;
const byte REGISTER_ADDRESS = 0x00;

void setup() {
  Wire.begin();  

  pinMode(BUTTON, INPUT_PULLUP);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  uint8_t b = digitalRead(BUTTON);
  if (b != bState) {
    bState = b;
    if (b == LOW) {
      lState = lState == HIGH ? LOW : HIGH;
      digitalWrite(LED_BUILTIN, lState);

      Wire.beginTransmission(SLAVE_ADDRESS);
      Wire.write(REGISTER_ADDRESS);
      Wire.write(lState);
      Wire.endTransmission(); 
    }
  }
}

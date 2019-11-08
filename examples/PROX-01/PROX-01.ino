#include "PCA9534.h"

/*
   Pin 1: Power
   Pin 2: I²C Data
   Pin 3: Ground
   Pin 4: I²C Clock
*/
#define GPIO0_VIN   0
#define GPIO1_VO    1

PCA9534 gpio;
// P0 is connected to VIN
// P1 is connected to VO
// Go high on VIN, then read on VO


void setup() {
  // Pin, Mode
  // Pins 0, 1, 2, 3, 4, 5, 6, 7
  // Modes are Input, Inverted, or Output
  gpio.begin();
  gpio.pinMode(GPIO0_VIN, OUTPUT);
  gpio.pinMode(GPIO1_VO, INPUT);
  gpio.digitalWrite(GPIO0_VIN, HIGH);
  Serial.begin(9600);
}

void loop() {
  Serial.print("Value: ");
  Serial.println(getIR());
  delay(1000);
}

uint8_t getIR() {
  return gpio.digitalRead(GPIO1_VO);
}

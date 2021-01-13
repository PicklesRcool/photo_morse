#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "config.h"
#include "sensor_reader.h"


SensorReader sensor_reader(kLedPin);

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(kLedPin, OUTPUT);
  pinMode(kSensorPin, INPUT);
  analogReference(0);
  
  Serial.begin(kSerialDataRate);
  Serial.print("\n\nSerial output initialized. Data rate: ");
  Serial.println(kSerialDataRate);
}

unsigned long click_start  = 0;
unsigned long last_pressed = 0;

bool clicking = false;

void loop() {
#if 1  // For stopping program execution

  int sensor_read = analogRead(kSensorPin);
  sensor_reader.ProcessValue(sensor_read);

  if (sensor_reader.GetReadOver()) {
    Serial.print(sensor_reader.GetReadSymbol());
    Serial.print(" - ");
    Serial.println(sensor_reader.GetDuration());
  }

  delay(kLoopDelay);
#endif
}

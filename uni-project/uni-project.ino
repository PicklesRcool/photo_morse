#include "config.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

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
  int light_perc  = round(sensor_read / 1023.0 * 100);
  bool key_pressed = light_perc <= kLightSensorThreshold;
  
  if (key_pressed) {
    digitalWrite(kLedPin, HIGH);

    last_pressed = millis();

    if (!clicking) {
      clicking = true;
      click_start = millis();
    }
  }

  if (!key_pressed) {
    digitalWrite(kLedPin, LOW);
  }

  if (((millis() - last_pressed) > kWaitForPressInterval) && clicking) {
    clicking = false;

    int click_dur = millis() - click_start;
    if (click_dur < kDotDashBorder)
      Serial.print(".");
    else
      Serial.print("-");
  }

  delay(kLoopDelay);
#endif
}

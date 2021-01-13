#include "config.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


const int kLedPin = 3;
const int kSensorPin = 0;

char temp_str[1000] = { 0 };  // For output formatting


void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(kLedPin, OUTPUT);
  pinMode(kSensorPin, INPUT);
  analogReference(INTERNAL4V3);
  
  Serial.begin(9600);
  Serial.println("\n\nSerial output initialized.");
}

int click_start = 0;

int last_pressed = 0;
bool clicking = false;

int press_counter = 1;

void loop() {
#if 1  // For stopping program execution
  int sensor_read = analogRead(kSensorPin);
  int light_perc = round(sensor_read / 1023.0 * 100);
  bool key_pressed = light_perc <= kLightSensorThreshold;
  
  if (((millis() - last_pressed) > kWaitForPressInterval) && key_pressed) {
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

#endif
}

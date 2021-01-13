#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "config.h"
#include "sensor_reader.h"
#include "morse_symbols.h"
#include "led_utils.h"

SensorReader sensor_reader(kLedPin);

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(kLedPin, OUTPUT);
  pinMode(kRedLedPin_1, OUTPUT);
  pinMode(kRedLedPin_2, OUTPUT);

  pinMode(kSensorPin, INPUT);
  analogReference(0);
  
  Serial.begin(kSerialDataRate);
  Serial.print("\n\nSerial output initialized. Data rate: ");
  Serial.println(kSerialDataRate);

  srand(time(NULL));
}

void loop() {
#if 1  // For stopping program execution
  unsigned long input_start = millis();
  bool input_active = false;

  char rand_char = char(rand() % 25 + 97);  // TODO: Remove magic numbers
  char dot_dash_str[10] = { 0 };

  Serial.print("Write the letter: ");
  Serial.println(rand_char);

  while(!(millis() - input_start > kNewWordThreshhold && input_active)) {
    int sensor_read = analogRead(kSensorPin);
    sensor_reader.ProcessValue(sensor_read);

    if (sensor_reader.GetReadOver()) {
      char read_symbol = sensor_reader.GetReadSymbol();

      Serial.print(read_symbol);
      strncat(dot_dash_str, &read_symbol, 1); 

      input_active = true;
      input_start = millis();
    }

    delay(kLoopDelay);
  }
  Serial.println();
  
  if (strcmp(dot_dash_str, CharToMorse(rand_char)) == 0) {
    Serial.println("Nice! :D\n");
    LED_DoubleBlink_Parallel(kRedLedPin_1, kRedLedPin_2, 200, 1000);
  }
  else {
    Serial.println("Try again! :(\n");
    LED_DoubleBlink_Split(kRedLedPin_1, kRedLedPin_2, 200, 1000);
  }

#endif
}

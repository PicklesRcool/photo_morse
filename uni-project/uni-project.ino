#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "config.h"
#include "sensor_reader.h"
#include "morse_symbols.h"
#include "led_utils.h"
#include "morse_letter_game.h"

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
  
  LED_DoubleBlink_Parallel(kRedLedPin_1, kRedLedPin_2, 200, 1000);
}

void loop() {
#if 1  // For stopping program execution

  MorseLetterGame letter_game(sensor_reader);

  letter_game.Exec();

#endif
}
